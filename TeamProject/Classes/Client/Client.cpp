//
//  Client.cpp
//  TeamProject
//
//  Created by macbook_006 on 3/10/14.
//
//

#include "Client.h"
#include "GameScreen.h"
bool Client::login(){
    return true;//if login completed
}

bool Client::connectRoom(int roomID){
    package->createPackage(1, MESSAGE_CODE_CONNECTROOM, NULL);
    package->setRoomID(roomID);
    this->clientSocket->send(*package);
    //waiting reply from server
    clientSocket->recv(*package);
    if(package->getMessageCode() == (int)MESSAGE_CODE_FAIL){
        printf("Not connect to room because room full or network disconnect!\n");
        return false;
    }
    else if(package->getMessageCode() == (int)MESSAGE_CODE_CLIENT_ST || package->getMessageCode()== (int)MESSAGE_CODE_CLIENT_ND){
        printf("Connect successful!\n");
        if(package->getMessageCode() == (int)MESSAGE_CODE_CLIENT_ST){
            this->clientID = 1;
        }
        else{
            this->clientID = 2;
        }
        return true;
    }
    return false;
}

bool Client::quitRoom(){
    package->createPackage(1, MESSAGE_CODE_EXITROOM, NULL);
    clientSocket->send(*package);
    return true;//if quit completed
}

bool Client::exitGame(){
    return true; //if exits
}

Client::Client(ClientSocket* sock){
    this->clientSocket = sock;
    package = new Package();
}

Client::~Client(){
    delete package;
    clientSocket->close();
    delete clientSocket;
}

void Client::setSocket(ClientSocket* sock){
    this->clientSocket = sock;
}
ClientSocket* Client::getSocket(){
    return this->clientSocket;
}
