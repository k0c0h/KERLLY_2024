package com.mycompany.calculatedistance.model;

/**
 *
 * @author Kerlly Chiriboga - ODS
 */

public class PhisicalParameters {

    private double speed;
    private double time;
    private double distance;

    public PhisicalParameters(double speed, double time, double distance) {
        this.speed = speed;
        this.time = time;
        this.distance = distance;
    }

    public double getSpeed() {
        return speed;
    }

    public void setSpeed(double speed) {
        this.speed = speed;
    }

    public double getTime() {
        return time;
    }

    public void setTime(double time) {
        this.time = time;
    }

    public double getDistance() {
        return distance;
    }

    public void setDistance(double distance) {
        this.distance = distance;
    }
  PhisicalParameters parameters = new PhisicalParameters(speed, time, distance);
  
}
