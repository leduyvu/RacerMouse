#if !defined(_PACKAGE_H)
#define _PACKAGE_H

#include <string.h>
#include "Definition.h"
class Package {
private:
    int x;
    int y;
//    int dataLength;
    int messageCode;
    char data[50];
    int roomID;
public:
    Package();
    ~Package();
    int getRoomID();
    void setRoomID(int roomID);
    
    int getX();
    int getY();
    void setX();
    void setY();
    
    void setItemID();
    int getItemID();
    
//    int getDataLength();
//    void setDataLength(int dataLength);
    
    int getMessageCode();
    void setMessageCode(int messageCode);
    
    char* getData();
    void setData(const char* data);
    
    void createPackage(int dataLength, int messageCode, const char* data);
    
};

#endif  //_PACKAGE_H
