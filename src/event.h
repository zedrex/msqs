#ifndef EVENT_TYPE_H
#define EVENT_TYPE_H

#include "server.h"

enum class EventType
{
    ARRIVAL,
    DEPARTURE
};

class Event
{
protected:
    // Enumerator class for Event Types (ARRIVAL | DEPARTURE)
    EventType type;

    // Time of happening for this event
    double invoke_time;

public:
    // Event constructor from event type and invoke time
    Event(EventType type, double invoke_time);

    // Returns event invoke time
    double GetInvokeTime();

    // Returns event type as enum class EventType
    virtual EventType GetType() = 0;

    // Temporary cirutal function to invoke child class functions
    virtual Server *GetTargetServer();
};

class ArrivalEvent : public Event
{
protected:
public:
    ArrivalEvent(EventType type, double invoke_time);
    EventType GetType() override;
};

class DepartureEvent : public Event
{
protected:
    // Target server
    Server *target_server;

public:
    DepartureEvent(EventType type, double invoke_time, Server *target_server);
    EventType GetType() override;
    Server *GetTargetServer() override;
};

// Sorts Event objects based on invoke time (ascending)
class Compare
{
public:
    bool operator()(Event *a, Event *b);
};

#endif