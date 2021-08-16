#ifndef SERVER_H
#define SERVER_H

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
    static int total_servers;

public:
    Server();

    ServerStatus GetServerStatus();
    void SetServerStatus(ServerStatus status);
};

#endif