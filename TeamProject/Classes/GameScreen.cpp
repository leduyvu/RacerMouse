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
//    Character *charac = new Cat();
//    charac->create();
//    charac->addToMap(ccp(200, 200), this);
    
    initMap();
    meta = tiledMap->getMetaLayer();
    registerWithTouchDispatcher();
    return true;
}

void  GameScreen::initMap(){
    tiledMap = RMTiledMap::create();
    tiledMap->retain();
    this->addChild(tiledMap);
    
}

#pragma mark - handle touches

void GameScreen::registerWithTouchDispatcher() {
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool GameScreen::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event){
    return true;
}

void GameScreen::ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event){
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    touchLocation = this->convertToNodeSpace(touchLocation);
    
    CCPoint tileCoord = tiledMap->tileCoordForPosition(touchLocation);
    // test
    CCString *type = tiledMap->typeAtTileCoord(tileCoord);
    
//    CCLog("hang: %f, cot: %f", tileCoord.y, tileCoord.x);
//    int tileGid = tiledMap->getTiledMap()->layerNamed("Meta")->tileGIDAt(tileCoord);
//    CCLog("tileGid: %f", tileGid);
//    if (tileGid) {
//        CCDictionary *properties = tiledMap->getTiledMap()->propertiesForGID(tileGid);
//        if (properties) {
//            CCString *type = new CCString();
//            *type = *properties->valueForKey("type");
    if (type && (type->compare("-1") == 0)) {
        return;
    }
    
    if (type && type->compare("1") == 0) {
        meta->removeTileAt(tileCoord);
    }
//        }
//    }
//    
//    
}
