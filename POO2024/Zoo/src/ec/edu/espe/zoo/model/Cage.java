
package ec.edu.espe.zoo.model;

/**
 *
 * @author Kerlly Chiriboga -ODS
 */
public class Cage {
    private int id;

    @Override
    public String toString() {
        return "Cage{" + "id=" + id + '}';
    }

    public Cage(int id) {
        this.id = id;
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
    
    
}
