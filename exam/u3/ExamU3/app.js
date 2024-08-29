const express = require('express');
const mongoose = require('mongoose');
const path = require('path');
const SortingContext = require('./strategies/sortingContext');

const app = express();
const port = 3007;

app.use(express.json());
app.use(express.static(__dirname)); 
mongoose.connect('mongodb+srv://kachiriboga:chiriboga@cluster0.mstbyy5.mongodb.net/strategyChiriboga?retryWrites=true&w=majority', { useNewUrlParser: true, useUnifiedTopology: true });

const arraySchema = new mongoose.Schema({
    unsorted: String,
    size: Number,
    sortAlgorithm: String,
    sorted: String
});

const ArrayModel = mongoose.model('arrayKerlly', arraySchema);

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html'));
});

app.post('/sort', async (req, res) => {
    const numbers = req.body.numbers;

    const unsortedNumbers = [...numbers];
    
    const sortingContext = new SortingContext();
    const sortAlgorithmInstance = sortingContext.setSortStrategy(numbers.length); 
    const sortAlgorithm = sortAlgorithmInstance.constructor.name; 
    const sortedNumbers = sortAlgorithmInstance.sort(numbers);

    const newArray = new ArrayModel({
        unsorted: unsortedNumbers.join(', '),
        size: numbers.length,
        sortAlgorithm: sortAlgorithm, 
        sorted: sortedNumbers.join(', ') 
    });

    await newArray.save();

    res.json({ sortedNumbers, sortAlgorithm });
});


app.listen(port, () => {
    console.log(`Servidor escuchando en http://localhost:${port}`);
});
