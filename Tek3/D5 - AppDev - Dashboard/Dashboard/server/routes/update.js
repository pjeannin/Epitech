const router = require('express').Router();
const verify = require('../middleware/verifyToken');
const axios = require('axios').default;
const User = require('../models/User');

// Weather Service

router.get('/Weather/ForecastWeather', verify, async(req, res) => {
    let request = JSON.parse(req.query.params);
    await axios.get("https://api.weatherapi.com/v1/forecast.json", {
        params: {
            key: process.env.APIKEYWEATHER,
            q: request.q,
            alerts: request.alerts,
            aqi: request.aqi,
            days: request.days
        }
    }).then(r => {
        res.status(200).send(r.data)
    })
    .catch(err => {
        res.status(400).send(err)
    })
})

router.get('/Weather/CurrentWeather', verify, async(req, res) => {
    let request = JSON.parse(req.query.params);
    await axios.get("https://api.weatherapi.com/v1/current.json", {
        params: {
            key: process.env.APIKEYWEATHER,
            q: request.q,
            aqi: request.aqi
        }
    }).then(r => {
        res.status(200).send(r.data)
    })
    .catch(err => {
        res.status(400).send(err)
    })
})

router.get('/Weather/AirQuality', verify, async(req, res) => {
    let request = JSON.parse(req.query.params);
    await axios.get("https://api.weatherapi.com/v1/current.json", {
        params: {
            key: process.env.APIKEYWEATHER,
            q: request.q,
            aqi: request.aqi
        }
    }).then(r => {
        res.status(200).send(r.data)
    })
    .catch(err => {
        res.status(400).send(err)
    })
})

// Github Service

router.get('/Github/UserInfos', verify, async(req, res) => {
    let request = JSON.parse(req.query.params);
    await axios.get(`https://api.github.com/users/${request.username}`)
        .then(r => {
            res.status(200).send(r.data);
        })
        .catch(err => {
            res.status(400).send(err);
        })
})

router.get('/Github/UserRepos', verify, async(req, res) => {
    let request = JSON.parse(req.query.params);
    await axios.get(`https://api.github.com/users/${request.username}/repos`)
        .then(r => {
            res.status(200).send(r.data);
        })
        .catch(err => {
            res.status(400).send(err);
        })
})

// Youtube Service

router.get('/Youtube/ChannelInfos', verify, async(req, res) => {
    let request = JSON.parse(req.query.params);
    axios.get("https://youtube.googleapis.com/youtube/v3/search", {
        params: {
            part: "snippet",
            q: request.q,
            key: process.env.APIKEYYOUTUBE
        }
    }).then(r => {
        axios.get("https://youtube.googleapis.com/youtube/v3/channels", {
            params: {
                part: "snippet,statistics",
                id: r.data.items[0].snippet.channelId,
                key: process.env.APIKEYYOUTUBE
            }
        }).then(response => {
            res.status(200).send(response.data);
        }).catch(err => {
            res.status(400).send(err);
        })
    }).catch(err => {
        res.status(400).send(err);
    })
})

// Twitter Service

router.get('/Twitter/UserInfos', verify, async(req, res) => {
    let request = JSON.parse(req.query.params);

})

// Pornhub Service

router.get('/Pornhub/VideoInfos', verify, async(req, res) => {
    let request = JSON.parse(req.query.params);

    axios.get('http://www.pornhub.com/webmasters/video_by_id', {
        params: {
            id: request.id
        }
    }).then(r => {
        res.status(200).send(r.data);
    }).catch(err => {
        res.status(400).send(err);
    })
})

router.get('/Pornhub/TopVideos', verify, async(req, res) => {
    axios.get('http://www.pornhub.com/webmasters/search')
        .then(r => {
            res.status(200).send(r.data);
        }).catch(err => {
            res.status(400).send(err);
        })
})

router.get('/Reddit/messages', verify, async(req, res) => {
    let request = JSON.parse(req.query.params);
    let user = await User.findOne({
        username: request.username
    });
    console.log(user);
    console.log(request);
    if (request.type !== 'inbox' && request.type !== 'sent' && request.type !== 'unread')
        return res.status(401).send('Type must be inbox, sent or unread');
    axios.get(`https://oauth.reddit.com/message/${request.type}`, {
        headers: {
            Authorization: `Bearer ${user.redditToken}`
        },
        params: {
            limit: 10,
            raw_json: 1
        }
    }).then(response => {
        console.log(response.data);
        res.status(200).send(response.data);
    }).catch(err => {
        console.log(err);
        res.status(400).send(err);
    })
})

module.exports = router;