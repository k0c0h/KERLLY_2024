const mongoose = require('mongoose');

const reservationSchema = new mongoose.Schema({
  customerName: String,
  customerEmail: String,
  flightOrigin: String,
  flightDestination: String,
  pricePerPerson: Number,
  numberOfPeople: Number,
  totalPrice: Number
});

module.exports = mongoose.model('Reservation', reservationSchema);
