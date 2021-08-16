#include "event.h"
#include "server.h"

Event::Event(EventType type, double invoke_time)
{
    this->type = type;
    this->invoke_time = invoke_time;
}

double Event::GetInvokeTime()
{
    return this->invoke_time;
}

EventType Event::GetType()
{
    return this->type;
}

Server *Event::GetTargetServer()
{
    Server server;
    return &server;
}

bool Compare::operator()(Event *a, Event *b)
{
    if (a->GetInvokeTime() > b->GetInvokeTime())
    {
        return true;
    }
    else
    {
        return false;
    }
}

ArrivalEvent::ArrivalEvent(EventType type, double invoke_time) : Event(type, invoke_time)
{
}

EventType ArrivalEvent::GetType()
{
    return EventType::ARRIVAL;
}

DepartureEvent::DepartureEvent(EventType type, double invoke_time, Server *target_server) : Event(type, invoke_time)
{
    this->target_server = target_server;
}

EventType DepartureEvent::GetType()
{
    return EventType::DEPARTURE;
}

Server *DepartureEvent::GetTargetServer()
{
    return this->target_server;
}
