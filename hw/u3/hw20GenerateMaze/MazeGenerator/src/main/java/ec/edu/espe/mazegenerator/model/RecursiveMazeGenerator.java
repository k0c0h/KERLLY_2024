package ec.edu.espe.mazegenerator.model;

import java.util.Random;
import java.util.Collections;

/**
 *
 * @author Kerlly Chiriboga, ODS
 */
public class RecursiveMazeGenerator implements IMazeGenerator {

    private int width, height;
    private Cell[][] maze;
    private int entranceX, entranceY, exitX, exitY;

    @Override
    public Cell[][] generateMaze(int width, int height) {
        this.width = width;
        this.height = height;
        maze = new Cell[width][height];

        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                maze[x][y] = new Cell();
            }
        }
        selectEntranceAndExit();
        generate(entranceX, entranceY);

        return maze;
    }

    private void selectEntranceAndExit() {
        Random rand = new Random();
        int entranceEdge = rand.nextInt(4);
        if (entranceEdge == 0) { 
            entranceX = rand.nextInt(width);
            entranceY = 0;
            maze[entranceX][entranceY].topWall = false;
            maze[entranceX][entranceY].isEntrance = true;
        } else if (entranceEdge == 1) {
            entranceX = width - 1;
            entranceY = rand.nextInt(height);
            maze[entranceX][entranceY].rightWall = false;
            maze[entranceX][entranceY].isEntrance = true;
        } else if (entranceEdge == 2) { 
            entranceX = rand.nextInt(width);
            entranceY = height - 1;
            maze[entranceX][entranceY].bottomWall = false;
            maze[entranceX][entranceY].isEntrance = true;
        } else { 
            entranceX = 0;
            entranceY = rand.nextInt(height);
            maze[entranceX][entranceY].leftWall = false;
            maze[entranceX][entranceY].isEntrance = true;
        }

        int exitEdge;
        do {
            exitEdge = rand.nextInt(4);
        } while (exitEdge == entranceEdge);

        if (exitEdge == 0) { 
            exitX = rand.nextInt(width);
            exitY = 0;
            maze[exitX][exitY].topWall = false;
            maze[exitX][exitY].isExit = true;
        } else if (exitEdge == 1) { 
            exitX = width - 1;
            exitY = rand.nextInt(height);
            maze[exitX][exitY].rightWall = false;
            maze[exitX][exitY].isExit = true;
        } else if (exitEdge == 2) { 
            exitX = rand.nextInt(width);
            exitY = height - 1;
            maze[exitX][exitY].bottomWall = false;
            maze[exitX][exitY].isExit = true;
        } else { 
            exitX = 0;
            exitY = rand.nextInt(height);
            maze[exitX][exitY].leftWall = false;
            maze[exitX][exitY].isExit = true;
        }
    }

    private void generate(int x, int y) {
        maze[x][y].visited = true;
        Integer[] directions = {0, 1, 2, 3};
        Collections.shuffle(java.util.Arrays.asList(directions));

        for (int direction : directions) {
            int newX = x, newY = y;

            switch (direction) {
                case 0:
                    newY = y - 1;
                    break;
                case 1:
                    newX = x + 1;
                    break;
                case 2:
                    newY = y + 1;
                    break;
                case 3:
                    newX = x - 1;
                    break;
            }

            if (isValidCell(newX, newY) && !maze[newX][newY].visited) {
                removeWall(x, y, newX, newY);
                generate(newX, newY);
            }
        }
    }

    private boolean isValidCell(int x, int y) {
        return x >= 0 && x < width && y >= 0 && y < height;
    }

    private void removeWall(int x1, int y1, int x2, int y2) {
        if (x1 == x2) {
            if (y1 > y2) {
                maze[x1][y1].topWall = false;
                maze[x2][y2].bottomWall = false;
            } else {
                maze[x1][y1].bottomWall = false;
                maze[x2][y2].topWall = false;
            }
        } else {
            if (x1 > x2) {
                maze[x1][y1].leftWall = false;
                maze[x2][y2].rightWall = false;
            } else {
                maze[x1][y1].rightWall = false;
                maze[x2][y2].leftWall = false;
            }
        }
    }
}
