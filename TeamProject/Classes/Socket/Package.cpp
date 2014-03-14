#include "Package.h"

Package::Package(){
//  bzero(data, 512);
}

Package::~Package(){
}
//int Package::getDataLength() {
//  return dataLength;
//}

//void Package::setDataLength(int dataLength) {
//  this->dataLength = dataLength;
//}

int Package::getMessageCode() {
  return messageCode;
}

void Package::setMessageCode(int messageCode) {
  this->messageCode = messageCode;
}


char* Package::getData() {
  return data;
}

void Package::setData(const char* data) {
  if (data == NULL) {
    bzero(this->data, 512);
  }
  else {
    strncpy(this->data, data, 512);
  }
}

void Package::createPackage(int dataLength, int messageCode, const char* data){
// setDataLength(dataLength);
 setMessageCode(messageCode);
// setData(data);
}

int Package::getRoomID(){
    return this->roomID;
}

void Package::setRoomID(int roomID){
    this->roomID = roomID;
}
