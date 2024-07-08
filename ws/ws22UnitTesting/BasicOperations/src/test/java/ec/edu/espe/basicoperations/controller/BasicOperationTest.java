
package ec.edu.espe.basicoperations.controller;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 *
 * @author Kerlly Chiriboga - ODS
 */
public class BasicOperationTest {
    
    public BasicOperationTest() {
    }

    /**
     * Test of addTwoNumbers method, of class BasicOperation.
     */
    @Test
    public void testAddTwoNumbers() {
        System.out.println("addTwoNumbers");
        float addend1 = 1.2F;
        float addend2 = 2.4F;
        float expResult = 3.6F;
        float result = BasicOperation.addTwoNumbers(addend1, addend2);
        assertEquals(expResult, result, 0);
    }
    
        @Test
    public void testAddTwoNumbersNegative() {
        System.out.println("addTwoNumbers");
        float addend1 = 1.8F;
        float addend2 = -2.2F;
        float expResult = -0.4F;
        float result = BasicOperation.addTwoNumbers(addend1, addend2);
        assertEquals(expResult, result, 0);
    }
    
        @Test
    public void testAddTwoNumbersIntegers() {
        System.out.println("addTwoNumbers");
        float addend1 = 1;
        float addend2 = 2;
        float expResult = 3;
        float result = BasicOperation.addTwoNumbers(addend1, addend2);
        assertEquals(expResult, result, 0);
    }

}
