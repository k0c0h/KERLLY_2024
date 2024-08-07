package ec.edu.espe.AirlineReservationSystem.view;


/**
 *
 * @author Miguel Caiza,Overnight Developers Squad,DCCO-ESPE
 */
public class FrmAirlineReservationSystem extends javax.swing.JFrame {

    /**
     * Creates new form FmAirlineReservationSystemMenu
     */
    public FrmAirlineReservationSystem() {
        initComponents();
        setLocationRelativeTo(null);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jCheckBoxMenuItem5 = new javax.swing.JCheckBoxMenuItem();
        jMenuBar1 = new javax.swing.JMenuBar();
        mnuCustomer = new javax.swing.JMenu();
        itemUser = new javax.swing.JMenuItem();
        itemLogout = new javax.swing.JMenuItem();
        itemExit = new javax.swing.JMenuItem();
        jMenu2 = new javax.swing.JMenu();
        itemCreateCustomer = new javax.swing.JMenuItem();
        mnuFlight = new javax.swing.JMenu();
        jMenu3 = new javax.swing.JMenu();
        itemChangeFlightData = new javax.swing.JMenuItem();
        mnuTicket = new javax.swing.JMenu();
        mnuOffer = new javax.swing.JMenu();
        mnuBaggage = new javax.swing.JMenu();
        mnuHelp = new javax.swing.JMenu();

        jCheckBoxMenuItem5.setSelected(true);
        jCheckBoxMenuItem5.setText("jCheckBoxMenuItem5");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        mnuCustomer.setText("Airline Reservation");

        itemUser.setText("Crear Usuario");
        mnuCustomer.add(itemUser);

        itemLogout.setText("Logout");
        mnuCustomer.add(itemLogout);

        itemExit.setText("Exit");
        itemExit.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                itemExitActionPerformed(evt);
            }
        });
        mnuCustomer.add(itemExit);

        jMenuBar1.add(mnuCustomer);

        jMenu2.setText("Cliente");

        itemCreateCustomer.setText("Crear Cliente");
        itemCreateCustomer.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                itemCreateCustomerActionPerformed(evt);
            }
        });
        jMenu2.add(itemCreateCustomer);

        jMenuBar1.add(jMenu2);

        mnuFlight.setText("Vuelo");

        jMenu3.setText("Crear Vuelo");

        itemChangeFlightData.setText("Cambiar Datos del Vuelo");
        jMenu3.add(itemChangeFlightData);

        mnuFlight.add(jMenu3);

        jMenuBar1.add(mnuFlight);

        mnuTicket.setText("Ticket");
        jMenuBar1.add(mnuTicket);

        mnuOffer.setText("Ofertas");
        jMenuBar1.add(mnuOffer);

        mnuBaggage.setText("Equipaje");
        jMenuBar1.add(mnuBaggage);

        mnuHelp.setText("Ayuda");
        jMenuBar1.add(mnuHelp);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 649, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 368, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void itemExitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_itemExitActionPerformed
        System.exit(0);
    }//GEN-LAST:event_itemExitActionPerformed

    private void itemCreateCustomerActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_itemCreateCustomerActionPerformed
        FrmCreateCustomer frmCreateCustomer = new FrmCreateCustomer();
        this.setVisible(false);
        frmCreateCustomer.setVisible(true);

    }//GEN-LAST:event_itemCreateCustomerActionPerformed

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
            java.util.logging.Logger.getLogger(FrmAirlineReservationSystem.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(FrmAirlineReservationSystem.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(FrmAirlineReservationSystem.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(FrmAirlineReservationSystem.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new FrmAirlineReservationSystem().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuItem itemChangeFlightData;
    private javax.swing.JMenuItem itemCreateCustomer;
    private javax.swing.JMenuItem itemExit;
    private javax.swing.JMenuItem itemLogout;
    private javax.swing.JMenuItem itemUser;
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItem5;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenu jMenu3;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenu mnuBaggage;
    private javax.swing.JMenu mnuCustomer;
    private javax.swing.JMenu mnuFlight;
    private javax.swing.JMenu mnuHelp;
    private javax.swing.JMenu mnuOffer;
    private javax.swing.JMenu mnuTicket;
    // End of variables declaration//GEN-END:variables
}
