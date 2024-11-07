/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package ec.espe.edu.AirlineReservationSystem.view;

import ec.espe.edu.AirlineReservationSystem.controller.TicketController;
import ec.espe.edu.AirlineReservationSystem.model.Ticket;
import javax.swing.JOptionPane;

/**
 *
 * @author Joffre
 */
public class PayMethod extends javax.swing.JFrame {

;

    public PayMethod() {
     
        initComponents(); 
    }
    
        
     
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        botones = new javax.swing.ButtonGroup();
        background4 = new javax.swing.JPanel();
        arstxt4 = new javax.swing.JLabel();
        fondo4 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        BDebit = new javax.swing.JRadioButton();
        BCredit = new javax.swing.JRadioButton();
        BPaypal = new javax.swing.JRadioButton();
        jLabel6 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        TicketCosttxt = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        background4.setBackground(new java.awt.Color(255, 255, 255));
        background4.setRequestFocusEnabled(false);
        background4.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        arstxt4.setFont(new java.awt.Font("Engravers MT", 0, 14)); // NOI18N
        arstxt4.setForeground(new java.awt.Color(255, 255, 255));
        arstxt4.setText("Airline Reservation System");
        background4.add(arstxt4, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 0, 300, 50));

        fondo4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/fondo.jpeg"))); // NOI18N
        background4.add(fondo4, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, 680, 48));

        jLabel2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/airline company icon .jpg"))); // NOI18N
        background4.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(480, 320, 150, 140));

        jLabel3.setFont(new java.awt.Font("Segoe UI Black", 1, 16)); // NOI18N
        jLabel3.setText("Ingrese el tipo de Pago:");
        background4.add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 280, -1, -1));

        jLabel4.setText("(C) Overnight Developerr Squad - ODS");
        background4.add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(440, 290, -1, -1));

        jLabel5.setText("(R) Overnight Developer Squad");
        background4.add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(460, 260, -1, -1));

        jButton1.setText("Confirmar");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        background4.add(jButton1, new org.netbeans.lib.awtextra.AbsoluteConstraints(260, 410, 90, -1));

        BDebit.setBackground(new java.awt.Color(255, 255, 255));
        botones.add(BDebit);
        BDebit.setFont(new java.awt.Font("Segoe UI Light", 1, 12)); // NOI18N
        BDebit.setText("Tarjeta de Credito");
        BDebit.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BDebitActionPerformed(evt);
            }
        });
        background4.add(BDebit, new org.netbeans.lib.awtextra.AbsoluteConstraints(210, 220, -1, -1));

        botones.add(BCredit);
        BCredit.setFont(new java.awt.Font("Segoe UI Light", 1, 12)); // NOI18N
        BCredit.setText("Tarjeta de Debito");
        background4.add(BCredit, new org.netbeans.lib.awtextra.AbsoluteConstraints(210, 280, -1, -1));

        botones.add(BPaypal);
        BPaypal.setFont(new java.awt.Font("Segoe UI Light", 1, 12)); // NOI18N
        BPaypal.setText("Paypal");
        BPaypal.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BPaypalActionPerformed(evt);
            }
        });
        background4.add(BPaypal, new org.netbeans.lib.awtextra.AbsoluteConstraints(210, 340, -1, -1));

        jLabel6.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/visa.png"))); // NOI18N
        background4.add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(340, 210, -1, -1));

        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/card.png"))); // NOI18N
        background4.add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(350, 280, 50, 30));

        jLabel7.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/paypal.png"))); // NOI18N
        background4.add(jLabel7, new org.netbeans.lib.awtextra.AbsoluteConstraints(350, 330, 50, 30));

        jLabel8.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/tarjeta-de-credito.png"))); // NOI18N
        background4.add(jLabel8, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 70, 140, 110));

        jLabel9.setFont(new java.awt.Font("Segoe UI Black", 1, 18)); // NOI18N
        jLabel9.setText("Estimado cliente sus datos son privados ");
        background4.add(jLabel9, new org.netbeans.lib.awtextra.AbsoluteConstraints(220, 80, 390, 30));

        jLabel10.setFont(new java.awt.Font("Segoe UI Black", 2, 18)); // NOI18N
        jLabel10.setText("Protejalos...");
        background4.add(jLabel10, new org.netbeans.lib.awtextra.AbsoluteConstraints(340, 110, 120, 40));
        background4.add(TicketCosttxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 160, 220, 40));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addComponent(background4, javax.swing.GroupLayout.PREFERRED_SIZE, 678, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addComponent(background4, javax.swing.GroupLayout.PREFERRED_SIZE, 481, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
                                              

  if (BCredit.isSelected() || BDebit.isSelected() || BPaypal.isSelected()) {
    
    JOptionPane.showMessageDialog(this, "El pago se realizó con éxito.", "Éxito", JOptionPane.INFORMATION_MESSAGE);
     this.dispose();
} else {
    
    JOptionPane.showMessageDialog(this, "Por favor, seleccione un método de pago.", "Error", JOptionPane.ERROR_MESSAGE);
}
    }//GEN-LAST:event_jButton1ActionPerformed

    private void BDebitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BDebitActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_BDebitActionPerformed

    private void BPaypalActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BPaypalActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_BPaypalActionPerformed

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
            java.util.logging.Logger.getLogger(PayMethod.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(PayMethod.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(PayMethod.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(PayMethod.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new PayMethod().setVisible(true);
                
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JRadioButton BCredit;
    private javax.swing.JRadioButton BDebit;
    private javax.swing.JRadioButton BPaypal;
    private javax.swing.JLabel TicketCosttxt;
    private javax.swing.JLabel arstxt4;
    private javax.swing.JPanel background4;
    private javax.swing.ButtonGroup botones;
    private javax.swing.JLabel fondo4;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    // End of variables declaration//GEN-END:variables
}