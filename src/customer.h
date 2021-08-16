#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
    // Arrival time by simulation clock
    double arrival_time;

    // Start time of service by simulation clock
    double service_start_time;

    // Departure time by simulation clock
    double departure_time;

    // Serial based on arrival time by simulation clock
    int serial;

    // Total number of customers for the simulation
    static int total_customer;

public:
    // Empty Constructor (to fix bugs)
    Customer();

    // Creates Customer object from arrival to system
    Customer(double arrival_time);

    // Returns the arrival serial of the customer
    int GetSerial();

    // Set service start time by the simulation clock
    void SetServiceStartTime(double time);

    // Set departure time from the system by the simulation clock
    void SetDepartureTime(double time);

    double GetArrivalTime();
    double GetServiceStartTime();
    double GetDepartureTime();

    // Returns the total number of customer so far (whole simulation)
    static int GetTotalCustomers();
};

#endif