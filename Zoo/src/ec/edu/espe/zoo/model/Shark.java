
package ec.edu.espe.zoo.model;

import java.util.Date;

/**
 *
 * @author Kerlly Chiriboga -ODS
 */
public class Shark extends Fish{

    public Shark(int id, Date bornOnDate, Cage cage, char gender, int numberOfLegs) {
        super(id, bornOnDate, cage, gender, numberOfLegs);
    }
    @Override
    public void feed(int food){
        System.out.println("Feeding a shark with " + food + " fish ");
    }
}
