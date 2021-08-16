#include <queue>
#include <limits>
#include <vector>

#include "simulation.h"
#include "simulation_log.h"
#include "event.h"
#include "customer.h"
#include "server.h"
#include "exponential_random_number.h"

Simulation::Simulation(int number_of_servers, double inter_arrival_time_mean, double service_time_mean, int number_of_customers)
{
    this->number_of_servers = number_of_servers;
    this->inter_arrival_time_mean = inter_arrival_time_mean;
    this->service_time_mean = service_time_mean;
    this->number_of_customers = number_of_customers;

    // Set up the random number generators
    this->inter_arrival_time_generator.SetMean(this->inter_arrival_time_mean);
    this->service_time_generator.SetMean(this->service_time_mean);
}

void Simulation::UpdateTime(double time) { this->clock = time; }

void Simulation::Initialize()
{
    // Set clock time to 0 and server status to Idle
    this->clock = 0;

    // Set all server status as idle
    for (int i = 0; i < this->number_of_servers; i++)
    {
        servers.push_back(Server());
    }

    // Schedule the first arrival event
    ArrivalEvent arrival_event(EventType::ARRIVAL, this->clock + this->inter_arrival_time_generator.GetRandomNumber());
    this->event_queue.push(&arrival_event);
}

void Simulation::Run()
{
    // Run simulation till event queue is empty
    while (!event_queue.empty())
    {
        // Fetch current event from the queue and update simulation clock
        Event *current_event = this->event_queue.top();
        this->event_queue.pop();
        UpdateTime(current_event->GetInvokeTime());

        // Handle the event
        if (current_event->GetType() == EventType::ARRIVAL)
        {
            std::cout << "Calling arrival" << std::endl;
            HandleArrival();
        }
        else if (current_event->GetType() == EventType::DEPARTURE)
        {
            HandleDeparture(current_event->GetTargetServer());
        }
    }
}

void Simulation::HandleArrival()
{
    // Create a new Customer with its arrival time
    Customer customer(this->clock);
    std::cout << "Hadnling arrival event" << std::endl;

    // Schedule next arrival event if customer limit is not crossed
    if (this->number_of_customers > Customer::GetTotalCustomers())
    {
        ArrivalEvent arrival_event(EventType::ARRIVAL, this->clock + this->inter_arrival_time_generator.GetRandomNumber());
        this->event_queue.push(&arrival_event);
    }

    // Find the availble server
    Server *available_server = this->GetAvailableServer();

    // If there are no server availble
    if (available_server == nullptr)
    {
        // Send customer to the queue
        this->service_queue.push(customer);

        // Log the arrival event
        CreateArrivalLog(customer);
    }
    // If a server is availble, send customer to service
    else
    {
        // Log the arrival event
        CreateArrivalLog(customer);

        // Send the customer to server
        this->currently_served_customer = customer;

        // Set server status to Busy
        available_server->SetServerStatus(ServerStatus::BUSY);

        // Schedule the departure event (end of service)
        DepartureEvent departure_event(EventType::DEPARTURE, this->clock + this->service_time_generator.GetRandomNumber(), available_server);
        this->event_queue.push(&departure_event);

        // Log the service event
        CreateServiceLog();
    }
}

void Simulation::HandleDeparture(Server *target_server)
{
    // Set server status to Idle
    target_server->SetServerStatus(ServerStatus::IDLE);

    // Log the departure event and empty the server
    CreateDepartureLog();

    // If there are customers in queue, decrease queue length and schedule service time
    if (!(this->service_queue.empty()))
    {
        // Fetch first customer from the queue and send him to server
        Customer customer = service_queue.front();
        this->currently_served_customer = customer;

        this->service_queue.pop();

        // Set server to busy state
        target_server->SetServerStatus(ServerStatus::BUSY);

        // Schedule the departure event (end of service)
        DepartureEvent departure_event(EventType::DEPARTURE, this->clock + this->service_time_generator.GetRandomNumber(), target_server);
        this->event_queue.push(&departure_event);

        // Log the service event
        CreateServiceLog();
    }
}

void Simulation::CreateArrivalLog(Customer customer)
{
    this->simulation_log.CreateEventRecord("Arrival", this->clock, customer.GetSerial(), this->service_queue.size());
}

void Simulation::CreateServiceLog()
{
    this->simulation_log.CreateEventRecord("Service", this->clock, currently_served_customer.GetSerial(), this->service_queue.size());
    currently_served_customer.SetServiceStartTime(this->clock);
}

void Simulation ::CreateDepartureLog()
{
    this->simulation_log.CreateEventRecord("Departure", this->clock, currently_served_customer.GetSerial(), this->service_queue.size());
    currently_served_customer.SetDepartureTime(this->clock);
    this->simulation_log.CreateCustomerRecord(currently_served_customer);
}

SimulationLog *Simulation::GetSimulationLog()
{
    return &(this->simulation_log);
}

Server *Simulation::GetAvailableServer()
{
    // Check the first available server
    for (Server server : this->servers)
        if (server.GetServerStatus() == ServerStatus::IDLE)
            return &server;

    // No server is available
    return nullptr;
}