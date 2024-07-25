/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ec.edu.espe.calculatedistance.controller;

import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import javax.swing.text.Document;

/**
 *
 * @author G403
 */
public class DistanciaController {
     private final MongoClient mongoClient;
    private final MongoDatabase database;
    private final MongoCollection collection;

    public DistanciaController() {
        
        this.mongoClient = MongoClients.create("mongodb://localhost:27017");
        this.database = mongoClient.getDatabase("mydatabase");
        this.collection  = database.getCollection("distance");
        
        
    }

    public void guardarDistancia(double speed, double time, double distance) {
      
        Document document;
            .append("speed", speed)
            .append("time", time)
            .append("distance", distance);

        
        collection.insertOne(document);
    }
}
