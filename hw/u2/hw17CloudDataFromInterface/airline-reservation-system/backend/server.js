const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const reservationRoutes = require('./routes/reservation');
const path = require('path');

const app = express();
const PORT = process.env.PORT || 3000;

const mongoUri = 'mongodb+srv://kachiriboga:chiriboga@cluster0.mstbyy5.mongodb.net/hw17?retryWrites=true&w=majority';

// Conexión a MongoDB
mongoose.connect(mongoUri)
  .then(() => {
    console.log('Connected to MongoDB');
  })
  .catch(err => {
    console.error('Error connecting to MongoDB', err);
  });

app.use(bodyParser.json());
app.use('/api/reservations', reservationRoutes);

app.use(express.static(path.join(__dirname, 'public')));
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
