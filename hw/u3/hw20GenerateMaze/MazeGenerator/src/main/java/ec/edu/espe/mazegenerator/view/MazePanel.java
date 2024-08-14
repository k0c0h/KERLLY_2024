package ec.edu.espe.mazegenerator.view;
import ec.edu.espe.mazegenerator.model.Cell;
import javax.swing.*;
import java.awt.*;
/**
 *
 * @author Kerlly Chiriboga, ODS
 */


public class MazePanel extends JPanel {
    private Cell[][] maze;

    public void setMaze(Cell[][] maze) {
        this.maze = maze;
        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        if (maze == null) return;

        int cellSize = Math.min(getWidth(), getHeight()) / Math.max(maze.length, maze[0].length);

        for (int x = 0; x < maze.length; x++) {
            for (int y = 0; y < maze[0].length; y++) {
                Cell cell = maze[x][y];
                int posX = x * cellSize;
                int posY = y * cellSize;

                g.setColor(Color.BLACK);
                if (cell.topWall) g.drawLine(posX, posY, posX + cellSize, posY);
                if (cell.rightWall) g.drawLine(posX + cellSize, posY, posX + cellSize, posY + cellSize);
                if (cell.bottomWall) g.drawLine(posX, posY + cellSize, posX + cellSize, posY + cellSize);
                if (cell.leftWall) g.drawLine(posX, posY, posX, posY + cellSize);

                if (cell.isEntrance) {
                    g.setColor(Color.BLACK); 
                    g.setFont(new Font("Arial", Font.BOLD, cellSize / 2));
                    g.drawString("E", posX + cellSize / 4, posY + 3 * cellSize / 4);
                } else if (cell.isExit) {
                    g.setColor(Color.BLACK);
                    g.setFont(new Font("Arial", Font.BOLD, cellSize / 2));
                    g.drawString("S", posX + cellSize / 4, posY + 3 * cellSize / 4);
                }
            }
        }
    }
}