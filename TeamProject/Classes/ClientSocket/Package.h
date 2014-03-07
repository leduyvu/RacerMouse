#if !defined(_PACKAGE_H)
#define _PACKAGE_H

#include <string.h>

class Package {
public:
static const int MESSAGE_CODE_LOGIN = 101;
static const int MESSAGE_CODE_LOGOUT = 102;
static const int MESSAGE_CODE_REGISTER = 103;

static const int MESSAGE_CODE_CONNECTROOM = 201;
static const int MESSAGE_CODE_EXITROOM = 202;

static const int MESSAGE_CODE_REALY = 301;
static const int MESSAGE_CODE_ENDGAME = 302;

static const int MESSAGE_CODE_MOVE = 401;
static const int MESSAGE_CODE_ITEM = 402;
    
static const int MESSAGE_CODE_QUIT = 501;

private:
    int x;
    int y;
//    int dataLength;
    int messageCode;
    char data[50];
public:
    Package();
    
    int getRoomID();
    void setRoomID();
    
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
