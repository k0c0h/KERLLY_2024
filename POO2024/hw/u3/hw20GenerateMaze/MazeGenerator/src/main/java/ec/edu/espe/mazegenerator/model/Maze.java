package ec.edu.espe.mazegenerator.model;

/**
 *
 * @author Kerlly Chiriboga, ODS
 */
public class Maze {
    private Room[][] rooms;
    private int width;
    private int height;

    public Maze(int width, int height) {
        this.width = width;
        this.height = height;
        rooms = new Room[width][height];
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                rooms[i][j] = new Room();
            }
        }
    }

    public Room getRoom(int x, int y) {
        return rooms[x][y];
    }

    public int getWidth() { return width; }
    public int getHeight() { return height; }
}

