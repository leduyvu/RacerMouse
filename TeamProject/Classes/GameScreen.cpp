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
    size = CCDirector::sharedDirector()->getWinSize();
    //init map
    initMap();
    meta = tiledMap->getMetaLayer();
    registerWithTouchDispatcher();
    
    player = new Player();
    player->create();
    player->setRunValue(1);
    player->addToMap(ccp(3, 4), this, tiledMap);
    
    _arrItems = new CCArray();
    _arrItemsRemove = new CCArray();
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

    this->drawListItem(CCPoint(size.width / 12, size.height - size.height/10));
    for (int i = 1; i <= 9; i ++) {
        this->addItem(i, CCPoint(rand() % 20 + 1, rand() % 20 + 1));
    } 
    
    this->schedule(schedule_selector(GameScreen::autoPlay), 0.2);
    this->schedule(schedule_selector(GameScreen::update));
    return true;
}

void  GameScreen::initMap(){
    tiledMap = RMTiledMap::create();
    tiledMap->retain();
    this->addChild(tiledMap);
}
#pragma mark - update
void GameScreen::update(float dt) {
    CCObject *i;
    CCARRAY_FOREACH(_arrItems, i) {
        Item *item = (Item*)i;
        int kc1 = item->getContentSize().width/2 * item->getScale() +
        player->getSprite()->getContentSize().width/2 * player->getSprite()->getScale();
        int kc2 = ccpDistance(item->getPosition(), player->getSprite()->getPosition());
        if (kc2 <= kc1) {
            _arrItemsRemove->addObject(item);
            switch (item->getType()) {
                case 1://biến hình
                    
                    break;
                case 2://tàng hình
                    
                    break;
                case 3://tăng tốc
                    player->setVelocity(player->getVelocity() * 2);
                    break;
                case 4://xuyên tường
                    
                    break;
                case 5://đặt bẫy
                    
                    break;
                case 6://SlowSpeed
                    
                    break;
                case 7://đóng băng 
                    
                    break;
                case 8://bóng đèn
                    
                    break;
                case 9://xua đuổi
                    
                    break;
                default:
                    break;
            }
        }
    }
    
    CCObject *i1;
    CCARRAY_FOREACH(_arrItemsRemove, i1) {
        Item *item = (Item*)i1;
        this->removeItem(item);
    }
}
#pragma mark - handle touches

void GameScreen::registerWithTouchDispatcher(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool GameScreen::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event){
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    touchLocation = this->convertToNodeSpace(touchLocation);
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
//    int tileGid = tiledMap->getTiledMap()->layerNamed("Meta")->tileGIDAt(tileCoord);
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
#pragma mark - Items
void GameScreen::addItem(int typeItem, CCPoint position) {
    Item * item = new Item();
    item->setType(typeItem);
    char name[10] = {};
    sprintf(name, "ball%i.png", typeItem);
    item->initWithFile(name);
    item->addToMap(position, this, tiledMap);
    _arrItems->addObject(item);
    item->setScale(0.3f);

    CCSprite *spItem = (CCSprite*)this->getChildByTag(1000 + typeItem);
    spItem->setOpacity(255);
}
void GameScreen::drawListItem(cocos2d::CCPoint p) {
    for (int i = 1; i <= 9; i ++) {
        char name[10] = {};
        sprintf(name, "ball%i.png", i);
        CCSprite *item = CCSprite::create(name);
        item->setScale(0.5f);
        float h = item->getScale() * item->getContentSize().width;
        CCPoint position = CCPoint(p.x + (i - 1 + 0.5f) * h, p.y);
        item->setPosition(position);
        item->setTag(1000 + i);
        item->setOpacity(100);
        this->addChild(item);
    }
}
void GameScreen::removeItem(Item *item) {
    CCSprite *spItem = (CCSprite*)this->getChildByTag(1000 + item->getType());
    spItem->setOpacity(100);
    _arrItems->removeObject(item);
    this->removeChild(item, true);
}
GameScreen::~GameScreen(){
    delete arrCharacters;
    arrCharacters = NULL;
    player->release();
}