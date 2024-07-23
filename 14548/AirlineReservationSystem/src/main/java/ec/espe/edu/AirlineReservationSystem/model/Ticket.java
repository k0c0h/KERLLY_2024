/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ec.espe.edu.AirlineReservationSystem.model;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

/**
 *
 * @author Joffre
 */

public class Ticket {
   private static final String COUNTER_FILE = "ticket_counter.txt";
    private static int idCounter;
    private int idTicket;
    private int ticketNumber;
    private String customerName;
    private int idFlight;
    private String ticketClass;

    static {
        try {
            Path path = Paths.get(COUNTER_FILE);
            if (Files.exists(path)) {
                try (BufferedReader reader = new BufferedReader(new FileReader(COUNTER_FILE))) {
                    idCounter = Integer.parseInt(reader.readLine());
                }
            } else {
                idCounter = 1;
            }
        } catch (IOException e) {
            e.printStackTrace();
            idCounter = 1; // Si hay un error, reinicia el contador
        }
    }

    public Ticket(int ticketNumber, String customerName, int idFlight, String ticketClass) {
        this.idTicket = idCounter++;
        this.ticketNumber = ticketNumber;
        this.customerName = customerName;
        this.idFlight = idFlight;
        this.ticketClass = ticketClass;
        saveCounter(); // Guarda el nuevo contador en el archivo
    }

    private void saveCounter() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(COUNTER_FILE))) {
            writer.write(Integer.toString(idCounter));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Métodos getter y setter
    public int getIdTicket() {
        return idTicket;
    }

    public void setIdTicket(int idTicket) {
        this.idTicket = idTicket;
    }

    public int getTicketNumber() {
        return ticketNumber;
    }

    public void setTicketNumber(int ticketNumber) {
        this.ticketNumber = ticketNumber;
    }

    public String getCustomerName() {
        return customerName;
    }

    public void setCustomerName(String customerName) {
        this.customerName = customerName;
    }

    public int getIdFlight() {
        return idFlight;
    }

    public void setIdFlight(int idFlight) {
        this.idFlight = idFlight;
    }

    public String getTicketClass() {
        return ticketClass;
    }

    public void setTicketClass(String ticketClass) {
        this.ticketClass = ticketClass;
    }
}
