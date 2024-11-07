package ec.espe.edu.AirlineReservationSystem.model;

import java.util.Date;

/**
 *
 * @author Kerlly Chiriboga, ODS
 */
public class Flight {

    private String flightId;
    private String origin;
    private String destination;
    private String airline;
    private Date departureDate;
    private Date arrivalDate;

    public Flight(String flightId, String origin, String destination, String airline, Date departureDate, Date arrivalDate) {
        this.flightId = flightId;
        this.origin = origin;
        this.destination = destination;
        this.airline = airline;
        this.departureDate = departureDate;
        this.arrivalDate = arrivalDate;
    }

    public Flight() {
    }

    /**
     * @return the flightId
     */
    public String getFlightId() {
        return flightId;
    }

    /**
     * @param flightId the flightId to set
     */
    public void setFlightId(String flightId) {
        this.flightId = flightId;
    }

    /**
     * @return the origin
     */
    public String getOrigin() {
        return origin;
    }

    /**
     * @param origin the origin to set
     */
    public void setOrigin(String origin) {
        this.origin = origin;
    }

    /**
     * @return the destination
     */
    public String getDestination() {
        return destination;
    }

    /**
     * @param destination the destination to set
     */
    public void setDestination(String destination) {
        this.destination = destination;
    }

    /**
     * @return the airline
     */
    public String getAirline() {
        return airline;
    }

    /**
     * @param airline the airline to set
     */
    public void setAirline(String airline) {
        this.airline = airline;
    }

    /**
     * @return the departureDate
     */
    public Date getDepartureDate() {
        return departureDate;
    }

    /**
     * @param departureDate the departureDate to set
     */
    public void setDepartureDate(Date departureDate) {
        this.departureDate = departureDate;
    }

    /**
     * @return the arrivalDate
     */
    public Date getArrivalDate() {
        return arrivalDate;
    }

    /**
     * @param arrivalDate the arrivalDate to set
     */
    public void setArrivalDate(Date arrivalDate) {
        this.arrivalDate = arrivalDate;
    }

}
