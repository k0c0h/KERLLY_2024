/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ec.espe.edu.AirlineReservationSystem.controller;

import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import java.util.List;
import org.bson.Document;

/**
 *
 * @author Joffre
 */
public class BaggageController {
    private static int ticketId; 
    
    private static final String DATABASE_NAME = "TicketDataBase";
    private static final String TICKET_COLLECTION = "tickets";
    private static final String COUNTER_COLLECTION = "counters";
    private static final String COUNTER_NAME = "ticketId";
    
    private MongoClient mongoClient;
    private MongoDatabase database;
    private MongoCollection<Document> ticketCollection;
    private MongoCollection<Document> counterCollection;

public BaggageController(int ticketId) {
        this.ticketId = ticketId;
    }
   
    public static void setTicketId(int id) {
        ticketId = id;
    }

    
    public static int getTicketId() {
        return ticketId;
    }
}
    
  


