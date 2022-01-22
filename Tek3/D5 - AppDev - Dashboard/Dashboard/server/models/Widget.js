const mongoose = require('mongoose')

const widgetSchema = new mongoose.Schema({
    user: {
        type: String,
        required: true,
    },
    serviceName: {
        type: String,
        required: true,
    },
    index: {
        type: Number,
        required: true,
    },
    widgetData: {
        name: {
            type: String,
            required: true,
        },
        params: [{
            name: {
                type: String,
                required: true,
            },
            data: {
                type: String,
                required: true
            }
        }]
    }
})

module.exports = mongoose.model('Widget', widgetSchema);