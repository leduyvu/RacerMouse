#include "Client.h"
#include <math.h>

Client::Client(ClientSocket* clientSocket) {
  this->clientSocket = clientSocket;
}

//bool Client::LoggedIn(){
//  return isLoggedIn;
//}
//
//int checkValidString(char* str){
//  int len = strlen(str);
//  if(len == 0){
//    return -1;
//  }
//
///*
//  for(int i = 0; i < len ;i++){
//    if(!(isalnum(str[i]) || (str[i] == '_') ) ){
//      return 0;
//    }
//  }
//*/
//  return 1;
//}
//
//void Client::getUserInfo(char* username,char* password){
//  //get username
//  printf("Please enter your username:\n");
//  fgets(username,30,stdin);
//  for ( int i = 0; i < 30; i++ ){
//    if ( username[i] == '\n' ){
//      username[i] = '\0';
//      break;
//    }
//  } 
//	
//  //get password
//  strcpy(password, getpass("Please enter your password:\n"));
//}
//
//bool Client::checkUserInfo(char* username, char* password){
//  int t1 = checkValidString(username);
//  int t2 = checkValidString(password);
//  if(t1 == 0){
//    printf("Username contains invalid characters\n");
//  }
//  else if(t1 == -1){
//    printf("Username is NULL\n");
//  }
//  else if(t2 == 0){
//    printf("Password contains invalid characters\n");
//  }
//  else if(t2 == -1){
//    printf("Password is NULL\n");
//  }
//  else{
//    return 1;
//  }
//  return 0;
//}
//
//void Client::login() {
//  if(LoggedIn()){
//    printf("You have logged in!\n");
//    return;
//  }
//  //Get username and password
//  char username[30];
//  char password[30];
//  getUserInfo(username,password);
//  //Check username and password	
//  if(checkUserInfo(username,password) == 0){
//    return;
//  }
//  //create request package;
//  char userInfo[80];
//  strcpy(userInfo,username);
//  strcat(userInfo,":");
//  strcat(userInfo,password);
//  package.createPackage(0,Package::MESSAGE_CODE_LOGIN,userInfo);
//  //send request package to server
//  clientSocket->send(package);
//  //waiting for reply from server
//  clientSocket->recv(package);
//
//  if(package.getMessageCode() == Package::MESSAGE_CODE_FAIL){
//    printf("Username and Password Incorrect!\n");
//  }
//  else{
//    isLoggedIn = true;
//    printf("Login successful!\n");
//    strcpy(currentDir,package.getData());
//  }
//}
//
//bool Client::logout() {
//  if(!LoggedIn()){
//    printf("Please login first!\n");
//    return false;
//  }
//  //create request package;
//  package.createPackage(0,Package::MESSAGE_CODE_LOGOUT,NULL);
//  //send request to client
//  clientSocket->send(package);
//  //waiting for reply from server
//  clientSocket->recv(package);
//	
//  if(package.getMessageCode() == Package::MESSAGE_CODE_SUCCESS){
//    printf("Logout Success!\n");
//    return true;
//  }
//}
//
//
//void Client::reg(){
//  //Get username and password
//  char username[30];
//  char password[30];
//  getUserInfo(username,password);
//  //Check username and password	
//  if(checkUserInfo(username,password) == 0){
//    return;
//  }
//  //create request package;
//  char userInfo[80];
//  strcpy(userInfo,username);
//  strcat(userInfo,":");
//  strcat(userInfo,password);
//  package.createPackage(0,Package::MESSAGE_CODE_REGISTER,userInfo);
//  //send request package to server
//  clientSocket->send(package);
//  //waiting for reply from server
//  clientSocket->recv(package);
//    
//  if(package.getMessageCode() == Package::MESSAGE_CODE_FAIL){
//    printf("This username has been used! \n");
//  }
//  else{
//    printf("Register successful!\n");
//  }
//}
//
//char* Client::extractFileName(char* fullFilePath) {
//    return strrchr(fullFilePath, '/') + 1;
//}
//
//void Client::put() {
//  if(!LoggedIn()){
//    printf("Please login first!\n");
//    return;
//  }
//
//  int count = 0;
//  printf("put start\n");
//  if (inputtedCommand.checkPutSyntax() == false) {
//    printf("error : put syntax, not full file path\n");
//    return;
//  }
// 
//  if (ClientFile::checkFileExists(inputtedCommand.getParameter()) == false) {
//    printf("error : file not exist\n");
//    return;
//  }
//	printf("%s",inputtedCommand.getParameter());
//    
//  package.createPackage(0,Package::MESSAGE_CODE_PUT,extractFileName(inputtedCommand.getParameter()));
//  //send request package to server
//  clientSocket->send(package);
//  //waiting for reply from server to see if the file is locked
//  //clientSocket->recv(package);
//  
//  ClientFile cf(inputtedCommand.getParameter());
////	long filesize =sizeof(inputtedCommand.getParameter());
////	long f=0;
//  cf.openFileToRead();
//  package = cf.getNextPackage();
//
//  while (package.getDataLength() != 0) {
////while (f < filesize) {
//    ++count;
//	
//    clientSocket->send(package);
////    usleep(1);
//	package = cf.getNextPackage();
//	
//  }
//  cf.closeFile();
//  package.createPackage(0,Package::MESSAGE_CODE_PUT_END,NULL);
//  clientSocket->send(package);
//  printf("put end %d\n", count);
//  fflush(0);
//}
//
//void Client::ls() {
//  if(!isLoggedIn){
//    printf("Please login first!\n");
//    return;
//  }  
//  package.createPackage(0,Package::MESSAGE_CODE_LS,inputtedCommand.getParameter());
//  //send request package to server
//  clientSocket->send(package);
//  //waiting for reply from server
//  clientSocket->recv(package);
//  
//  while(package.getMessageCode()!=Package::MESSAGE_CODE_LS_END){
//    if(package.getMessageCode() == Package::MESSAGE_CODE_LS_REQUEST){
//      int len=package.getDataLength();    
//      SListItem *slistitem;
//      slistitem=(SListItem *)package.getData();     
//      printf("%s",slistitem->ListItemName); 
//      package.setMessageCode(Package::MESSAGE_CODE_LS_END);        
//    }    
//    clientSocket->recv(package);
//  }
//}
//
//void Client::cd() {
//  if(!LoggedIn()){
//    printf("Please login first!\n");
//    return;
//  }
//  package.createPackage(0,Package::MESSAGE_CODE_CD,inputtedCommand.getParameter());
//  //send request package to server
//  clientSocket->send(package);
//  //waiting for reply from server
//  clientSocket->recv(package);
//
//  if(package.getMessageCode() == Package::MESSAGE_CODE_FAIL){
//    printf("Fail!\n");
//  }
//  else{
//    printf("Success!\n");
//    strcpy(currentDir,package.getData());
//  }
//}
//
//void Client::createdir() {
//  if(!LoggedIn()){
//    printf("Please login first!\n");
//    return;
//  }
//  package.createPackage(0,Package::MESSAGE_CODE_MKDIR,inputtedCommand.getParameter());
//  //send request package to server
//  clientSocket->send(package);
//  //waiting for reply from server
//  clientSocket->recv(package);
//
//  if(package.getMessageCode() == Package::MESSAGE_CODE_FAIL){
//    printf("Fail!\n");
//  }
//  else{
//    printf("Success!\n");
//    //strcpy(currentDir,package.getData());
//  }
//}
//
//char* Client::readCommand() {
//  //get command
//  char temp[100] = {0};
//  fgets(temp,100,stdin);
//  // parse command
//  char *tmp;
//  char cmd[10];	//command
//  char para[100];	//parameter
//  if((tmp = strtok(temp," \n")) == NULL){
//    strcpy(cmd,"invalid");
//  }
//  else{
//    strcpy(cmd,tmp);
//  }
//
//  if((strcmp(cmd,"login") == 0) || (strcmp(cmd,"register") == 0) || (strcmp(cmd,"logout") == 0) || (strcmp(cmd,"quit") == 0)){
//    if((tmp = strtok(NULL,"\n")) != NULL){
//      printf("Invalid Command\n");
//      inputtedCommand.setCommandName("invalid");
//    }  
//    else{   
//      inputtedCommand.setCommandName(cmd);
//    }
//  }	
//  else if((strcmp(cmd,"cd") == 0) || (strcmp(cmd,"put") == 0)||(strcmp(cmd,"mkdir") == 0)){
//    if((tmp = strtok(NULL,"\n")) == NULL){
//      printf("Invalid Command\n");
//      inputtedCommand.setCommandName("invalid");
//    }  
//    else{   
//      strcpy(para,tmp);
//      inputtedCommand.setCommandName(cmd);
//      inputtedCommand.setParameter(para);
//    }
//  }
//  else if(strcmp(cmd,"ls") == 0){
//    if((tmp = strtok(NULL,"\n")) == NULL){
//      inputtedCommand.setCommandName(cmd);
//      inputtedCommand.setParameter("");
//    }  
//    else{      
//      strcpy(para,tmp);	
//      inputtedCommand.setCommandName(cmd);
//      inputtedCommand.setParameter(para);
//    }
//  } 
//  else{
//    printf("Invalid Command\n");
//    inputtedCommand.setCommandName("invalid");
//  }
//  return inputtedCommand.getCommandName();
//}



