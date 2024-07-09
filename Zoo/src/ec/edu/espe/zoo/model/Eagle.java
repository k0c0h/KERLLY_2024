
package ec.edu.espe.zoo.model;

import java.util.Date;

/**
 *
 * @author Kerlly Chiriboga -ODS
 */
public class Eagle extends Bird{

    public Eagle(int id, Date bornOnDate, Cage cage, char gender, int numberOfLegs) {
        super(id, bornOnDate, cage, gender, numberOfLegs);
        region = 3;
    }
    
    
    @Override
    public void feed(int food){
        System.out.println("Feedimg an eagle with " + food + "mice");
    }
    
    public void feed(Food food){
        System.out.println("Feeding an eagle with " + food);
    }
    
}
