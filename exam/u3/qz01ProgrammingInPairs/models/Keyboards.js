const mongoose = require('mongoose');

const keyboardSchema = new mongoose.Schema({
    id: { type: Number, required: true, unique: true },
    name: { type: String, required: true },
    price: { type: Number, required: true },
    weight: { type: Number, required: true },
    amount: { type: Number, required: true },
    totalPrice: { type: Number, required: true },
    approximatedWeight: { type: Number, required: true }
});

module.exports = mongoose.model('Keyboard', keyboardSchema);

