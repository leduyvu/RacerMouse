#if !defined(_CLIENT_H)
#define _CLIENT_H

#include "ClientSocket.h"
//#include "Command.h"
#include "Package.h"
//#include "ListItem.h"
//#include "ClientFile.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

class Client {
public:
  ClientSocket* clientSocket;
  Package package;
//  Command inputtedCommand;
//  bool isLoggedIn;
//  char currentDir[512];

  Client(ClientSocket* clientSocket);
//  bool LoggedIn();
//  bool checkUserInfo(char* username, char* password);
//  void getUserInfo(char* username, char* password);
//  void login();
//  bool logout();
//  void reg();
//  void put();
//  void ls();
//  void cd();
//  void createdir();
//  char* readCommand();
//  char* extractFileName(char* fullFilePath);
//	void event();
};

#endif  //_CLIENT_H
