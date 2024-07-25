
package ec.espe.edu.AirlineReservationSystem.view;

import ec.espe.edu.AirlineReservationSystem.controller.AdUsuariosController;
import java.awt.Component;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import org.bson.Document;

import javax.swing.table.DefaultTableModel;
import java.util.List;
import javax.swing.DefaultCellEditor;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.table.TableCellRenderer;
import javax.swing.table.TableColumn;

/**
 *
 * @author Kerlly Chiriboga, ODS
 */

public class FrmAdUsuarios extends javax.swing.JFrame {

    private AdUsuariosController usuariosController;

    public FrmAdUsuarios() {
        initComponents();
        usuariosController = new AdUsuariosController();
        populateUsuariosTable();
        configureActionColumn();
        UsuariosTable.setRowHeight(40);
    }

    public JPanel getUsuariosPanel() {
        return Background;
    }

    private void populateUsuariosTable() {
        DefaultTableModel model = (DefaultTableModel) UsuariosTable.getModel();
        List<Document> usuarios = usuariosController.getUsuarios();
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
        model.setRowCount(0);

        for (Document usuario : usuarios) {
            Object[] row = new Object[10];
            row[0] = usuario.getString("id");
            row[1] = usuario.getString("name");
            row[2] = usuario.getString("email");
            row[3] = usuario.getString("phoneNumber");
            row[4] = usuario.getString("city");
            row[5] = usuario.getString("state");
            row[6] = usuario.getString("postalCode");
            row[7] = usuario.getDate("dateOfBirth") != null ? dateFormat.format(usuario.getDate("dateOfBirth")) : null;
            row[8] = usuario.getString("gender");

            JPanel buttonPanel = new JPanel();
            buttonPanel.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 0));

            JButton btnUpdate = new JButton("Actualizar");
            JButton btnDelete = new JButton("Eliminar");

            btnUpdate.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    String userId = (String) row[0];
                    String newName = JOptionPane.showInputDialog(null, "Ingrese el nuevo nombre:", row[1]);
                    String newEmail = JOptionPane.showInputDialog(null, "Ingrese el email:", row[2]);
                    String newPhoneNumber = JOptionPane.showInputDialog(null, "Ingrese el nuevo nùmero de teléfono:", row[3]);
                    String newCity = JOptionPane.showInputDialog(null, "Ingrese la nueva ciudad: ", row[4]);
                    String newState = JOptionPane.showInputDialog(null, "Ingrese la nueva provincia:", row[5]);
                    String newPostalCode = JOptionPane.showInputDialog(null, "Ingrese el nuevo código postal:", row[6]);
                    String newDateOfBirthStr = JOptionPane.showInputDialog(null, "Ingrese la nueva fecha de nacimiento (yyyy-MM-dd):", row[7]);
                    String newGender = JOptionPane.showInputDialog(null, "Ingrese el nuevo género:", row[8]);

                    if (newName != null && newEmail != null && newPhoneNumber != null &&
                        newCity != null && newState != null && newPostalCode != null &&
                        newDateOfBirthStr != null && newGender != null) {
                        try {
                            Date newDateOfBirth = new SimpleDateFormat("yyyy-MM-dd").parse(newDateOfBirthStr);
                            boolean success = usuariosController.updateUser(userId, newName, newEmail, newPhoneNumber, newCity, newState, newPostalCode, newDateOfBirth, newGender);

                            if (success) {
                                JOptionPane.showMessageDialog(null, "Usuario actualizado correctamente.");
                                populateUsuariosTable();
                            } else {
                                JOptionPane.showMessageDialog(null, "Failed to update user.");
                            }
                        } catch (ParseException ex) {
                            JOptionPane.showMessageDialog(null, "Invalid date format.");
                        }
                    }
                }
            });

            btnDelete.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    String userId = (String) row[0];
                    int response = JOptionPane.showConfirmDialog(null,
                            "¿Estás segura de que quieres eliminar el usuario con ID: " + userId + "?",
                            "Confirmar eliminación",
                            JOptionPane.YES_NO_OPTION,
                            JOptionPane.WARNING_MESSAGE);

                    if (response == JOptionPane.YES_OPTION) {
                        boolean success = usuariosController.deleteUser(userId);

                        if (success) {
                            JOptionPane.showMessageDialog(null, "Usuario eliminado correctamente.");
                            populateUsuariosTable();
                        } else {
                            JOptionPane.showMessageDialog(null, "Failed to delete user.");
                        }
                    }
                }
            });

            buttonPanel.add(btnUpdate);
            buttonPanel.add(btnDelete);
            row[9] = buttonPanel;

            model.addRow(row);
        }
    }

    private void configureActionColumn() {
        TableColumn actionColumn = UsuariosTable.getColumnModel().getColumn(9);
        actionColumn.setCellRenderer(new ButtonRenderer());
        actionColumn.setCellEditor(new ButtonEditor(new JCheckBox()));
        actionColumn.setPreferredWidth(200);
    }

    class ButtonRenderer extends JPanel implements TableCellRenderer {
        public ButtonRenderer() {
            setLayout(new FlowLayout(FlowLayout.CENTER, 5, 0));
        }

        @Override
        public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
            removeAll();
            if (value instanceof JPanel) {
                add((JPanel) value);
            }
            return this;
        }
    }

    class ButtonEditor extends DefaultCellEditor {
        private JPanel panel;

        public ButtonEditor(JCheckBox checkBox) {
            super(checkBox);
            panel = new JPanel();
            panel.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 0));
        }

        @Override
        public Component getTableCellEditorComponent(JTable table, Object value, boolean isSelected, int row, int column) {
            panel.removeAll();
            if (value instanceof JPanel) {
                panel.add((JPanel) value);
            }
            return panel;
        }

        @Override
        public Object getCellEditorValue() {
            return null;
        }

        @Override
        public boolean stopCellEditing() {
            return super.stopCellEditing();
        }
    }



    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Background = new javax.swing.JPanel();
        jPanel1 = new javax.swing.JPanel();
        Equipajetxt = new javax.swing.JLabel();
        Imagelogotxt = new javax.swing.JLabel();
        arstxt = new javax.swing.JLabel();
        lblDate = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        UsuariosTable = new javax.swing.JTable();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        Background.setBackground(new java.awt.Color(255, 255, 255));
        Background.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        Equipajetxt.setFont(new java.awt.Font("Trebuchet MS", 1, 36)); // NOI18N
        Equipajetxt.setForeground(new java.awt.Color(255, 255, 255));
        Equipajetxt.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Equipajetxt.setText("Usuarios");
        jPanel1.add(Equipajetxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(60, 30, -1, 78));

        Imagelogotxt.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/airline company icon .jpg"))); // NOI18N
        Imagelogotxt.setText("jLabel1");
        jPanel1.add(Imagelogotxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(730, 0, 160, 130));

        arstxt.setFont(new java.awt.Font("Engravers MT", 0, 14)); // NOI18N
        arstxt.setForeground(new java.awt.Color(255, 255, 255));
        arstxt.setText("Airline Reservation System");
        jPanel1.add(arstxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(390, 20, 300, 50));

        lblDate.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/fondo.jpeg"))); // NOI18N
        lblDate.setText("jLabel1");
        jPanel1.add(lblDate, new org.netbeans.lib.awtextra.AbsoluteConstraints(-10, 0, 930, -1));

        Background.add(jPanel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, 920, 150));

        jLabel1.setFont(new java.awt.Font("Segoe UI Black", 1, 18)); // NOI18N
        jLabel1.setText("Lista de Usuarios Registrados:");
        Background.add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 210, -1, -1));

        UsuariosTable.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null, null, null, null}
            },
            new String [] {
                "User ID", "Name", "Email", "Phone Number", "City", "State", "Postal Code", "Date Of Birth", "Gender", "Actions"
            }
        ));
        jScrollPane1.setViewportView(UsuariosTable);

        Background.add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 250, 780, 160));

        jLabel4.setText("(C) Overnight Developerr Squad - ODS");
        Background.add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(690, 470, -1, -1));

        jLabel5.setText("(R) Overnight Developer Squad");
        Background.add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(710, 440, -1, -1));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(Background, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(Background, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
    /* Set the Nimbus look and feel */
    //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
    /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
     */
    try {
        for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
            if ("Nimbus".equals(info.getName())) {
                javax.swing.UIManager.setLookAndFeel(info.getClassName());
                break;
            }
        }
    } catch (ClassNotFoundException ex) {
        java.util.logging.Logger.getLogger(FrmAdUsuarios.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
    } catch (InstantiationException ex) {
        java.util.logging.Logger.getLogger(FrmAdUsuarios.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
    } catch (IllegalAccessException ex) {
        java.util.logging.Logger.getLogger(FrmAdUsuarios.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
    } catch (javax.swing.UnsupportedLookAndFeelException ex) {
        java.util.logging.Logger.getLogger(FrmAdUsuarios.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
    }
    //</editor-fold>
    //</editor-fold>

    /* Create and display the form */
    java.awt.EventQueue.invokeLater(new Runnable() {
        public void run() {
            new FrmAdUsuarios().setVisible(true);
        }
    });
}

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JPanel Background;
    private javax.swing.JLabel Equipajetxt;
    private javax.swing.JLabel Imagelogotxt;
    private javax.swing.JTable UsuariosTable;
    private javax.swing.JLabel arstxt;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel lblDate;
    // End of variables declaration//GEN-END:variables
}
