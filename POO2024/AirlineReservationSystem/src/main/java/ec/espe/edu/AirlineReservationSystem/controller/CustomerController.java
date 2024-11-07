package ec.espe.edu.AirlineReservationSystem.controller;

import com.mongodb.ConnectionString;
import com.mongodb.MongoClientSettings;
import com.mongodb.MongoException;
import com.mongodb.ServerApi;
import com.mongodb.ServerApiVersion;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.model.Filters;
import ec.espe.edu.AirlineReservationSystem.model.Customer;
import org.bson.Document;
import org.bson.conversions.Bson;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;



/**
 *
 * @author Julio Blacio, Overnight Developers Squad, DCCO-ESPE
 */
public class CustomerController {

    private static final Logger logger = LogManager.getLogger(CustomerController.class);
    private static Properties properties = new Properties();

    static {
        try (InputStream input = CustomerController.class.getClassLoader().getResourceAsStream("config.properties")) {
            if (input == null) {
                throw new RuntimeException("Sorry, unable to find config.properties");
            }
            properties.load(input);
        } catch (IOException ex) {
            logger.error("IOException: ", ex);
            throw new RuntimeException("Failed to load configuration properties", ex);
        }
    }

    private static MongoClient createMongoClient() {
        String connectionString = properties.getProperty("mongo.connection.string");

        if (connectionString == null || connectionString.isEmpty()) {
            throw new IllegalArgumentException("MongoDB connection string is not set in the properties file");
        }

        ServerApi serverApi = ServerApi.builder()
                .version(ServerApiVersion.V1)
                .build();

        MongoClientSettings settings = MongoClientSettings.builder()
                .applyConnectionString(new ConnectionString(connectionString))
                .serverApi(serverApi)
                .build();

        return MongoClients.create(settings);
    }

    public static void createCustomer(Customer customer) {
        try (MongoClient mongoClient = createMongoClient()) {
            MongoDatabase database = mongoClient.getDatabase("CustomerDatabase");

            saveCustomerToDatabase(customer, database);

        } catch (Exception e) {
            logger.error("Error creating customer: ", e);
        }
    }

    private static void saveCustomerToDatabase(Customer customer, MongoDatabase database) {
        MongoCollection<Document> collection = database.getCollection("customers");

        Document customerDocument = new Document("id", customer.getIdDocument())
                .append("name", customer.getName())
                .append("email", customer.getEmail())
                .append("phoneNumber", customer.getPhoneNumber())
                .append("userName", customer.getUsername())
                .append("password", customer.getPassword())
                .append("city", customer.getCity())
                .append("state", customer.getState())
                .append("postalCode", customer.getPostalCode())
                .append("dateOfBirth", customer.getDateOfBirth())
                .append("gender", customer.getGender());

        try {
            collection.insertOne(customerDocument);
            logger.info("Customer saved successfully!");
        } catch (MongoException e) {
            logger.error("Error saving customer to database: ", e);
        }
    }

    public static boolean authenticateCustomer(String username, String password) {
        try (MongoClient mongoClient = createMongoClient()) {
            MongoDatabase database = mongoClient.getDatabase("CustomerDatabase");
            MongoCollection<Document> collection = database.getCollection("customers");

            Bson filter = Filters.and(
                    Filters.eq("userName", username),
                    Filters.eq("password", password)
            );

            Document customerDocument = collection.find(filter).first();

            return customerDocument != null;
        } catch (Exception e) {
            logger.error("Error authenticating customer: ", e);
            return false;
        }
    }
}
