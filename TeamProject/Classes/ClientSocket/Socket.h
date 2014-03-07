#if !defined(_SOCKET_H)
#define _SOCKET_H

#include "Package.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

class Socket {
public:
  char addr[16];
  int port;
  int fd;

  Socket(const char* addr, int port);
  Socket(const int newfd);
  int send(Package& package);
  int recv(Package& package);
  void close();
  char* getIpAddress();
  int getPort();
};

#endif  //_SOCKET_H
