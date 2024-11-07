
package ec.edu.espe.zoo.model;

import java.util.Date;

/**
 *
 * @author Kerlly Chiriboga -ODS
 */
public class Lion extends Feline {

    public Lion(int id, Date bornOnDate, Cage cage, char gender, int numberOfLegs) {
        super(id, bornOnDate, cage, gender, numberOfLegs);
    }

    @Override
    public void feed(int food){
        System.out.println("Feeding a lion with " + food + " pouns of meat ");
    }
    
    public void feed(int food, String type){
        System.out.println("Feeding a lion with " + food + " " + type + "(s)");
    }
    
}
