const express = require('express')
const mongoose = require('mongoose')
const app = express()
const cors = require('cors')

// Import Routes
const authRoute = require('./routes/auth')
const widgetsRoute = require('./routes/widgets')
const aboutRoute = require('./routes/about')
const updateRoute = require('./routes/update')

// Init schema

const Service = require('./models/Service')

// Init widgets json files

const initYoutube = require('./json/initYoutube.json');
const initGithub = require('./json/initGithub.json');
const initWeather = require('./json/initWeather.json');
const initPornhub = require('./json/initPornhub.json');
const initReddit = require('./json/initReddit.json');

mongoose.connect(process.env.MONGOURL,
    { useNewUrlParser: true },
    () => console.log('Connected to DB !')
);

// Middleware
app.use(express.json());
app.use(cors());

// Routes Middleware
app.use('/api/user', authRoute)
app.use('/api/widgets', widgetsRoute)
app.use('/about.json', aboutRoute)
app.use('/api/update', updateRoute)

app.listen(process.env.PORT, async () => {
    let youtubeService = await Service.findOne({name: initYoutube.name})
    let githubService = await Service.findOne({name: initGithub.name})
    let weatherService = await Service.findOne({name: initWeather.name})
    let pornhubService = await Service.findOne({name: initPornhub.name})
    let redditService = await Service.findOne({name: initReddit.name})

    if (!youtubeService) {
        youtubeService = new Service(initYoutube);
        await youtubeService.save();
        console.log('Init youtube widget in database')
    }
    if (!githubService) {
        githubService = new Service(initGithub);
        await githubService.save();
        console.log('Init github widget in database')
    }
    if (!weatherService) {
        weatherService = new Service(initWeather);
        await weatherService.save();
        console.log('Init weather widget in database')
    }
    if (!pornhubService) {
        pornhubService = new Service(initPornhub);
        await pornhubService.save();
        console.log('Init pornhub widget in database')
    }
    if (!redditService) {
        redditService = new Service(initReddit);
        await redditService.save();
        console.log('Init reddit widget in database')
    }
    console.log(`Backend running at http://localhost:${process.env.PORT}`)
})
