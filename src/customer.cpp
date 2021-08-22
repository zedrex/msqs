#include "customer.h"

int Customer::total_customer = 0;

Customer::Customer() {}

Customer::Customer(double arrival_time)
{
    this->serial = ++(this->total_customer);
    this->arrival_time = arrival_time;
}

int Customer::GetSerial()
{
    return this->serial;
}

int Customer::GetTotalCustomers()
{
    return Customer::total_customer;
}

void Customer::SetServiceStartTime(double time)
{
    this->service_start_time = time;
}

void Customer::SetDepartureTime(double time)
{
    this->departure_time = time;
}

double Customer::GetArrivalTime()
{
    return this->arrival_time;
}

double Customer::GetServiceStartTime()
{
    return this->service_start_time;
}

double Customer::GetDepartureTime()
{
    return this->departure_time;
}

void Customer::SetServer(int server_index)
{
    this->server_index = server_index;
}

int Customer::GetServer()
{
    return this->server_index;
}
