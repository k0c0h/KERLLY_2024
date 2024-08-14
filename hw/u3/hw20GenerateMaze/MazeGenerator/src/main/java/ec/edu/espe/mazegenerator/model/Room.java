package ec.edu.espe.mazegenerator.model;

/**
 *
 * @author Kerlly Chiriboga, ODS
 */
public class Room {
    private boolean hasNorthDoor;
    private boolean hasSouthDoor;
    private boolean hasEastDoor;
    private boolean hasWestDoor;

    public boolean hasNorthDoor() { return hasNorthDoor; }
    public boolean hasSouthDoor() { return hasSouthDoor; }
    public boolean hasEastDoor() { return hasEastDoor; }
    public boolean hasWestDoor() { return hasWestDoor; }

    public void setNorthDoor(boolean hasNorthDoor) { this.hasNorthDoor = hasNorthDoor; }
    public void setSouthDoor(boolean hasSouthDoor) { this.hasSouthDoor = hasSouthDoor; }
    public void setEastDoor(boolean hasEastDoor) { this.hasEastDoor = hasEastDoor; }
    public void setWestDoor(boolean hasWestDoor) { this.hasWestDoor = hasWestDoor; }
}

