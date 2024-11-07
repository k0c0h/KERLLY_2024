package ec.edu.espe.mazegenerator.view;
import ec.edu.espe.mazegenerator.model.Cell;
import javax.swing.*;
import java.awt.*;

/**
 *
 * @author Kerlly Chiriboga, ODS
 */

public class MazeView extends JPanel {
    private Cell[][] maze;
    private int width, height;

    public MazeView(int width, int height) {
        this.width = width;
        this.height = height;
        setPreferredSize(new Dimension(width * 20, height * 20)); 
    }

    public void setMaze(Cell[][] maze) {
        this.maze = maze;
        repaint();
    }

    public int getMazeWidth() {
        return width;
    }

    public int getMazeHeight() {
        return height;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (maze != null) {
            drawMaze(g);
        }
    }

    private void drawMaze(Graphics g) {
        if (maze == null) return;

        int cellSize = 20;
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                Cell cell = maze[x][y];
                int posX = x * cellSize;
                int posY = y * cellSize;

                if (cell.topWall) g.drawLine(posX, posY, posX + cellSize, posY);
                if (cell.rightWall) g.drawLine(posX + cellSize, posY, posX + cellSize, posY + cellSize);
                if (cell.bottomWall) g.drawLine(posX, posY + cellSize, posX + cellSize, posY + cellSize);
                if (cell.leftWall) g.drawLine(posX, posY, posX, posY + cellSize);
            }
        }
    }
}