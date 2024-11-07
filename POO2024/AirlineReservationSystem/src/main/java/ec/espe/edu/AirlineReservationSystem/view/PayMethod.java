/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package ec.espe.edu.AirlineReservationSystem.view;

/**
 *
 * @author Joffre
 */
public class PayMethod extends javax.swing.JFrame {

    /**
     * Creates new form PayMethod
     */
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

        background4 = new javax.swing.JPanel();
        arstxt4 = new javax.swing.JLabel();
        fondo4 = new javax.swing.JLabel();
        IdTickettxt4 = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        ValidarBton = new javax.swing.JButton();
        Validaciontxt = new javax.swing.JLabel();

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

        IdTickettxt4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                IdTickettxt4ActionPerformed(evt);
            }
        });
        background4.add(IdTickettxt4, new org.netbeans.lib.awtextra.AbsoluteConstraints(170, 230, 130, 40));

        jLabel1.setFont(new java.awt.Font("Segoe UI Emoji", 1, 12)); // NOI18N
        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/tarjeta-de-credito.png"))); // NOI18N
        background4.add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(260, 50, 160, 150));

        jLabel2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/airline company icon .jpg"))); // NOI18N
        background4.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(480, 320, 150, 140));

        jLabel3.setFont(new java.awt.Font("Segoe UI Black", 1, 12)); // NOI18N
        jLabel3.setText("Ingrese el Ticket ID:");
        background4.add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 240, -1, -1));

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
        background4.add(jButton1, new org.netbeans.lib.awtextra.AbsoluteConstraints(180, 420, 90, -1));

        ValidarBton.setText("Validar");
        ValidarBton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ValidarBtonActionPerformed(evt);
            }
        });
        background4.add(ValidarBton, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 230, -1, -1));

        Validaciontxt.setFont(new java.awt.Font("Arial", 1, 12)); // NOI18N
        background4.add(Validaciontxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 210, 300, 170));

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

    private void IdTickettxt4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_IdTickettxt4ActionPerformed

    }//GEN-LAST:event_IdTickettxt4ActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
       
    }//GEN-LAST:event_jButton1ActionPerformed

    private void ValidarBtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ValidarBtonActionPerformed
      
    }//GEN-LAST:event_ValidarBtonActionPerformed

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
    private javax.swing.JTextField IdTickettxt;
    private javax.swing.JTextField IdTickettxt1;
    private javax.swing.JTextField IdTickettxt2;
    private javax.swing.JTextField IdTickettxt3;
    private javax.swing.JTextField IdTickettxt4;
    private javax.swing.JLabel Validaciontxt;
    private javax.swing.JButton ValidarBton;
    private javax.swing.JLabel arstxt;
    private javax.swing.JLabel arstxt1;
    private javax.swing.JLabel arstxt2;
    private javax.swing.JLabel arstxt3;
    private javax.swing.JLabel arstxt4;
    private javax.swing.JPanel background;
    private javax.swing.JPanel background1;
    private javax.swing.JPanel background2;
    private javax.swing.JPanel background3;
    private javax.swing.JPanel background4;
    private javax.swing.JLabel fondo;
    private javax.swing.JLabel fondo1;
    private javax.swing.JLabel fondo2;
    private javax.swing.JLabel fondo3;
    private javax.swing.JLabel fondo4;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    // End of variables declaration//GEN-END:variables
}