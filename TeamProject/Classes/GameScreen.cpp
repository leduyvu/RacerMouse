//
//  GameScreen.cpp
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#include "GameScreen.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* GameScreen::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScreen *layer = GameScreen::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}
#pragma mark INIT
// on "init" you need to initialize your instance
bool GameScreen::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    //init
    Character *charac = new Cat();
    charac->create();
    charac->addToMap(ccp(200, 200), this);
    
    return true;
}

void  GameScreen::initMap(){
}