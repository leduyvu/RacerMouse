#include "Socket.h"
#include <iostream>
#include <string.h>
Socket::Socket(const char* addr, int port) {
    strcpy(this->addr, addr);
    this->port = port;
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(port);
    
    if (fd < 0) {
        printf("socket");
        exit(1);
    }
}

Socket::Socket(const int newfd) {
    fd = newfd;
}

Socket::Socket(){
}

int Socket::send(const char* str) {
    std::string strc(str);
    int nbytes = sendto(fd,str,strlen(str),0, (struct sockaddr *)&servaddr,sizeof(servaddr));
    if (nbytes < 0) {
        perror("write");
        exit(1);
    }
    strc.clear();
    return nbytes;
}

int Socket::recv(char *str) {
    len = sizeof(cliaddr);
    int nbytes = recvfrom(fd,str,sizeof(char)*20, 0, (struct sockaddr *)&cliaddr, 0);
    if (nbytes < 0) {
        perror("read");
        exit(1);
    }
    return nbytes;
}

//int Socket::send(Package& package) {
//    int nbytes = ::sendto(fd, &package,sizeof(package),0,
//                          (struct sockaddr *)&servaddr,sizeof(servaddr));
//    if (nbytes < 0) {
//        perror("write");
//        exit(1);
//    }
//    return nbytes;
//}
//
//int Socket::recv(Package& package) {
//    len = sizeof(cliaddr);
//    int nbytes = ::recvfrom(fd,&package,sizeof(package), 0, (struct sockaddr *)&cliaddr,&len);
//    if (nbytes < 0) {
//        perror("read");
//        exit(1);
//    }
//    return nbytes;
//}

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

Package Socket::getPackage(){
    return this->package;
}

void Socket::setPackage(Package package){
    this->package = package;
}
