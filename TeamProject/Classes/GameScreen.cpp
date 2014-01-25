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
    srand (time(NULL));
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    //init map
    initMap();
    meta = tiledMap->getMetaLayer();
    registerWithTouchDispatcher();
    
    arrPlayers = new CCArray();
    Character* player = new Player();
    player->create();
    player->setRunValue(1);
    player->addToMap(ccp(3, 4), this, tiledMap);
    arrPlayers->addObject(player);
    
    arrCharacters = new CCArray;
    Character* cat;
    cat = new Cat();
    cat->create();
    cat->addToMap(ccp(5, 4), this, tiledMap);
    cat->setRunValue(1);
    arrCharacters->addObject(cat);
    
    Character* cat2;
    cat2 = new Cat();
    cat2->create();
    cat2->addToMap(ccp(9, 4), this, tiledMap);
    cat2->setRunValue(2);
    arrCharacters->addObject(cat2);
    
    Character* cat3;
    cat3 = new Cat();
    cat3->create();
    cat3->addToMap(ccp(9, 4), this, tiledMap);
    cat3->setRunValue(2);
    arrCharacters->addObject(cat3);

    this->schedule(schedule_selector(GameScreen::autoPlay), 0.2);
    
    return true;
}

void  GameScreen::initMap(){
    tiledMap = RMTiledMap::create();
    tiledMap->retain();
    this->addChild(tiledMap);
}

#pragma mark - handle touches

void GameScreen::registerWithTouchDispatcher(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool GameScreen::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event){
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    touchLocation = this->convertToNodeSpace(touchLocation);
    Character* player = dynamic_cast<Character*>(arrPlayers->objectAtIndex(0));
    if(fabs(touchLocation.x - player->getSprite()->getPosition().x) > fabs(touchLocation.y - player->getSprite()->getPosition().y)){
        if(touchLocation.x - player->getSprite()->getPosition().x > 0){
            player->setRunValue(1);
        }
        else{
            player->setRunValue(2);
        }
    }
    else{
        if(touchLocation.y - player->getSprite()->getPosition().y > 0){
            player->setRunValue(3);
        }
        else{
            player->setRunValue(4);
        }
    }
    
    return true;
}

void GameScreen::ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event){
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    touchLocation = this->convertToNodeSpace(touchLocation);
    
    CCPoint tileCoord = tiledMap->tileCoordForPosition(touchLocation);
    // test
//    CCString *type = tiledMap->typeAtTileCoord(tileCoord);
//    CCLog("hang: %f, cot: %f", tileCoord.y, tileCoord.x);
//    int tileGid = tiledMap->getTiledMap()->layerNamed("Tile Layer 1")->tileGIDAt(tileCoord);
//    CCLog("tileGid: %f", tileGid);
//    if (tileGid) {
//        CCDictionary *properties = tiledMap->getTiledMap()->propertiesForGID(tileGid);
//        if (properties) {
//            CCString *type = new CCString();
//            *type = *properties->valueForKey("type");
//    if (type && (type->compare("-1") == 0)) {
//        return;
//    }
//    
//    if (type && type->compare("1") == 0) {
//        meta->removeTileAt(tileCoord);
//    }
}

void GameScreen::autoPlay(){
    CCObject* obj;
    CCARRAY_FOREACH(arrCharacters, obj)
    {
        Character* cat =  dynamic_cast<Character*>(obj);
        cat->autoRun(tiledMap);
        CCObject* objPlayer;
        CCARRAY_FOREACH(arrPlayers, objPlayer){
            Character* player = dynamic_cast<Character*>(objPlayer);
            if(fabs(cat->getPosition().y - player->getPosition().y) <= 1 && fabs(cat->getPosition().x - player->getPosition().x) >= 4 ){
                if(cat->getPosition().x >=  player->getPosition().x && cat->getRunCurrent() != 1){
                    if(cat->checkLeft(tiledMap, cat->getPosition())){
                        cat->setRunValue(2);
                    }
                }
                if(cat->getPosition().x <=  player->getPosition().x && cat->getRunCurrent() != 2){
                    if(cat->checkRight(tiledMap, cat->getPosition())){
                        cat->setRunValue(1);
                    }
                }
            }
            if(fabs(cat->getPosition().x - player->getPosition().x) <= 1 && fabs(cat->getPosition().y - player->getPosition().y) >= 4){
                if(cat->getPosition().y <=  player->getPosition().y && cat->getRunCurrent() != 3){
                    if(cat->checkBelow(tiledMap, cat->getPosition())){
                        cat->setRunValue(4);
                    }
                }
                if(cat->getPosition().y >=  player->getPosition().y && cat->getRunCurrent() != 4){
                    if(cat->checkUpward(tiledMap, cat->getPosition())){
                        cat->setRunValue(3);
                    }
                }
            }
        }
        
        if(cat->getRunValue() == 1){
            if(cat->checkRight(tiledMap, cat->getPosition())){
                cat->moveRight(tiledMap);
            }
            else{
                switch (cat->getRunCurrent()) {
                    case 1:
                        cat->moveRight(tiledMap);
                        break;
                    case 2:
                        cat->moveLeft(tiledMap);
                        break;
                    case 3:
                        cat->moveUpward(tiledMap);
                        break;
                    case 4:
                        cat->moveBelow(tiledMap);
                        break;
                    default:
                        break;
                }
            }
        }
        else if(cat->getRunValue() == 2){
            if(cat->checkLeft(tiledMap, cat->getPosition())){
                cat->moveLeft(tiledMap);
            }
            else{
                switch (cat->getRunCurrent()) {
                    case 1:
                        cat->moveRight(tiledMap);
                        break;
                    case 2:
                        cat->moveLeft(tiledMap);
                        break;
                    case 3:
                        cat->moveUpward(tiledMap);
                        break;
                    case 4:
                        cat->moveBelow(tiledMap);
                        break;
                    default:
                        break;
                }
            }
        }
        else if(cat->getRunValue() == 3){
            if(cat->checkUpward(tiledMap, cat->getPosition())){
                cat->moveUpward(tiledMap);
            }
            else{
                switch (cat->getRunCurrent()) {
                    case 1:
                        cat->moveRight(tiledMap);
                        break;
                    case 2:
                        cat->moveLeft(tiledMap);
                        break;
                    case 3:
                        cat->moveUpward(tiledMap);
                        break;
                    case 4:
                        cat->moveBelow(tiledMap);
                        break;
                    default:
                        break;
                }
            }
        }
        else if(cat->getRunValue() == 4){
            if(cat->checkBelow(tiledMap, cat->getPosition())){
                cat->moveBelow(tiledMap);
            }
            else{
                switch (cat->getRunCurrent()) {
                    case 1:
                        cat->moveRight(tiledMap);
                        break;
                    case 2:
                        cat->moveLeft(tiledMap);
                        break;
                    case 3:
                        cat->moveUpward(tiledMap);
                        break;
                    case 4:
                        cat->moveBelow(tiledMap);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    //player
    CCObject* objPlayer;
    CCARRAY_FOREACH(arrPlayers, objPlayer){
        Character* player = dynamic_cast<Character*>(objPlayer);
        if(player->getRunValue() == 1){
            if(player->checkRight(tiledMap, player->getPosition())){
                player->moveRight(tiledMap);
            }
            else{
                switch (player->getRunCurrent()) {
                    case 1:
                        player->moveRight(tiledMap);
                        break;
                    case 2:
                        player->moveLeft(tiledMap);
                        break;
                    case 3:
                        player->moveUpward(tiledMap);
                        break;
                    case 4:
                        player->moveBelow(tiledMap);
                        break;
                    default:
                        break;
                }
            }
        }
        else if(player->getRunValue() == 2){
            if(player->checkLeft(tiledMap, player->getPosition())){
                player->moveLeft(tiledMap);
            }
            else{
                switch (player->getRunCurrent()) {
                    case 1:
                        player->moveRight(tiledMap);
                        break;
                    case 2:
                        player->moveLeft(tiledMap);
                        break;
                    case 3:
                        player->moveUpward(tiledMap);
                        break;
                    case 4:
                        player->moveBelow(tiledMap);
                        break;
                    default:
                        break;
                }
            }
        }
        else if(player->getRunValue() == 3){
            if(player->checkUpward(tiledMap, player->getPosition())){
                player->moveUpward(tiledMap);
            }
            else{
                switch (player->getRunCurrent()) {
                    case 1:
                        player->moveRight(tiledMap);
                        break;
                    case 2:
                        player->moveLeft(tiledMap);
                        break;
                    case 3:
                        player->moveUpward(tiledMap);
                        break;
                    case 4:
                        player->moveBelow(tiledMap);
                        break;
                    default:
                        break;
                }
            }
        }
        else if(player->getRunValue() == 4){
            if(player->checkBelow(tiledMap, player->getPosition())){
                player->moveBelow(tiledMap);
            }
            else{
                switch (player->getRunCurrent()) {
                    case 1:
                        player->moveRight(tiledMap);
                        break;
                    case 2:
                        player->moveLeft(tiledMap);
                        break;
                    case 3:
                        player->moveUpward(tiledMap);
                        break;
                    case 4:
                        player->moveBelow(tiledMap);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

GameScreen::~GameScreen(){
    delete arrCharacters;
    arrCharacters = NULL;
//    player->release();
    
    delete arrPlayers;
    arrPlayers = NULL;
}