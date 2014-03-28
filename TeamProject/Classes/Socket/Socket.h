#if !defined(_SOCKET_H)
#define _SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include "Package.h"
using namespace std;
class Socket {
private:
    Package package;
    socklen_t len;
protected:
    struct sockaddr_in servaddr,cliaddr;
public:
    char addr[16];
    int port;
    int fd;
    Socket();
    Socket(const char* addr, int port);
    Socket(const int newfd);
    int send(const char* str);
    int recv(char str[]);
    int send(Package& package);
    int recv(Package& package);
    void close();
    char* getIpAddress();
    int getPort();
    
    Package getPackage();
    void setPackage(Package package);
};

struct roomThread{
    Socket* sock1;
    Socket* sock2;
    bool isPlaying = false;
    bool isFull = false;
    int countPlayer = 0;
};

#endif  //_SOCKET_H
