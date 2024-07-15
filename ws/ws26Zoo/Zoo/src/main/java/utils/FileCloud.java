package utils;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.mongodb.MongoClient;
import com.mongodb.MongoClientURI;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import ec.edu.espe.zoo.model.Animal;
import javax.swing.text.Document;


/**
 *
 * @author Kerlly Chiriboga, ODS
 */
public class FileCloud {
    
    private static final String CONNECTION_STRING = "your_mongodb_connection_string";
    private static final String DATABASE_NAME = "your_database_name";
    private static final String COLLECTION_NAME = "your_collection_name";

    public static void saveAnimalToCloud(Animal animal) {
        try {
            // Convert the Animal object to JSON
            ObjectMapper mapper = new ObjectMapper();
            String json = mapper.writeValueAsString(animal);
            
            // Create a MongoDB client
            MongoClientURI uri = new MongoClientURI(CONNECTION_STRING);
            MongoClient mongoClient = new MongoClient(uri);
            
            // Get the database and collection
            MongoDatabase database = mongoClient.getDatabase(DATABASE_NAME);
            MongoCollection<org.bson.Document> collection = database.getCollection(COLLECTION_NAME);
            
            // Create a Document from the JSON
            Document doc = Document.parse(json);
            
            // Insert the document into the collection
            collection.insertOne((org.bson.Document) doc);
            
            // Close the MongoDB client
            mongoClient.close();
            
            System.out.println("Animal saved to cloud: " + json);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


