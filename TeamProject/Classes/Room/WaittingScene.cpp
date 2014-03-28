//
//  WaittingScene.cpp
//  TeamProject
//
//  Created by macbook_006 on 3/11/14.
//
//

#include "WaittingScene.h"
CCScene* WaittingScene::scene(Client* client){
    CCScene *scene = CCScene::create();
    WaittingScene *layer = WaittingScene::create(client);
    scene->addChild(layer);
    return scene;
}

WaittingScene* WaittingScene::create(Client* client){
    WaittingScene* pRet = new WaittingScene();
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

bool WaittingScene::init(Client* client){
    this->client = client;    
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
                                                           menu_selector(WaittingScene::ready));
    connectItem->setPosition(ccp(spr_Bg->getPositionX()/4, spr_Bg->getPositionY()/4));
    
    CCMenuItemImage *quitItem = CCMenuItemImage::create(
                                                           "RoomScene/frame_room.png",
                                                           "RoomScene/frame_room.png",
                                                           this,
                                                           menu_selector(WaittingScene::quitRoom));
    quitItem->setPosition(ccp(spr_Bg->getPositionX()*6/4, spr_Bg->getPositionY()/4));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(connectItem, quitItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    //Label
    CCLabelTTF* lbplayer = CCLabelTTF::create(".....", "Time New Roman", 64);
    lbplayer->setPosition(ccp(spr_Bg->getPositionX()/4, spr_Bg->getPositionY()/2));
    
    CCLabelTTF* lbEnemy = CCLabelTTF::create(".....", "Time New Roman", 64);
    lbEnemy->setPosition(ccp(spr_Bg->getPositionX() * 6/4, spr_Bg->getPositionY()/2));
    
    this->addChild(lbplayer, 1,10);
    this->addChild(lbEnemy,1,20);
    this->scheduleUpdate();
    return true;
}

//void WaittingScene::update(){
//    client->getSocket()->recv(*(client->getPackage()));
//    if(client->getPackage()->getMessageCode() == (int)MESSAGE_CODE_READY){
//        dynamic_cast<CCLabelTTF*>(this->getChildByTag(20))->setString("OK");
//        unscheduleUpdate();
//    }
//}
//destructor
WaittingScene::~WaittingScene(){
}

void WaittingScene::ready(){
    client->getPackage()->setMessageCode(MESSAGE_CODE_READY);
    client->getSocket()->send(*(client->getPackage()));
    dynamic_cast<CCLabelTTF*>(this->getChildByTag(10))->setString("OKK");

    client->getSocket()->recv(*(client->getPackage()));
    if(client->getPackage()->getMessageCode() == (int)MESSAGE_CODE_READY){
        dynamic_cast<CCLabelTTF*>(this->getChildByTag(20))->setString("OK");
    }
}

void WaittingScene::quitRoom(){
    client->getPackage()->setMessageCode(MESSAGE_CODE_EXITROOM);
    client->getSocket()->send(*(client->getPackage()));
    cocos2d::CCScene *newGameScene  = GameRoom::scene(client);
    cocos2d::CCTransitionScene* transition = cocos2d::CCTransitionSlideInT::create(1, newGameScene);
    cocos2d::CCDirector::sharedDirector()->replaceScene(transition);
    
}