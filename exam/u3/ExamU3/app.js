const express = require('express');
const mongoose = require('mongoose');
const SortingContext = require('./strategies/sortingContext');

const app = express();
const port = 3000;

app.set('view engine', 'ejs');
app.use(express.static('public'));
app.use(express.urlencoded({ extended: true }));

mongoose.connect('mongodb+srv://kachiriboga:chiriboga@cluster0.mstbyy5.mongodb.net/hw17?retryWrites=true&w=majority', { useNewUrlParser: true, useUnifiedTopology: true });

const arraySchema = new mongoose.Schema({
    unsorted: String,
    size: Number,
    sortAlgorithm: String,
    sorted: String
});

const ArrayModel = mongoose.model('ArrayFirstName', arraySchema);

app.get('/', (req, res) => {
    res.render('index');
});

app.post('/sort', async (req, res) => {
    const numbers = req.body.numbers.split(',').map(Number);
    const sortingContext = new SortingContext();
    const sortedNumbers = sortingContext.sort(numbers);

    const sortAlgorithm = sortingContext.setSortStrategy(numbers.length).constructor.name;

    const newArray = new ArrayModel({
        unsorted: numbers.join(', '),
        size: numbers.length,
        sortAlgorithm: sortAlgorithm,
        sorted: sortedNumbers.join(', ')
    });

    await newArray.save();

    res.render('index', {
        sortedNumbers: sortedNumbers.join(', '),
        sortAlgorithm: sortAlgorithm
    });
});

app.listen(port, () => {
    console.log(`Servidor escuchando en http://localhost:${port}`);
});
