#include "event.h"

Event::Event(EventType type, double invoke_time)
{
    this->type = type;
    this->invoke_time = invoke_time;
    this->target_server = -1;
}

Event::Event(EventType type, double invoke_time, int target_server)
{
    this->type = type;
    this->invoke_time = invoke_time;
    this->target_server = target_server;
}

double Event::GetInvokeTime()
{
    return this->invoke_time;
}

EventType Event::GetType()
{
    return this->type;
}

int Event::GetTargetServer()
{
    return this->target_server;
}

bool Compare::operator()(Event a, Event b)
{
    if (a.GetInvokeTime() > b.GetInvokeTime())
    {
        return true;
    }
    else
    {
        return false;
    }
}