package ec.espe.edu.AirlineReservationSystem.controller;

import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.MongoCursor;
import org.bson.Document;
import java.util.ArrayList;
import java.util.List;

public class OffersController {

    private MongoClient mongoClient;
    private MongoDatabase database;
    private MongoCollection<Document> offersCollection;

    public OffersController() {
        mongoClient = MongoClients.create("mongodb+srv://overnightdevelopersquad:Iq9R4i2czmCFcGBk@airlinedb.wbmwsfn.mongodb.net/");
        database = mongoClient.getDatabase("FlightDataBase");
        offersCollection = database.getCollection("offers");
    }

    public List<Document> getOffers() {
        List<Document> offersList = new ArrayList<>();
        try (MongoCursor<Document> cursor = offersCollection.find().iterator()) {
            while (cursor.hasNext()) {
                offersList.add(cursor.next());
            }
        }
        return offersList;
    }
}
