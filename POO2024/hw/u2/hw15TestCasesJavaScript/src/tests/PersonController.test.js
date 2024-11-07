
const PersonController = require('../controllers/PersonController');
const { differenceInDays, differenceInYears } = require('date-fns');

describe('PersonController', () => {
  let personController;

  beforeEach(() => {
    personController = new PersonController();
  });

  test('computageAgeInDays', () => {
    const birthDate = '2004-01-13';
    const expectedDays = differenceInDays(new Date(), new Date(birthDate));
    const result = personController.computageAgeInDays(birthDate);
    expect(result).toBe(expectedDays);
  });

  test('computageAgeInYears', () => {
    const birthDate = '2004-01-13';
    const expectedYears = differenceInYears(new Date(), new Date(birthDate));
    const result = personController.computageAgeInYears(birthDate);
    expect(result).toBe(expectedYears);
  });
});
