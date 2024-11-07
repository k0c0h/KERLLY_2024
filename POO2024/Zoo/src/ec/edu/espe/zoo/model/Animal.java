
package ec.edu.espe.zoo.model;

import java.util.Date;

/**
 *
 * @author Kerlly Chiriboga -ODS
 */
public abstract class Animal {
    private int id;
    private Date bornOnDate;
    private Cage cage;
    private char gender;
    private int numberOfLegs;
    protected int region; //publico hijos privado otros
    
    public void register(int cageId){
        System.out.println("");}
    
    public void feed(int food){
        
    }

    @Override
    public String toString() {
        return "Animal{" + "id=" + id + ", bornOnDate=" + bornOnDate + ", cage=" + cage + ", gender=" + gender + ", numberOfLegs=" + numberOfLegs + '}';
    }
     
            
    public Animal(int id, Date bornOnDate, Cage cage, char gender, int numberOfLegs) {
        this.id = id;
        this.bornOnDate = bornOnDate;
        this.cage = cage;
        this.gender = gender;
        this.numberOfLegs = numberOfLegs;
    }

    
    /**
     * @return the id
     */
    public int getId() {
        return id;
    }

    /**
     * @param id the id to set
     */
    public void setId(int id) {
        this.id = id;
    }

    /**
     * @return the bornOnDate
     */
    public Date getBornOnDate() {
        return bornOnDate;
    }

    /**
     * @param bornOnDate the bornOnDate to set
     */
    public void setBornOnDate(Date bornOnDate) {
        this.bornOnDate = bornOnDate;
    }

    /**
     * @return the cage
     */
    public Cage getCage() {
        return cage;
    }

    /**
     * @param cage the cage to set
     */
    public void setCage(Cage cage) {
        this.cage = cage;
    }

    /**
     * @return the gender
     */
    public char getGender() {
        return gender;
    }

    /**
     * @param gender the gender to set
     */
    public void setGender(char gender) {
        this.gender = gender;
    }

    /**
     * @return the numberOfLegs
     */
    public int getNumberOfLegs() {
        return numberOfLegs;
    }

    /**
     * @param numberOfLegs the numberOfLegs to set
     */
    public void setNumberOfLegs(int numberOfLegs) {
        this.numberOfLegs = numberOfLegs;
    }
    
}
