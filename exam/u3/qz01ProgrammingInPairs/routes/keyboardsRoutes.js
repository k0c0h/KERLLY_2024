const express = require('express');
const Keyboard = require('../models/Keyboards');
const router = express.Router();

router.get('/keyboards', async (req, res) => {
    try {
        const keyboards = await Keyboard.find();
        res.json(keyboards);
    } catch (err) {
        res.status(500).json({ message: err.message });
    }
});

router.get('/keyboard/:id', async (req, res) => {
    try {
        const keyboard = await Keyboard.findOne({ id: req.params.id });
        if (keyboard == null) {
            res.status(404).json({ message: 'Keyboard not found' });
        } else {
            res.json(keyboard);
        }
    } catch (error) {
        res.status(500).json({ message: error.message });
    }
});

router.post('/keyboard', async (req, res) => {
    const keyboard = new Keyboard({
        id: req.body.id,
        name: req.body.name,
        price: req.body.price,
        weight: req.body.weight,
        amount: req.body.amount,
        totalPrice: req.body.price * req.body.amount,
        approximatedWeight: req.body.weight * req.body.amount
    });

    try {
        const newKeyboard = await keyboard.save();
        res.status(200).json(newKeyboard);
    } catch (error) {
        res.status(500).json({ message: error.message });
    }
});

module.exports = router;
