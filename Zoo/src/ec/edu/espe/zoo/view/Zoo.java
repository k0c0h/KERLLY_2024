
package ec.edu.espe.zoo.view;

import ec.edu.espe.zoo.model.*;
import java.util.ArrayList;
import java.util.Date;

/**
 *
 * @author Kerlly Chiriboga -ODS
 */
public class Zoo {
    public static void main(String[] args) {
        System.out.println("Hello Inheritance!");
        
        ArrayList<Animal> animals = new ArrayList<>();
        
        Date date = new Date();
        Cage cage = new Cage(1);
        Cage cageFelines = new Cage(2);
        Cage pool = new Cage(3);
        
        Lion lion = new Lion(0, date, cageFelines, 'm', 4);
        animals.add(lion);
        lion.feed(3);
        lion.feed(2,"deer");
        Shark shark = new Shark(0, date,pool, 'f', 0);
        shark.feed(1);
        animals.add(shark);
        
        lion.register(3);
        
        Bird bird = new Eagle(0, date, cage, 'm', 2);
        bird.feed(1);
        animals.add(bird);
        
        Primate primate = new Monkey(0, date, cage, 'f', 4);
        primate.feed(5); 
        animals.add(primate);
        primate.register(5);

        
        Animal animal;
        animal = new Tiger(0, date, cageFelines, 'f', 4);
        animal.feed(3);
        animals.add(animal);
        animal.register(6);
        
        animal = new Lion(0, date, cageFelines, 'f', 4);
        animal.feed(4);
        animals.add(animal);
        lion.feed(3, "zebra");
        
        System.out.println("Lion --> " + lion);
        
        Eagle eagle = new Eagle(0, date, cage, 'f', 2);
        animals.add(eagle);
        
        Condor condor = new Condor("Andes", 0, date, cage, 'm', 2);
        animals.add(condor);
        
        System.out.println("---------->     ANIMALS IN MY ZOO     <----------------");
        System.out.println(animals);
        
        for(Animal ani : animals)
        {
            System.out.println(ani);
        }
        
    }
}
