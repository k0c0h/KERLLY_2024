
package ec.edu.espe.basicoperations.controller;

import java.time.LocalDate;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 *
 * @author Kerlly Chiriboga - ODS
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
        LocalDate birthDate = LocalDate.parse("2004-01-13");
        PersonController instance = new PersonController();
        int expResult = 7482 ;//7475
        int result = instance.computageAgeInDays(birthDate);
        assertEquals(expResult, result);
    }

    /**
     * Test of computageAgeInYears method, of class PersonController.
     */
    @Test
    public void testComputageAgeInYears() {
        System.out.println("computageAgeInYears");
        LocalDate birthDate = LocalDate.parse("2004-01-13");
        PersonController instance = new PersonController();
        int expResult = 20;
        int result = instance.computageAgeInYears(birthDate);
        assertEquals(expResult, result);
    }
    
}
