#include "Socket.h"
#include <stdio.h>

Socket *Socket::getSocket(int ip, int port)
{
    if (unique != NULL)
        return unique;
    else
    {
        unique = new Socket(ip, port);
        return unique;
    }
}

Socket *Socket::getSocket()
{
    return unique;
}

Socket::Socket(int ip, int port)
{
    IP = ip;
    portNumber = port;
}
