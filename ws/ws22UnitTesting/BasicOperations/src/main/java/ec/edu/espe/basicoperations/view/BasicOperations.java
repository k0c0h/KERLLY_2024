package ec.edu.espe.basicoperations.view;

import ec.edu.espe.basicoperations.controller.BasicOperation;
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


        addend1 = 1.2F;
        addend2 = 2.4F;

        sum = addend1 + addend2;

        System.out.println("The sum of " + addend1 + " + " + addend2 + "--> " + sum);


        addend1 = 1.8F;
        addend2 = -2.2F;        
        
        
        sum = BasicOperation.addTwoNumbers(addend1, addend2);
        
        System.out.println("The sum of " + addend1 + " + " + addend2 + "--> " + sum);

        PersonController personController = new PersonController();
        
        LocalDate bornOnDate;
        bornOnDate = LocalDate.parse("2004-01-13");
        int days;
        
        days = personController.computageAgeInDays(bornOnDate);
        
        System.out.println("My age in days is --> " + days);
        
        int numberOfYears;
        numberOfYears = personController.computageAgeInYears(bornOnDate);
        System.out.println("My age in years is --> " + numberOfYears);
        
        
    }

}
