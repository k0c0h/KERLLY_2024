package ec.espe.edu.AirlineReservationSystem.controller;

import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.MongoCursor;
import org.bson.Document;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 *
 * Author: Kerlly Chiriboga, ODS
 */
public class AdUsuariosController {

    private MongoClient mongoClient;
    private MongoDatabase database;
    private MongoCollection<Document> usuariosCollection;

    public AdUsuariosController() {
        mongoClient = MongoClients.create("mongodb+srv://overnightdevelopersquad:Iq9R4i2czmCFcGBk@airlinedb.wbmwsfn.mongodb.net/");
        database = mongoClient.getDatabase("CustomerDatabase");
        usuariosCollection = database.getCollection("customers");
    }

    public List<Document> getUsuarios() {
        List<Document> usuariosList = new ArrayList<>();
        try (MongoCursor<Document> cursor = usuariosCollection.find().iterator()) {
            while (cursor.hasNext()) {
                Document user = cursor.next();
                usuariosList.add(user);
            }
        }
        return usuariosList;
    }

    public boolean updateUser(String userId, String newName, String newEmail, String newPhoneNumber, String newCity, String newState, String newPostalCode, Date newDateOfBirth, String newGender) {
        try {
            Document query = new Document("id", userId);
            Document update = new Document("$set", new Document("name", newName)
                .append("email", newEmail)
                .append("phoneNumber", newPhoneNumber)
                .append("city", newCity)
                .append("state", newState)
                .append("postalCode", newPostalCode)
                .append("dateOfBirth", newDateOfBirth)
                .append("gender", newGender));

            usuariosCollection.updateOne(query, update);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public boolean deleteUser(String userId) {
        try {
            Document query = new Document("id", userId);
            usuariosCollection.deleteOne(query);
            return true;
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
