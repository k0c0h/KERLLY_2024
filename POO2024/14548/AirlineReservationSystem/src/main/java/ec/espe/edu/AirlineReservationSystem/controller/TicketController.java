/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ec.espe.edu.AirlineReservationSystem.controller;

import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.result.UpdateResult;
import ec.espe.edu.AirlineReservationSystem.model.Ticket;
import org.bson.Document;

import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

public class TicketController {

    private static final Logger logger = Logger.getLogger(TicketController.class.getName());

    private static final String DATABASE_NAME = "TicketDataBase";
    private static final String TICKET_COLLECTION = "tickets";
    private static final String COUNTER_COLLECTION = "counters";
    private static final String COUNTER_NAME = "ticketId";

    private MongoClient mongoClient;
    private MongoDatabase database;
    private MongoCollection<Document> ticketCollection;
    private MongoCollection<Document> counterCollection;

    public TicketController() {
        mongoClient = MongoClients.create("mongodb+srv://overnightdevelopersquad:Iq9R4i2czmCFcGBk@airlinedb.wbmwsfn.mongodb.net/");
        database = mongoClient.getDatabase(DATABASE_NAME);
        ticketCollection = database.getCollection(TICKET_COLLECTION);
        counterCollection = database.getCollection(COUNTER_COLLECTION);
    }

    private int getNextTicketId() {
        Document query = new Document("_id", COUNTER_NAME);
        Document update = new Document("$inc", new Document("seq", 1));

        Document result = counterCollection.findOneAndUpdate(query, update);
        if (result != null) {
            return result.getInteger("seq");
        } else {
            Document newCounter = new Document("_id", COUNTER_NAME).append("seq", 1);
            counterCollection.insertOne(newCounter);
            return 1;
        }
    }

    public String saveTicket(Ticket ticket) {
        try {
            int nextTicketId = getNextTicketId();
            ticket.setIdTicket(nextTicketId);

            Document ticketDoc = new Document("Number of Ticket", ticket.getTicketNumber())
                    .append("Ticket ID", ticket.getIdTicket())
                    .append("Customer Name", ticket.getCustomerName())
                    .append("Id Flight", ticket.getIdFlight())
                    .append("Ticket Class", ticket.getTicketClass());

            ticketCollection.insertOne(ticketDoc);
            return String.valueOf(ticket.getIdTicket());
        } catch (Exception e) {
            logger.log(Level.SEVERE, "Error al guardar el ticket", e);
            return null;
        }
    }

    public String findTicketById(int ticketId) {
        try {
            Document query = new Document("Ticket ID", ticketId);
            Document ticket = ticketCollection.find(query).first();

            if (ticket != null) {
                String customerName = ticket.getString("Customer Name");
                int flightId = ticket.getInteger("Id Flight");
                String ticketClass = ticket.getString("Ticket Class");

                return "<html>Cliente Encontrado <br><br>" +
                        "Nombre del Cliente: " + customerName +
                        "<br><br>ID del Vuelo: " + flightId +
                        "<br><br>Clase: " + ticketClass +
                        "<br><br>Por favor, estimado cliente, revise que sus datos sean correctos.</html>";
            } else {
                return "<html>No se encontró el ticket con ID: " + ticketId + "</html>";
            }
        } catch (Exception e) {
            logger.log(Level.SEVERE, "Error al buscar el ticket", e);
            return "<html>Error al buscar el ticket. Por favor, intente nuevamente.</html>";
        }
    }

    public void updateTicketWithBaggage(int ticketId, String baggageType, int baggageSize) {
        try {
            Document filter = new Document("Ticket ID", ticketId);

            int nextBaggageId = getNextBaggage(ticketId);
            String baggageId = "Equipaje " + nextBaggageId;

            Document newBaggage = new Document("Baggage ID", baggageId)
                    .append("Baggage Type", baggageType)
                    .append("Baggage Size", baggageSize);

            Document update = new Document("$push", new Document("Equipaje", newBaggage));

            ticketCollection.updateOne(filter, update);
        } catch (Exception e) {
            logger.log(Level.SEVERE, "Error al actualizar el equipaje del ticket", e);
        }
    }

    public int getNextBaggage(int ticketId) {
        try {
            Document filter = new Document("Ticket ID", ticketId);
            Document ticket = ticketCollection.find(filter).first();

            if (ticket != null) {
                List<Document> baggages = (List<Document>) ticket.get("Equipaje");
                if (baggages != null) {
                    return baggages.size() + 1;
                }
            }
            return 1;
        } catch (Exception e) {
            logger.log(Level.SEVERE, "Error al obtener el siguiente ID de equipaje", e);
            return 1;
        }
    }

  public void removeBaggage(int ticketId, String baggageId) {
    try {
        // Filtrar por Ticket ID
        Document filter = new Document("Ticket ID", ticketId);
        
        // Actualizar para eliminar el equipaje con el Baggage ID proporcionado
        Document update = new Document("$pull", new Document("Equipaje", new Document("Baggage ID", baggageId)));

        // Ejecutar la actualización
        UpdateResult result = ticketCollection.updateOne(filter, update);

        // Verificar si se modificó algún documento
        if (result.getModifiedCount() > 0) {
            System.out.println("Equipaje eliminado exitosamente.");
        } else {
            System.out.println("No se encontró equipaje para eliminar.");
        }
    } catch (Exception e) {
        e.printStackTrace();
        JOptionPane.showMessageDialog(null, "Error al eliminar el equipaje: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
    }
}

    public int getBaggageCount(int ticketId) {
        try {
            Document filter = new Document("Ticket ID", ticketId);
            Document ticket = ticketCollection.find(filter).first();

            if (ticket != null) {
                List<Document> baggages = (List<Document>) ticket.get("Equipaje");
                return baggages != null ? baggages.size() : 0;
            }
            return 0;
        } catch (Exception e) {
            logger.log(Level.SEVERE, "Error al contar el equipaje", e);
            return 0;
        }
    }
    public Document findTicket(int ticketId) {
    MongoCollection<Document> ticketCollection = database.getCollection("tickets");
    Document filter = new Document("Ticket ID", ticketId);
    Document ticket = ticketCollection.find(filter).first();
    return ticket;
}
    
        public int calculateTicketCost(String ticketClass, int ticketNumber) {
        if (ticketClass == null || ticketClass.isEmpty()) {
            throw new IllegalArgumentException("La clase de ticket no puede ser nula o vacía.");
        }

        int ticketCost = 0;
        final int ECONOMY_COST = 120;
        final int BUSINESS_COST = 200;

        switch (ticketClass.toUpperCase()) {
            case "ECONOMY":
                ticketCost = ECONOMY_COST;
                break;
            case "BUSINESS":
                ticketCost = BUSINESS_COST;
                break;
            default:
                throw new IllegalArgumentException("Clase de ticket no válida");
        }

        return ticketCost * ticketNumber;
    }
}






