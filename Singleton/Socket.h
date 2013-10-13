#pragma once
class Socket
{
public :
    static Socket* getSocket(int ip, int port);
    static Socket* getSocket();
private:
    Socket(int ip, int port);
    static Socket *unique;
    int IP;
    int portNumber;
};
