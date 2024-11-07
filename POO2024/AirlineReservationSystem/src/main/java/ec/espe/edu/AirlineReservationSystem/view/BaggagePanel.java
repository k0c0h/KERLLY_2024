/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JPanel.java to edit this template
 */
package ec.espe.edu.AirlineReservationSystem.view;

import ec.espe.edu.AirlineReservationSystem.controller.BaggageController;
import ec.espe.edu.AirlineReservationSystem.controller.TicketController;
import ec.espe.edu.AirlineReservationSystem.model.Baggage;
import ec.espe.edu.AirlineReservationSystem.view.IdTicket;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Frame;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.SwingUtilities;
import javax.swing.border.EmptyBorder;
import org.bson.Document;

/**
 *
 * @author Joffre
 */
public class BaggagePanel extends javax.swing.JPanel {
private String baggageType;    

    /**
     * Creates new form BaggagePanel
     */
    public BaggagePanel() {
        initComponents();
        
    CheckedBton.setEnabled(false);
    CleanBaggageBton.setEnabled(false);
    CarryOnBton.setEnabled(false);
     ButtonManager.setButtons(CheckedBton, CleanBaggageBton, CarryOnBton);
    }
    
    public class ButtonManager {

    private static javax.swing.JButton checkedBton;
    private static javax.swing.JButton cleanBaggageBton;
    private static javax.swing.JButton carryOnBton;

    public static void setButtons(javax.swing.JButton checkedBton, javax.swing.JButton cleanBaggageBton, javax.swing.JButton carryOnBton) {
        ButtonManager.checkedBton = checkedBton;
        ButtonManager.cleanBaggageBton = cleanBaggageBton;
        ButtonManager.carryOnBton = carryOnBton;
    }

    public static void enableButtons(boolean enable) {
        if (checkedBton != null && cleanBaggageBton != null && carryOnBton != null) {
            checkedBton.setEnabled(enable);
            cleanBaggageBton.setEnabled(enable);
            carryOnBton.setEnabled(enable);
        }
    }
}
  private void mostrarPanelEliminacion() {
    JPanel panel = new JPanel();
    panel.setLayout(new GridBagLayout()); // Usar GridBagLayout para centrar elementos
    GridBagConstraints gbc = new GridBagConstraints();
    gbc.insets = new Insets(10, 10, 10, 10); // Espaciado entre los elementos
    gbc.anchor = GridBagConstraints.CENTER; // Centrar el contenido

    // Recuperar el ticketId
    int ticketId = BaggageController.getTicketId();

    // Crear una instancia del controlador
    TicketController controlador = new TicketController();
    
    // Recuperar el ticket
    Document ticket = controlador.findTicket(ticketId);

    if (ticket == null) {
        JOptionPane.showMessageDialog(null, "No se encontró el ticket con ID: " + ticketId, "Error", JOptionPane.ERROR_MESSAGE);
        return;
    }

    // Recuperar el equipaje del ticket
    List<Document> equipajes = (List<Document>) ticket.get("Equipaje");

    if (equipajes == null || equipajes.isEmpty()) {
        JOptionPane.showMessageDialog(null, "No se encontró equipaje para el ticket con ID: " + ticketId, "Información", JOptionPane.INFORMATION_MESSAGE);
        return;
    }

    // Crear los componentes dinámicamente
    int row = 0;
    for (Document equipaje : equipajes) {
        String baggageId = equipaje.getString("Baggage ID");
        String baggageType = equipaje.getString("Baggage Type");
        int baggageWeight = equipaje.getInteger("Baggage Size");

        JPanel itemPanel = new JPanel();
        itemPanel.setLayout(new BorderLayout());
        itemPanel.setBorder(BorderFactory.createEmptyBorder(5, 10, 5, 10)); // Espaciado alrededor del item
        itemPanel.setBackground(Color.WHITE); // Fondo blanco para el item

        JLabel etiquetaEquipaje = new JLabel(String.format("<html><b>%s</b><br>Tipo: %s<br>Peso: %d kg</html>", baggageId, baggageType, baggageWeight));
        etiquetaEquipaje.setFont(new Font("Arial", Font.BOLD, 14)); // Fuente en negrita y tamaño

        JButton botonEliminar = new JButton("Eliminar");
        botonEliminar.setFont(new Font("Arial", Font.BOLD, 10)); // Fuente en negrita y tamaño pequeño
        botonEliminar.setBackground(Color.RED); // Fondo rojo
        botonEliminar.setForeground(Color.WHITE); // Texto blanco
        botonEliminar.setOpaque(true); // Fondo visible
        botonEliminar.setPreferredSize(new Dimension(100, 25)); // Tamaño ajustado para un botón compacto

        itemPanel.add(etiquetaEquipaje, BorderLayout.CENTER);
        itemPanel.add(botonEliminar, BorderLayout.EAST);

        gbc.gridy = row;
        panel.add(itemPanel, gbc);
        row++;

        botonEliminar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                eliminarEquipaje(baggageId, (JDialog) SwingUtilities.getWindowAncestor(botonEliminar));
            }
        });
    }

    // Crear y mostrar el diálogo con el panel
    JDialog dialog = new JDialog((Frame) null, "Eliminar Equipaje", true);
    dialog.setLayout(new BorderLayout());
    dialog.add(new JScrollPane(panel), BorderLayout.CENTER); // Añadir scroll si es necesario
    dialog.setSize(500, 500); // Tamaño fijo
    dialog.setLocationRelativeTo(null); // Centrar el diálogo en la pantalla
    dialog.setVisible(true);
}
  
private void eliminarEquipaje(String baggageId, JDialog dialog) {
    int ticketId = BaggageController.getTicketId();
    TicketController controlador = new TicketController();
    controlador.removeBaggage(ticketId, baggageId);

    // Mostrar mensaje de confirmación
    JOptionPane.showMessageDialog(null, baggageId + " eliminado exitosamente.", "Confirmación", JOptionPane.INFORMATION_MESSAGE);

    // Cerrar el diálogo
    dialog.dispose();
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
        datePanel = new javax.swing.JPanel();
        Equipajetxt = new javax.swing.JLabel();
        Imagelogotxt = new javax.swing.JLabel();
        arstxt = new javax.swing.JLabel();
        fondoImage = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        OptionBaggagePanel = new javax.swing.JPanel();
        CarryOnBton = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        CheckedBton = new javax.swing.JButton();
        jLabel6 = new javax.swing.JLabel();
        CleanBaggageBton = new javax.swing.JButton();
        TicketBton = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();

        Background.setBackground(new java.awt.Color(255, 255, 255));

        datePanel.setBackground(new java.awt.Color(102, 0, 102));
        datePanel.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        Equipajetxt.setFont(new java.awt.Font("Trebuchet MS", 1, 36)); // NOI18N
        Equipajetxt.setForeground(new java.awt.Color(255, 255, 255));
        Equipajetxt.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Equipajetxt.setText("Añadir Equipaje");
        datePanel.add(Equipajetxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 10, -1, 78));

        Imagelogotxt.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/airline company icon .jpg"))); // NOI18N
        Imagelogotxt.setText("jLabel1");
        datePanel.add(Imagelogotxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(680, 0, 160, 120));

        arstxt.setFont(new java.awt.Font("Engravers MT", 0, 14)); // NOI18N
        arstxt.setForeground(new java.awt.Color(255, 255, 255));
        arstxt.setText("Airline Reservation System");
        datePanel.add(arstxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(390, 10, 300, 50));

        fondoImage.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/fondo.jpeg"))); // NOI18N
        datePanel.add(fondoImage, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 0, 930, 120));

        jLabel2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/fondo.jpeg"))); // NOI18N
        datePanel.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, 40, 110));

        OptionBaggagePanel.setBackground(new java.awt.Color(252, 245, 238));

        CarryOnBton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/equipaje-de-viaje.png"))); // NOI18N
        CarryOnBton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CarryOnBtonActionPerformed(evt);
            }
        });

        jLabel3.setFont(new java.awt.Font("Segoe UI Black", 1, 18)); // NOI18N
        jLabel3.setText("Añadir Equipaje");

        jLabel4.setFont(new java.awt.Font("Segoe UI Black", 1, 18)); // NOI18N
        jLabel4.setText("Eliminar Equipaje");

        jLabel5.setFont(new java.awt.Font("Segoe UI Black", 1, 12)); // NOI18N
        jLabel5.setText("Equipaje de Mano");

        CheckedBton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/facturar.png"))); // NOI18N
        CheckedBton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CheckedBtonActionPerformed(evt);
            }
        });

        jLabel6.setFont(new java.awt.Font("Segoe UI Black", 1, 12)); // NOI18N
        jLabel6.setText("Equipaje Facturado");

        CleanBaggageBton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/borrar.png"))); // NOI18N
        CleanBaggageBton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CleanBaggageBtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout OptionBaggagePanelLayout = new javax.swing.GroupLayout(OptionBaggagePanel);
        OptionBaggagePanel.setLayout(OptionBaggagePanelLayout);
        OptionBaggagePanelLayout.setHorizontalGroup(
            OptionBaggagePanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(OptionBaggagePanelLayout.createSequentialGroup()
                .addGap(68, 68, 68)
                .addComponent(jLabel5)
                .addGap(143, 143, 143)
                .addComponent(jLabel6)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, OptionBaggagePanelLayout.createSequentialGroup()
                .addGroup(OptionBaggagePanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(OptionBaggagePanelLayout.createSequentialGroup()
                        .addGap(193, 193, 193)
                        .addComponent(jLabel3))
                    .addGroup(OptionBaggagePanelLayout.createSequentialGroup()
                        .addGap(31, 31, 31)
                        .addComponent(CarryOnBton, javax.swing.GroupLayout.PREFERRED_SIZE, 181, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(84, 84, 84)
                        .addComponent(CheckedBton, javax.swing.GroupLayout.PREFERRED_SIZE, 168, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 135, Short.MAX_VALUE)
                .addGroup(OptionBaggagePanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(CleanBaggageBton, javax.swing.GroupLayout.PREFERRED_SIZE, 165, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 181, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(92, 92, 92))
        );
        OptionBaggagePanelLayout.setVerticalGroup(
            OptionBaggagePanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, OptionBaggagePanelLayout.createSequentialGroup()
                .addGap(34, 34, 34)
                .addGroup(OptionBaggagePanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(jLabel4))
                .addGap(27, 27, 27)
                .addGroup(OptionBaggagePanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(jLabel6))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(OptionBaggagePanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(CleanBaggageBton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(CheckedBton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(CarryOnBton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(44, Short.MAX_VALUE))
        );

        TicketBton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ec/edu/espe/airlinereservationsystem/images/ticket.png"))); // NOI18N
        TicketBton.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED));
        TicketBton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                TicketBtonActionPerformed(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("Segoe UI Black", 1, 14)); // NOI18N
        jLabel1.setText("Ingrese su ticket");

        javax.swing.GroupLayout BackgroundLayout = new javax.swing.GroupLayout(Background);
        Background.setLayout(BackgroundLayout);
        BackgroundLayout.setHorizontalGroup(
            BackgroundLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(BackgroundLayout.createSequentialGroup()
                .addGap(352, 352, 352)
                .addComponent(TicketBton, javax.swing.GroupLayout.PREFERRED_SIZE, 169, javax.swing.GroupLayout.PREFERRED_SIZE))
            .addGroup(BackgroundLayout.createSequentialGroup()
                .addGap(380, 380, 380)
                .addComponent(jLabel1))
            .addGroup(BackgroundLayout.createSequentialGroup()
                .addGap(46, 46, 46)
                .addComponent(OptionBaggagePanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
            .addComponent(datePanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
        BackgroundLayout.setVerticalGroup(
            BackgroundLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(BackgroundLayout.createSequentialGroup()
                .addComponent(datePanel, javax.swing.GroupLayout.PREFERRED_SIZE, 111, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(TicketBton, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(OptionBaggagePanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(35, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(Background, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(Background, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents

    private void TicketBtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_TicketBtonActionPerformed
    JFrame newFrame = new JFrame("Id Ticket");
    newFrame.setResizable(false);
    newFrame.setSize(700, 500);
    newFrame.setLocationRelativeTo(null);
    newFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    
    
    IdTicket idTicketPanel = new IdTicket();
    newFrame.add(idTicketPanel);
    
    
    
    newFrame.setVisible(true);

    }//GEN-LAST:event_TicketBtonActionPerformed

    private void CarryOnBtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CarryOnBtonActionPerformed

                                            
   String baggageType = "Carry On";
    
    
    TicketController controller = new TicketController();
    
    
    int ticketId = BaggageController.getTicketId();
    
   
    int baggageCount = controller.getBaggageCount(ticketId);
    
    if (baggageCount >= 2) {
        
        JOptionPane.showMessageDialog(this, 
            "No se pueden añadir más maletas. Ya se han añadido 2 maletas.", 
            "Límite Alcanzado", 
            JOptionPane.INFORMATION_MESSAGE);
        return;
    }
    
  
    JFrame newFrame = new JFrame("WeightBaggagePanel");
    newFrame.setResizable(false);
    newFrame.setSize(700, 500);
    newFrame.setLocationRelativeTo(null);
    newFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    
    
    WeigthBaggagePanel weightPanel = new WeigthBaggagePanel(baggageType);
    
  
    newFrame.add(weightPanel);
    
    
    newFrame.setVisible(true);


       
    
    }//GEN-LAST:event_CarryOnBtonActionPerformed

    private void CheckedBtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CheckedBtonActionPerformed
       
         String baggageType = "Checked";
    
    
    TicketController controller = new TicketController();
    
    
    int ticketId = BaggageController.getTicketId();
    
   
    int baggageCount = controller.getBaggageCount(ticketId);
    
    if (baggageCount >= 2) {
        
        JOptionPane.showMessageDialog(this, 
            "No se pueden añadir más maletas. Ya se han añadido 2 maletas.", 
            "Límite Alcanzado", 
            JOptionPane.INFORMATION_MESSAGE);
        return;
    }
    
  
    JFrame newFrame = new JFrame("WeightBaggagePanel");
    newFrame.setResizable(false);
    newFrame.setSize(700, 500);
    newFrame.setLocationRelativeTo(null);
    newFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    
    
    WeigthBaggagePanel weightPanel = new WeigthBaggagePanel(baggageType);
    
  
    newFrame.add(weightPanel);
    
    
    newFrame.setVisible(true);

    
    
    }//GEN-LAST:event_CheckedBtonActionPerformed

    private void CleanBaggageBtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CleanBaggageBtonActionPerformed
  
    mostrarPanelEliminacion();
        
    }//GEN-LAST:event_CleanBaggageBtonActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JPanel Background;
    private javax.swing.JButton CarryOnBton;
    private javax.swing.JButton CheckedBton;
    private javax.swing.JButton CleanBaggageBton;
    private javax.swing.JLabel Equipajetxt;
    private javax.swing.JLabel Imagelogotxt;
    private javax.swing.JPanel OptionBaggagePanel;
    private javax.swing.JButton TicketBton;
    private javax.swing.JLabel arstxt;
    private javax.swing.JPanel datePanel;
    private javax.swing.JLabel fondoImage;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    // End of variables declaration//GEN-END:variables
}
