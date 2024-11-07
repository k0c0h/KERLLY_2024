
const BasicOperation = require('../controllers/BasicOperation');
const PersonController = require('../controllers/PersonController');

console.log("Basic Operations! \nKerlly Chiriboga, OOP 14539");
console.log("---> Unit Testing in action <---");

let addend1;
let addend2;
let sum;

addend1 = 1.2;
addend2 = 2.4;
sum = addend1 + addend2;
console.log(`The sum of ${addend1} + ${addend2} --> ${sum}`);

addend1 = 1.8;
addend2 = -2.2;
sum = BasicOperation.addTwoNumbers(addend1, addend2);
console.log(`The sum of ${addend1} + ${addend2} --> ${sum}`);

const personController = new PersonController();
const birthDate = '2004-01-13';

const days = personController.computageAgeInDays(birthDate);
console.log(`My age in days is --> ${days}`);

const years = personController.computageAgeInYears(birthDate);
console.log(`My age in years is --> ${years}`);
