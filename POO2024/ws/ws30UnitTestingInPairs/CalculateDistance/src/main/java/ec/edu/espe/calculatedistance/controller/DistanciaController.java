package ec.edu.espe.calculatedistance.controller;

import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;

/**
 *
 * @author Kerlly Chiriboga - ODS
 */

public class DistanciaController {
    private final MongoClient mongoClient;
    private final MongoDatabase database;
    private final MongoCollection<Document> collection;
    
    public DistanciaController() {
        this.mongoClient = MongoClients.create("mongodb+srv://kachiriboga:chiriboga@cluster0.mstbyy5.mongodb.net/");
        this.database = mongoClient.getDatabase("mydatabase");
        this.collection = database.getCollection("distance");
    }


    public void guardarDistancia(double speed, double time, double distance) {
        Document document = new Document()
            .append("speed", speed)
            .append("time", time)
            .append("distance", distance);
        collection.insertOne(document);
    }

    public void close() {
        mongoClient.close();
    }
}
