#include "server.h"

int Server::total_servers = 0;

Server::Server()
{
    this->status = ServerStatus::IDLE;
    this->id = ++total_servers;
}

ServerStatus Server::GetServerStatus()
{
    return this->status;
}

void Server::SetServerStatus(ServerStatus status)
{
    this->status = status;
}