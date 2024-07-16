package utils;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.mongodb.MongoClient;
import com.mongodb.MongoClientURI;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import ec.edu.espe.zoo.model.Animal;
import org.bson.Document;

/**
 *
 * @author Kerlly Chiriboga, ODS
 */
public class FileCloud {

    // Reemplaza estos valores con tu información de conexión
    private static final String CONNECTION_STRING = "mongodb+srv://kachiriboga:chiriboga@cluster0.mstbyy5.mongodb.net/";
    private static final String DATABASE_NAME = "ws26Zoo";
    private static final String COLLECTION_NAME = "Zoo";

    public static void saveAnimalToCloud(Animal animal) {
        try {
            // Convert the Animal object to JSON
            ObjectMapper mapper = new ObjectMapper();
            String json = mapper.writeValueAsString(animal);

            // Create a MongoDB client
            MongoClientURI uri = new MongoClientURI(CONNECTION_STRING);
            // Get the database and collection
            try (MongoClient mongoClient = new MongoClient(uri)) {
                // Get the database and collection
                MongoDatabase database = mongoClient.getDatabase(DATABASE_NAME);
                MongoCollection<Document> collection = database.getCollection(COLLECTION_NAME);
                // Create a Document from the JSON
                Document doc = createDocumentFromJson(json);
                // Insert the document into the collection
                collection.insertOne(doc);
                // Close the MongoDB client
            }

            System.out.println("Animal saved to cloud: " + json);
        } catch (JsonProcessingException e) {
            e.printStackTrace();
        }
    }

    private static Document createDocumentFromJson(String json) {
        return Document.parse(json);
    }
}


