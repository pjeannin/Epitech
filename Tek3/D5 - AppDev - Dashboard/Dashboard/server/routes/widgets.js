const router = require('express').Router();
const Widget = require('../models/Widget');
const Service = require('../models/Service');
const verify = require('../middleware/verifyToken');

router.post('/create', verify, async (req, res) => {
    const widget = new Widget({
        user: req.body.user,
        serviceName: req.body.serviceName,
        index: req.body.index,
        widgetData: {
            name: req.body.widgetData.name,
            params: req.body.widgetData.params
        }
    });
    try {
        const savedWidget = await widget.save();
        res.status(200).send({ Status: `Widget ${savedWidget.widgetData.name} saved` });
    } catch (err) {
        res.status(400).send(err);
    }
})

router.get('/get', verify, async (req, res) => {
    const widgets = await Widget.find({user: req.query.user})
    if (!widgets) return res.status(400).send({Status: "Widget not found"});

    try {
        res.send(widgets);
    } catch (err) {
        res.status(400).send(err);
    }
})

router.post('/createService', verify, async (req, res) => {
    const serviceGet = await Service.findOne({name: req.body.name})
    if (serviceGet) return res.status(400).send({Status: `${serviceGet.name} already exist`})

    const service = new Service({
        name: req.body.name,
        widgets: {
            name: req.body.widgets.name,
            description: req.body.widgets.description,
            params: req.body.widgets.params
        }
    });
    try {
        const savedService = await service.save();
        res.status(200).send({ Status: `New service ${savedService.name} created` });
    } catch (err) {
        res.status(400).send(err);
    }
})

router.post('/addWidgetService', verify, async (req, res) => {
    const serviceGet = await Service.findOne({serviceName: req.body.name})
    if (!serviceGet) return res.status(400).send({Status: `Service not found`})
    let newWidget = serviceGet.widgets;
    
    newWidget.push(
        {
            name: req.body.name,
            description: req.body.description,
            params: req.body.params
        }
    )
    try {
        await Service.updateOne({name: req.body.name}, {
            widgets: newWidget
        })
        res.status(200).send({Status: "New widget created"})
    } catch (err) {
        res.status(400).send(err)
    }
})

router.patch('/updateWidget', verify, async (req, res) => {
    try {
        await Widget.findByIdAndUpdate(req.query.id, req.body.widget)
        res.status(200).send({Status: `Widget ${req.query.id} updated`})
    } catch (err) {
        res.status(400).send(err)
    }
})

router.delete('/deleteWidget', verify, async (req, res) => {
    const widgetRes = await Widget.findById(req.query.id)
    if (!widgetRes) return res.status(400).send({Status: `Widget not found`})

    widgetRes.remove(() => {
        res.status(200).send({Status: `Widget ${req.query.id} deleted`})
    });
})

module.exports = router;