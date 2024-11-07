/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ec.espe.edu.AirlineReservationSystem.controller;

import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.MongoCursor;
import com.mongodb.client.result.DeleteResult;
import com.mongodb.client.result.UpdateResult;
import org.bson.Document;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 *
 * @author Kerlly Chiriboga, ODS
 */

public class AdFlightsController {
    private MongoClient mongoClient;
    private MongoDatabase database;
    private MongoCollection<Document> flightsCollection;

    public AdFlightsController() {
        mongoClient = MongoClients.create("mongodb+srv://overnightdevelopersquad:Iq9R4i2czmCFcGBk@airlinedb.wbmwsfn.mongodb.net/");
        database = mongoClient.getDatabase("FlightDataBase"); 
        flightsCollection = database.getCollection("flights"); 
    }

    public List<Document> getFlights() {
        List<Document> flightsList = new ArrayList<>();
        try (MongoCursor<Document> cursor = flightsCollection.find().iterator()) {
            while (cursor.hasNext()) {
                Document flight = cursor.next();
                flightsList.add(flight);
            }
        }
        return flightsList;
    }
    
    public boolean updateFlight(String flightID, String newAirline, String newOrigin, String newDestination, Date newDepartureDate, Date newArrivalDate) {
        try {
            Document query = new Document("flightID", flightID);
            Document update = new Document("$set", new Document("airline", newAirline)
                .append("origin", newOrigin)
                .append("destination", newDestination)
                .append("departureDate", newDepartureDate)
                .append("arrivalDate", newArrivalDate));
                
            UpdateResult result = flightsCollection.updateOne(query, update);
            return result.getModifiedCount() > 0;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public boolean deleteFlight(String flightID) {
        try {
            Document query = new Document("flightID", flightID);
            DeleteResult result = flightsCollection.deleteOne(query);
            return result.getDeletedCount() > 0;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }
    
    public void close() {
        if (mongoClient != null) {
            mongoClient.close();
            System.out.println("Conexión a MongoDB cerrada.");
        }
    }
}
