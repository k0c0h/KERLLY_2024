/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ec.espe.edu.AirlineReservationSystem.model;

/**
 *
 * @author Joffre
 */
public class Baggage {
   
    private int weight;
    private String type;

    public Baggage(int weight, String type) {
        this.weight = weight;
        this.type = type;
    }

    
    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

   
    public Baggage(int weight) {
        this.weight = weight;
        this.type = null;
    }

    @Override
    public String toString() {
        return "Baggage{" + "weight=" + weight + ", type=" + type + '}';
    }
    
    
}
   
  
