#ifndef _GameManager_H_
#define _GameManager_H_

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;
class GameManager : public cocos2d::CCObject
{
private:
    bool bgm;
    string name;
    int level;
    string email;
    int point;
    string ipAddr;
    int reward;
    CC_SYNTHESIZE(float, _scaleSize, ScaleSize);
    CC_SYNTHESIZE(float, _timeAction, TimeAction);
    CC_SYNTHESIZE(int, _pointNow, PointNow);
    CC_SYNTHESIZE(int, _pointTotal, PointTotal);
    CC_SYNTHESIZE(int, _hit, Hit);
    CC_SYNTHESIZE(CCPoint, _positionHit, PositionHit);
    
    CC_SYNTHESIZE(int, _level, Level);
    CC_SYNTHESIZE(float, _SIZE_RATIO, SIZE_RATIO);
    CC_SYNTHESIZE(float, _SIZE_RATIO_X, SIZE_RATIO_X);
    CC_SYNTHESIZE(float, _SIZE_RATIO_Y, SIZE_RATIO_Y);
    CC_SYNTHESIZE(int, _platform, Platform);
    CC_SYNTHESIZE(bool, _sound, Sound);
    //Constructor
    GameManager();

    //Instance of the singleton
    static GameManager* m_mySingleton;

public:
    //Get instance of singleton
    static GameManager* sharedGameManager();
    bool getBgm();
    void setBgm(bool bgm);
    string getName();
    void setName(string name);
    string getEmail();
    void setEmail(string email);
    int getPoint();
    void setPoint(int point);
    string getIpAddr();
    void setIpAddr(string ipAddr);
    int getReward();
    void setReward(int reward);
};

#endif