const express = require('express');
const router = express.Router();
const Reservation = require('../models/Reservation');

router.post('/add', async (req, res) => {
  const { customerName, customerEmail, flightOrigin, flightDestination, pricePerPerson, numberOfPeople, totalPrice } = req.body;

  const newReservation = new Reservation({
    customerName,
    customerEmail,
    flightOrigin,
    flightDestination,
    pricePerPerson,
    numberOfPeople,
    totalPrice
  });

  try {
    await newReservation.save();
    res.status(201).json(newReservation);
  } catch (error) {
    res.status(500).json({ error: 'Error saving reservation' });
  }
});

module.exports = router;
