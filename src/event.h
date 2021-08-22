#ifndef EVENT_TYPE_H
#define EVENT_TYPE_H

enum class EventType
{
    ARRIVAL,
    DEPARTURE
};

class Event
{
private:
    // Enumerator class for Event Types (ARRIVAL | DEPARTURE)
    EventType type;

    // Time of happening for this event
    double invoke_time;

    // Index of target server (-1 if not applicable)
    int target_server;

public:
    // Event constructor from event type and invoke time
    Event(EventType type, double invoke_time);

    // Event constructor from event type, taregt_server and invoke time
    Event(EventType type, double invoke_time, int target_server);

    // Returns event invoke time
    double GetInvokeTime();

    // Returns event type as enum class EventType
    EventType GetType();

    // Returns target server
    int GetTargetServer();
};

// Sorts Event objects based on invoke time (ascending)
class Compare
{
public:
    bool operator()(Event a, Event b);
};

#endif