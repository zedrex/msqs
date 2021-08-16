#include "customer_record.h"
#include "customer.h"

CustomerRecord::CustomerRecord() {}

CustomerRecord::CustomerRecord(Customer customer)
{
    this->serial = customer.GetSerial();

    this->arrival_time = customer.GetArrivalTime();
    this->service_start_time = customer.GetServiceStartTime();
    this->departure_time = customer.GetDepartureTime();

    this->queue_delay_time = this->service_start_time - this->arrival_time;
    this->service_time = this->departure_time - this->service_start_time;
}
