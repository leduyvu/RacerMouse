#include "Socket.h"

Socket::Socket(const char* addr, int port) {
  strcpy(this->addr, addr);
  this->port = port;
  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0) {
    printf("socket");
    exit(1);
  }
}

Socket::Socket(const int newfd) {
  fd = newfd;
}

int Socket::send(Package& package) {
  int nbytes = ::send(fd, &package, sizeof(package), 0);
  if (nbytes < 0) {
    perror("write");
    exit(1);
  }
  return nbytes;
}

int Socket::recv(Package& package) {
  int nbytes = ::recv(fd, &package, sizeof(package), 0);
  if (nbytes < 0) {
    perror("read");
    exit(1);
  }
  return nbytes;
}

void Socket::close() {
  ::close(fd);
}
char* Socket::getIpAddress(){
  struct sockaddr_in client;
  socklen_t len = sizeof(client);
  if(getpeername(fd ,(struct sockaddr*) &client,&len) < 0){
	perror("error");
  }
  return inet_ntoa(client.sin_addr);
}

int Socket::getPort(){
  struct sockaddr_in client;
  socklen_t len = sizeof(client);
  if(getpeername(fd ,(struct sockaddr*) &client,&len) < 0){
	perror("error");
  }
  return ntohs(client.sin_port);
}
