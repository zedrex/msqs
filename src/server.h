#ifndef SERVER_H
#define SERVER_H

#include "customer.h"

enum class ServerStatus
{
    IDLE,
    BUSY
};

class Server
{
private:
    ServerStatus status;
    int id;
    Customer current_customer;
    static int total_servers;

public:
    Server();

    ServerStatus GetServerStatus();
    void SetServerStatus(ServerStatus status);
    void SetCurrentCustomer(Customer customer);
    void DepartCurrentCustomer();
    Customer GetCurrentCustomer();
};

#endif