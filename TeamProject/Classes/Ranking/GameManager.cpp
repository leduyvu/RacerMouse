#include "GameManager.h" 

using namespace cocos2d;
//using namespace CocosDenshion;

//All static variables need to be defined in the .cpp file
//I've added this following line to fix the problem
GameManager* GameManager::m_mySingleton = NULL;

GameManager::GameManager()
{
    this->setIpAddr("192.168.1.122");
    this->setSound(true);
}

GameManager* GameManager::sharedGameManager()
{
    //If the singleton has no instance yet, create one
    if(NULL == m_mySingleton)
    {
        //Create an instance to the singleton
        m_mySingleton = new GameManager();
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        float SIZE_RATIO = (size.width + size.height) / (960 + 640);
        float SIZE_RATIO_X = size.width / 960;
        float SIZE_RATIO_Y = size.height / 640;
        GameManager::sharedGameManager()->setSIZE_RATIO(SIZE_RATIO);
        GameManager::sharedGameManager()->setSIZE_RATIO_X(SIZE_RATIO_X);
        GameManager::sharedGameManager()->setSIZE_RATIO_Y(SIZE_RATIO_Y);
        
        CCUserDefault::sharedUserDefault()->setIntegerForKey("high_score1", 11000);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("high_score2", 10000);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("high_score3", 9000);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("high_score4", 8000);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("high_score5", 7000);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("high_score6", 6000);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("high_score7", 5000);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("high_score8", 4000);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("high_score9", 3000);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("high_score10", 2000);
        
        CCUserDefault::sharedUserDefault()->setStringForKey("name1", "Teo");
        CCUserDefault::sharedUserDefault()->setStringForKey("name2", "Ti");
        CCUserDefault::sharedUserDefault()->setStringForKey("name3", "Tung");
        CCUserDefault::sharedUserDefault()->setStringForKey("name4", "Cao");
        CCUserDefault::sharedUserDefault()->setStringForKey("name5", "THang");
        CCUserDefault::sharedUserDefault()->setStringForKey("name6", "Tien");
        CCUserDefault::sharedUserDefault()->setStringForKey("name7", "Man");
        CCUserDefault::sharedUserDefault()->setStringForKey("name8", "Ngung");
        CCUserDefault::sharedUserDefault()->setStringForKey("name9", "Hung");
        CCUserDefault::sharedUserDefault()->setStringForKey("name10", "Mien");
    }
    
    //Return the singleton object
    return m_mySingleton;
}
void GameManager::setBgm(bool bgm)
{
    CCUserDefault::sharedUserDefault()->setBoolForKey("BGM", bgm);
    CCUserDefault::sharedUserDefault()->flush();
}
bool GameManager::getBgm()
{
    return CCUserDefault::sharedUserDefault()->getBoolForKey("BGM");
}
string GameManager::getName()
{
    return CCUserDefault::sharedUserDefault()->getStringForKey("PlayerName");
}
void GameManager::setName(string name)
{
    CCUserDefault::sharedUserDefault()->setStringForKey("PlayerName", name);
    CCUserDefault::sharedUserDefault()->flush();
}
string GameManager::getEmail()
{
    return CCUserDefault::sharedUserDefault()->getStringForKey("Email");
}
void GameManager::setEmail(string email)
{
    CCUserDefault::sharedUserDefault()->setStringForKey("Email", email);
    CCUserDefault::sharedUserDefault()->flush();
}


int GameManager::getPoint()
{
    return this->point;
}
void GameManager::setPoint(int point)
{
    this->point = point;
}
string GameManager::getIpAddr()
{
    return this->ipAddr;
}
void GameManager::setIpAddr(string ipAddr) {
    this->ipAddr = ipAddr;
}

int GameManager::getReward() {
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("Reward");
}

void GameManager::setReward(int reward) {
    CCUserDefault::sharedUserDefault()->setIntegerForKey("Reward", reward);
    CCUserDefault::sharedUserDefault()->flush();
}
