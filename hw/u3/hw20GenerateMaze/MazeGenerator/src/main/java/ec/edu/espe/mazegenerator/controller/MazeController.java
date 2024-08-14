
package ec.edu.espe.mazegenerator.controller;

import ec.edu.espe.mazegenerator.model.Cell;
import ec.edu.espe.mazegenerator.model.IMazeGenerator;
import ec.edu.espe.mazegenerator.model.RecursiveMazeGenerator;
import ec.edu.espe.mazegenerator.view.MazeApp;

/**
 *
 * @author Kerlly Chiriboga, ODS
 */
public class MazeController {
    private MazeApp view;
    private IMazeGenerator mazeGenerator;
    private int width, height;

    public MazeController(MazeApp view) {
        this.view = view;
        this.mazeGenerator = new RecursiveMazeGenerator();
    }

    public void setMazeDimensions(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public void generateMaze() {
        if (width <= 0 || height <= 0) {
            view.showError("Width and height must be positive numbers.");
            return;
        }
        
        Cell[][] maze = mazeGenerator.generateMaze(width, height);
        view.setMaze(maze);
    }
}