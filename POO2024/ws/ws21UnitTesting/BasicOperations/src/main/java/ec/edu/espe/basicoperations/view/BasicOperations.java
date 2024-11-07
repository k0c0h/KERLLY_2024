package ec.edu.espe.basicoperations.view;

import static ec.edu.espe.basicoperations.controller.BasicOperation.addTwoNumbers;
import ec.edu.espe.basicoperations.controller.PersonController;
import java.time.LocalDate;

/**
 *
 * @author G400
 */
public class BasicOperations {

    public static void main(String[] args) {
        System.out.println("Basic Operations! \nKerlly Chiriboga, OOP 14539");
        System.out.println("---> Unit Testing in action <---");

        float addend1;
        float addend2;
        float sum;
        float sum1;
        float sum2;

        addend1 = 1.2F;
        addend2 = 2.4F;

        sum = addend1 + addend2;

        System.out.println("The sum of " + addend1 + " + " + addend2 + "--> " + sum);
        
        sum1 = addTwoNumbers(addend1, addend2);
        
        System.out.println("The sum of " + addend1 + " + " + addend2 + "--> " + sum1);
     
        sum2 = add(addend1, addend2);
        
        System.out.println("The sum of " + addend1 + " + " + addend2 + "--> " + sum2);

        PersonController personController = new PersonController();
        
        LocalDate bornOnDate;
        bornOnDate = LocalDate.parse("1970-12-17");
        int days;
        
        days = personController.computageAgeInDays(bornOnDate);
        
        System.out.println("My days are --> " + days);
        
        
    }

    public static float add(float addend1, float addend2) {
        float sum;
        sum = addend1 + addend2;
        return sum;
    }


}
