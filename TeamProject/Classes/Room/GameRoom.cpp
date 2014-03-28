
#include "GameRoom.h"
#include <pthread.h>
CCScene* GameRoom::scene(Client* client){
    CCScene *scene = CCScene::create();
    GameRoom *layer = GameRoom::create(client);
    scene->addChild(layer);
    return scene;
}

GameRoom::GameRoom(){

}

GameRoom* GameRoom::create(Client* client){
    GameRoom* pRet = new GameRoom();
    if(pRet && pRet->init(client)){
        pRet->autorelease();
        return pRet;
    }
    else{
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool GameRoom::init(Client* client){
    if(client == NULL){
        connectServer();
    }
    else{
        this->client = client;
    }
    CCSize sizeScreen = CCDirector::sharedDirector()->getWinSize();
//    this->setTouchEnabled(true);
    
    //background
    CCSprite* spr_Bg = CCSprite::create("RoomScene/bg_room.png");
    spr_Bg->setScaleX(sizeScreen.width/spr_Bg->getContentSize().width);
    spr_Bg->setScaleY(sizeScreen.height/spr_Bg->getContentSize().height);
    spr_Bg->setPosition(ccp(sizeScreen.width/2, sizeScreen.height/2));
    this->addChild(spr_Bg);
    
    //buuton
    CCMenuItemImage *connectItem = CCMenuItemImage::create(
                                                           "RoomScene/frame_room.png",
                                                           "RoomScene/frame_room.png",
                                                           this,
                                                           menu_selector(GameRoom::connectRoom));
    connectItem->setPosition(spr_Bg->getPosition());
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(connectItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    return true;
}

GameRoom::~GameRoom(){
    this->removeAllChildrenWithCleanup(true);
}

void GameRoom::connectServer(){
    char addr[20]="192.168.1.220";
    int port= 8080;
    socket = new ClientSocket(addr, port);
    if(socket->connect() >= 0){
        CCLOG("connected....");
        client = new Client(socket);
    }
    else{
        client = new Client(socket);
        CCMessageBox("not connected", "please try agian !");
    }
}

void GameRoom::connectRoom(){
    try{
        puts("try connect room");
        if(client->connectRoom(1)){
            CCLOG("..........   client ID :  % d   ...............", client->getClientID());
            cocos2d::CCScene *newGameScene  = WaittingScene::scene(client);
            cocos2d::CCTransitionScene* transition = cocos2d::CCTransitionSlideInT::create(1, newGameScene);
            cocos2d::CCDirector::sharedDirector()->replaceScene(transition);
        }
    }catch(exception e){
        puts(e.what());
    }
}