const BubbleSort = require('./bubbleSort');
const InsertionSort = require('./insertionSort');
const QuickSort = require('./quickSort');

class SortingContext {
    sort(data) {
        let size = data.length;
        let strategy = this.setSortStrategy(size);
        return strategy.sort(data);
    }

    setSortStrategy(size) {
        if (size >= 2 && size <= 5) {
            return new BubbleSort();
        } else if (size >= 6 && size <= 10) {
            return new InsertionSort();
        } else {
            return new QuickSort();
        }
    }
}

module.exports = SortingContext;
