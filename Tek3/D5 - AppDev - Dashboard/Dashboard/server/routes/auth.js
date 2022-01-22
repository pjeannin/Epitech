const router = require('express').Router();
const User = require('../models/User');
const { registerValidation, loginValidation } = require('../validation');
const jwt = require('jsonwebtoken');
const bcrypt = require('bcrypt');
const { default: axios } = require('axios');
const queryString = require('query-string');

router.post('/register', async (req, res) => {
    const { error } = registerValidation(req.body);
    if (error) return res.status(400).send(error.details[0].message);

    const emailExist = await User.findOne({email: req.body.email});
    if (emailExist) return res.status(400).send('Email already exists');

    const usernameExist = await User.findOne({username: req.body.username});
    if (usernameExist) return res.status(400).send('Username already exists');

    const salt = await bcrypt.genSalt(10);
    const hashedPassword = await bcrypt.hash(req.body.password, salt);

    const user = new User({
        username: req.body.username,
        email: req.body.email,
        password: hashedPassword
    });
    try {
        const savedUser = await user.save();
        res.status(200).send({ Status: `User ${user.username} succesfully created` });
    } catch (err) {
        res.status(400).send(err);
    }
});

router.post('/login', async (req, res) => {
    const { error } = loginValidation(req.body);
    if (error) return res.status(400).send(error.details[0].message);

    const user = await User.findOne({email: req.body.email});
    if (!user) return res.status(400).send('Email not found');

    const validPass = await bcrypt.compare(req.body.password, user.password);
    if (!validPass) return res.status(400).send('Invalid password');

    const token = jwt.sign({_id: user._id}, process.env.TOKENSECRET);

    let isReddit = false;

    if (user.redditToken !== 'none') {
        isReddit = true;
    }

    res.status(200).header('auth_token', token).send({
        Status: "Login Success",
        Username: user.username,
        RedditLogin: isReddit,
        Token: token
    })
})

router.patch('/changePassword', async (req, res) => {
    const salt = await bcrypt.genSalt(10);

    try {
        await User.findOneAndUpdate({username: req.query.username}, {password: bcrypt.hash(req.body.password, salt)})
        res.status(200).send({Status: `Password updated`})
    } catch (err) {
        res.status(400).send(err)
    }
})

router.post("/redditToken", async (req, res) => {
    const creds = btoa(`${process.env.APPIDREDDIT}:${req.body.code}`);
    axios.post("https://www.reddit.com/api/v1/access_token",{},{
        headers: {
            Authorization: `Basic ${creds}`
        },
        params: {
            grant_type: 'authorization_code',
            code: req.body.code,
            redirect_uri: process.env.REDIRECTURIREDDIT
        }
    }).then(async (response) => {
        try {
            await User.findOneAndUpdate({username: req.body.username}, {redditToken: response.data.access_token});
            res.status(200).send({Status: `Reddit token updated`});
        } catch (err) {
            res.status(400).send(err)
        }
        res.status(200).send();
    }).catch(err => {
        res.status(400).send(err);
    })
})

router.get('/redditOauth', async (req, res) => {
    res.status(200).send({authUrl: "https://www.reddit.com/api/v1/authorize?client_id=W752HSGWq0KX0H-1IzBGqw&response_type=code&state=achetez_des_AirPods&redirect_uri=http://localhost:3000/auth/redditURI&duration=permanent&scope=*"})
})

module.exports = router;