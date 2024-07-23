package ec.espe.edu.AirlineReservationSystem.controller;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.model.FindOneAndUpdateOptions;
import com.mongodb.client.model.ReturnDocument;
import org.bson.Document;
import ec.espe.edu.AirlineReservationSystem.model.Flight;

/**
 *
 * @author Kerlly Chiriboga, ODS
 */


public class FlightController {

    private MongoClient mongoClient;
    private MongoDatabase database;
    private MongoCollection<Document> flightCollection;
    private MongoCollection<Document> countersCollection;

    public FlightController() {
        mongoClient = MongoClients.create("mongodb+srv://overnightdevelopersquad:Iq9R4i2czmCFcGBk@airlinedb.wbmwsfn.mongodb.net/");
        database = mongoClient.getDatabase("FlightDataBase");
        flightCollection = database.getCollection("flights");
        countersCollection = database.getCollection("counters");
    }

    public String saveFlight(Flight flight) {
        String flightId = getNextFlightId();

        Document flightDoc = new Document("flightID", flightId)
                .append("origin", flight.getOrigin())
                .append("destination", flight.getDestination())
                .append("airline", flight.getAirline())
                .append("departureDate", flight.getDepartureDate())
                .append("arrivalDate", flight.getArrivalDate());
        flightCollection.insertOne(flightDoc);

        flight.setFlightId(flightId);

        return flightId;
    }

    private String getNextFlightId() {
        Document filter = new Document("_id", "flightId");
        Document update = new Document("$inc", new Document("seq", 1));
        FindOneAndUpdateOptions options = new FindOneAndUpdateOptions().returnDocument(ReturnDocument.AFTER);

        Document result = countersCollection.findOneAndUpdate(filter, update, options);

        if (result == null) {
            countersCollection.insertOne(new Document("_id", "flightId").append("seq", 1));
            return "1";
        }

        return result.getInteger("seq").toString();
    }

    public void close() {
        if (mongoClient != null) {
            mongoClient.close();
            System.out.println("Conexión a MongoDB cerrada.");
        }
    }
}
