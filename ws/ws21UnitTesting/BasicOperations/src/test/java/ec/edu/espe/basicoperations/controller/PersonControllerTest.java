
package ec.edu.espe.basicoperations.controller;

import java.time.LocalDate;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 *
 * @author G400
 */
public class PersonControllerTest {
    
    public PersonControllerTest() {
    }

    /**
     * Test of computageAgeInDays method, of class PersonController.
     */
    @Test
    public void testComputageAgeInDays() {
        System.out.println("computageAgeInDays");
        LocalDate birthDate = LocalDate.parse("2004/01/13");
        PersonController instance = new PersonController();
        int expResult = 0;
        int result = instance.computageAgeInDays(birthDate);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of computageAgeInYears method, of class PersonController.
     */
    @Test
    public void testComputageAgeInYears() {
        System.out.println("computageAgeInYears");
        LocalDate birthDate = LocalDate.parse("2004/01/13");
        PersonController instance = new PersonController();
        int expResult = 0;
        int result = instance.computageAgeInYears(birthDate);
        assertEquals(expResult, result);
        fail("The test case is a prototype.");
    }
    
}
