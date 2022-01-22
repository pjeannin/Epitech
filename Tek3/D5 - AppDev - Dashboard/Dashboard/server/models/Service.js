const mongoose = require('mongoose')

const serviceSchema = new mongoose.Schema({
    name: {
        type: String,
        required: true,
    },
    widgets: [{
        name: {
            type: String,
            required: true,
        },
        description: {
            type: String,
            required: true,
        },
        params: [{
            name: {
                type: String,
                required: true,
            },
            type: {
                type: String,
                required: true,
            },
        }]
    }]
})

module.exports = mongoose.model('Service', serviceSchema);