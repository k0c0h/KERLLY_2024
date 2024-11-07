package ec.espe.edu.AirlineReservationSystem.controller;

import ec.espe.edu.AirlineReservationSystem.controller.AdTicketsController;
import javax.swing.*;
import javax.swing.table.*;
import javax.swing.table.TableCellEditor;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.table.DefaultTableModel;

/**
 *
 * Author: Kerlly Chiriboga, ODS
 */

public class ButtonEditor extends DefaultCellEditor {

    private JButton btnUpdate;
    private JButton btnDelete;
    private JPanel buttonPanel;
    private JTable table;
    private AdTicketsController adTicketsController;

    public ButtonEditor(JCheckBox checkBox, JTable table) {
        super(checkBox);
        this.table = table;
        this.adTicketsController = adTicketsController;

        buttonPanel = new JPanel(new GridLayout(1, 2));

        btnUpdate = new JButton("Update");
        btnDelete = new JButton("Delete");

        buttonPanel.add(btnUpdate);
        buttonPanel.add(btnDelete);

        btnUpdate.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int row = table.getSelectedRow();
                int ticketId = (Integer) table.getValueAt(row, 1);
                JOptionPane.showMessageDialog(null, "Update functionality for Ticket ID: " + ticketId);

            }
        });

        btnDelete.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int row = table.getSelectedRow();
                int ticketId = (Integer) table.getValueAt(row, 1);
                int response = JOptionPane.showConfirmDialog(null,
                        "Are you sure you want to delete Ticket ID: " + ticketId + "?",
                        "Confirm Delete",
                        JOptionPane.YES_NO_OPTION,
                        JOptionPane.WARNING_MESSAGE);

                if (response == JOptionPane.YES_OPTION) {
                    adTicketsController.deleteTicket(ticketId);
                    ((DefaultTableModel) table.getModel()).removeRow(row);
                }
            }
        });
    }

    @Override
    public Component getTableCellEditorComponent(JTable table, Object value, boolean isSelected, int row, int column) {
        buttonPanel.setPreferredSize(new Dimension(table.getColumnModel().getColumn(column).getWidth(), table.getRowHeight()));
        return buttonPanel;
    }

    @Override
    public Object getCellEditorValue() {
        return null;
    }
}
