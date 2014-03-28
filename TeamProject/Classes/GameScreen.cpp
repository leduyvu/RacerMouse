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
//    package = new Package();
//    package->createPackage(50, 401, "...");
//    package->setData("sssssss");
//    char addr[200]="192.168.1.154";
//    int port=12345;
//    clientSock = new ClientSocket(addr, port);
//    client = new Client(clientSock);
//    clientSock->connect();
    
    //test Win
    isSlow = false;
    countKey = 100;
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
    
    arrItems = new CCArray();
    arrPlayers = new CCArray();
    player = new Player();
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
    intKey();
    
    this->schedule(schedule_selector(GameScreen::autoPlay), VELOCITY_PLAYER);
    this->schedule(schedule_selector(GameScreen::autoCharactersPlay), VELOCITY_NORMAL);
//Item create:
    for (int i = 1; i <= 9; i ++) {
        ItemObject* item = new ItemObject();
        item->create(i);
        if(i <= 5 && i > 0)
            item->addToMap(ccp(4, i * 3), this, tiledMap);
        else{
        }
//            item->addToMap(ccp(4, i * 3), this, tiledMap);
        arrItems->addObject(item);
    }
    this->schedule(schedule_selector(GameScreen::autoImpactItem), VELOCITY_PLAYER);
    initItemView();
    return true;
}

void  GameScreen::initMap(){
    tiledMap = RMTiledMap::create();
    tiledMap->retain();
    tiledMap->setPosition(ccp((size.width -  tiledMap->getTiledMap()->getMapSize().width * tiledMap->getTiledMap()->getTileSize().width)/2,size.height - tiledMap->getTiledMap()->getMapSize().height * tiledMap->getTiledMap()->getTileSize().height));
    this->addChild(tiledMap);
}
#pragma mark - update
void GameScreen::update(float dt) {
}
#pragma mark - handle touches

void GameScreen::registerWithTouchDispatcher(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool GameScreen::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event){
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    touchLocation = this->convertToNodeSpace(touchLocation);
    if(touchLocation.y <= size.height - tiledMap->getTiledMap()->getMapSize().height * tiledMap->getTiledMap()->getTileSize().height){
        return true;
    }
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
//    CCPoint tileCoord = tiledMap->tileCoordForPosition(touchLocation);
}

void GameScreen::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
//    CCPoint touchLocation = pTouch->getLocationInView();
//    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
//    touchLocation = this->convertToNodeSpace(touchLocation);
//    CCRect* touchRect = CCRect(touchLocation.x, <#float y#>, <#float width#>, <#float height#>)
}

void GameScreen::autoCharactersPlay(){
    if (isSlow) {
        timeSlow++;
    }
    else{
        timeSlow = 0;
    }
    if(timeSlow >= 50){
        normalCharacters();
        timeSlow = 0;
        isSlow = false;
        return;
    }
    
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
}

void GameScreen::autoPlay(){
    //player
    CCObject* objPlayer;
    CCARRAY_FOREACH(arrPlayers, objPlayer){
        Character* player = dynamic_cast<Character*>(objPlayer);
        eatKey(player);
        if(player->getRunValue() == 1){
            if(player->checkRight(tiledMap, player->getPosition())){
                player->moveRight(tiledMap);
//                eatKey(player);
            }
            else{
                switch (player->getRunCurrent()) {
                    case 1:
                        player->moveRight(tiledMap);
//                        eatKey(player);
                        break;
                    case 2:
                        player->moveLeft(tiledMap);
//                        eatKey(player);
                        break;
                    case 3:
                        player->moveUpward(tiledMap);
//                        eatKey(player);
                        break;
                    case 4:
                        player->moveBelow(tiledMap);
//                        eatKey(player);
                        break;
                    default:
                        break;
                }
            }
        }
        else if(player->getRunValue() == 2){
            if(player->checkLeft(tiledMap, player->getPosition())){
                player->moveLeft(tiledMap);
//                eatKey(player);
            }
            else{
                switch (player->getRunCurrent()) {
                    case 1:
                        player->moveRight(tiledMap);
//                        eatKey(player);
                        break;
                    case 2:
                        player->moveLeft(tiledMap);
//                        eatKey(player);
                        break;
                    case 3:
                        player->moveUpward(tiledMap);
//                        eatKey(player);
                        break;
                    case 4:
                        player->moveBelow(tiledMap);
//                        eatKey(player);
                        break;
                    default:
                        break;
                }
            }
        }
        else if(player->getRunValue() == 3){
            if(player->checkUpward(tiledMap, player->getPosition())){
                player->moveUpward(tiledMap);
//                eatKey(player);
            }
            else{
                switch (player->getRunCurrent()) {
                    case 1:
//                        eatKey(player);
                        player->moveRight(tiledMap);
                        break;
                    case 2:
                        player->moveLeft(tiledMap);
//                        eatKey(player);
                        break;
                    case 3:
                        player->moveUpward(tiledMap);
//                        eatKey(player);
                        break;
                    case 4:
                        player->moveBelow(tiledMap);
//                        eatKey(player);
                        break;
                    default:
                        break;
                }
            }
        }
        else if(player->getRunValue() == 4){
            if(player->checkBelow(tiledMap, player->getPosition())){
                player->moveBelow(tiledMap);
//                eatKey(player);
            }
            else{
                switch (player->getRunCurrent()) {
                    case 1:
                        player->moveRight(tiledMap);
//                        eatKey(player);
                        break;
                    case 2:
                        player->moveLeft(tiledMap);
//                        eatKey(player);
                        break;
                    case 3:
                        player->moveUpward(tiledMap);
//                        eatKey(player);
                        break;
                    case 4:
                        player->moveBelow(tiledMap);
//                        eatKey(player);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}
#pragma mark - Items
GameScreen::~GameScreen(){
    delete arrCharacters;
    arrCharacters = NULL;    
    delete arrPlayers;
    arrPlayers = NULL;
    
    delete arrItems;
    arrItems = NULL;
    //du
    delete _arrItems;
    _arrItems = NULL;
    delete _arrItemsRemove;
    _arrItemsRemove = NULL;
    
    delete arrIsItems;
    arrIsItems = NULL;
    delete arrPosItems;
    arrPosItems = NULL;
}

void GameScreen::eatKey(Character* player){
    CCString *type = tiledMap->typeAtTileCoord(ccp(player->getPosition().x, player->getPosition().y));
    if (type && type->compare("1") == 0) {
        meta->removeTileAt(player->getPosition());
        countKey--;
        iScore += 2;
        std::string strScore = static_cast<ostringstream*>(&(ostringstream() << this->iScore))->str();
        lbScore->setString(strScore.c_str());
    }
    
    
//    if(countKey == 90){
//        player->transformation(4);
//        slowCharacters();
//    }
    
//    
//    if (type && type->compare("2") == 0) {
//        meta->removeTileAt(player->getPosition());
//        player->transformation(4);
//        slowCharacters();
//        timeSlow = 0;
//    }
}

void GameScreen::autoImpactItem(){
    impactWithPlayer(arrPlayers, arrItems);
}

void GameScreen::onMenu(CCObject *pSender) {
    CCDirector::sharedDirector()->pause();
    _pauseLayer->setVisible(true);
}

void GameScreen::onContinue(CCObject *pSender) {
    _pauseLayer->setVisible(false);
    CCDirector::sharedDirector()->resume();
}

void GameScreen::onRestart(CCObject *pSender) {
    CCDirector::sharedDirector()->resume();
    CCScene * scene = GameScreen::scene();
    CCDirector::sharedDirector()->replaceScene(scene);
}

void GameScreen::onQuit(CCObject *pSender) {
    CCDirector::sharedDirector()->resume();
    CCScene * scene = GameMenu::scene();
    CCDirector::sharedDirector()->replaceScene(scene);
}

void GameScreen::intKey(){
    CCMenuItemImage* itemRight = CCMenuItemImage::create("Key/right.png", "Key/right.png", this,
                            menu_selector(GameScreen::moveKey));
    CCMenuItemImage* itemLeft = CCMenuItemImage::create("Key/left.png", "Key/left.png", this,
                                                         menu_selector(GameScreen::moveKey));
    CCMenuItemImage* itemUp = CCMenuItemImage::create("Key/up.png", "Key/up.png", this,
                                                         menu_selector(GameScreen::moveKey));
    CCMenuItemImage* itemDown = CCMenuItemImage::create("Key/down.png", "Key/down.png", this,
                                                         menu_selector(GameScreen::moveKey));
    itemRight->setPosition(ccp(size.width * 13 /16 + itemRight->getContentSize().width , size.height* 1/8));
    itemLeft->setPosition(ccp(size.width * 13 /16 - itemLeft->getContentSize().width , size.height* 1/8));
    itemUp->setPosition(ccp(size.width * 13 /16, size.height* 1/8 + itemRight->getContentSize().width ));
    itemDown->setPosition(ccp(size.width * 13 /16, size.height* 1/8 - itemRight->getContentSize().width ));
    itemRight->setTag(2001);
    itemLeft->setTag(2002);
    itemUp->setTag(2003);
    itemDown->setTag(2004);

    CCMenu * menu = CCMenu::create(itemDown, itemUp, itemRight, itemLeft, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
}

void GameScreen::moveKey(CCNode* sender, void* data){
    if(sender->getTag() == 2001){
        player->setRunValue(1);
    }
    else if(sender->getTag() == 2002){
        player->setRunValue(2);
    }
    else if(sender->getTag() == 2003){
        player->setRunValue(3);
    }
    else if(sender->getTag() == 2004){
        player->setRunValue(4);
    }
}

void GameScreen::initItemView(){
    CCSprite * score = CCSprite::create("score.png");
    //    score->setRotation(90);
    score->setPosition(ccp(score->getContentSize().width/2 +  size.width/32 , size.height - SIZE_COMPONENT * HEIGHT - score->getContentSize().height/2 - ALIGN));
    this->addChild(score);
    std::string strScore = static_cast<ostringstream*>(&(ostringstream() << this->iScore))->str();

    lbScore = CCLabelTTF::create(strScore.c_str(), "Time New Roman", 35);
    lbScore->setColor(ccc3(225, 125, 255));
    lbScore->setPosition(ccp(score->getContentSize().width * 3/4, score->getContentSize().height *4/9));
    score->addChild(lbScore);
    
    CCMenuItemImage * pause =
    CCMenuItemImage::create("menu.png", "menu.png", this,
                            menu_selector(GameScreen::onMenu));
    pause->setPosition(ccp(score->getPosition().x + score->getContentSize().width /2 + pause->getContentSize().width/2 + ALIGN * 2, score->getPosition().y));
    pause->setScale(score->getContentSize().height / pause->getContentSize().height);
//    pause->setRotation(90);
    
    CCMenu * menu = CCMenu::create(pause, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    _pauseLayer = CCSprite::create("frame-dialog.png");
//    _pauseLayer->setAnchorPoint(ccp(0.5, 0.5));
    _pauseLayer->setPosition(ccp(size.width /2 , size.height * 7/ 12));
    this->addChild(_pauseLayer, ZORDER_CHARACTER + 1);
    CCMenuItemImage * continueItem =
    CCMenuItemImage::create("btn_continues.png","btn_continues_active.png", this,
                            menu_selector(GameScreen::onContinue));
    continueItem->
    setPosition(ccp(_pauseLayer->getContentSize().width/2, _pauseLayer->getContentSize().height * 3/4));
    continueItem->setScale(0.8);
    CCMenuItemImage * restartItem =
    CCMenuItemImage::create("btn_continues.png", "btn_continues_active.png", this,
                            menu_selector(GameScreen::onRestart));
    restartItem->
    setPosition(ccp(continueItem->getPosition().x, _pauseLayer->getContentSize().height/2));
    restartItem->setScale(0.8);
    CCMenuItemImage * quitItem =
    CCMenuItemImage::create("btn_backmain.png", "btn_backmain_active.png", this,
                            menu_selector(GameScreen::onQuit));
    quitItem->
    setPosition(ccp(continueItem->getPosition().x, _pauseLayer->getContentSize().height * 1/4));
    quitItem->setScale(0.8);
    CCMenu * pauseMenu = CCMenu::create(continueItem, restartItem, quitItem, NULL);
    pauseMenu->setPosition(ccp(0, 0));
    _pauseLayer->addChild(pauseMenu);
    _pauseLayer->setVisible(false);
    
    CCSprite * ice = CCSprite::create("btn_ice.png");
//    ice->setRotation(90);
    ice->setPosition(ccp(score->getPosition().x - score->getContentSize().width/2 + ice->getContentSize().width/2, score->getPosition().y - score->getContentSize().height/2 - ALIGN * 2 - ice->getContentSize().height/2));
    this->addChild(ice);
    
    _ice = CCSprite::create("btn_ice_active.png");
    _ice->setPosition(ice->getPosition());
//    _ice->setRotation(90);
    _ice->setVisible(false);
    this->addChild(_ice);
    
    
    CCSprite * invi = CCSprite::create("btn_invi.png");
//    invi->setRotation(90);
    invi->setPosition(ccp(ice->getPosition().x, ice->getPosition().y -  ice->getContentSize().height - ALIGN));
    this->addChild(invi);
    
    _invi = CCSprite::create("btn_invi_active.png");
//    _invi->setRotation(90);
    _invi->setPosition(invi->getPosition());
    _invi->setVisible(false);
    this->addChild(_invi);
    
    CCSprite * speed = CCSprite::create("btn_speed.png");
//    speed->setRotation(90);
    speed->setPosition(ccp(ice->getPosition().x + ALIGN + ice->getContentSize().width, ice->getPosition().y));
    this->addChild(speed);
    
    _speed = CCSprite::create("btn_speed_active.png");
//    _speed->setRotation(90);
    _speed->setPosition(speed->getPosition());
    _speed->setVisible(false);
    this->addChild(_speed);
    
    CCSprite * streng = CCSprite::create("btn_streng.png");
//    streng->setRotation(90);
    streng->setPosition(ccp(speed->getPosition().x, invi->getPosition().y));
    this->addChild(streng);
    
    _streng = CCSprite::create("btn_streng_active.png");
    _streng->setPosition(streng->getPosition());
//    _streng->setRotation(90);
    _streng->setVisible(false);
    this->addChild(_streng);
    
    
    CCSprite * item5 = CCSprite::create("btn_normal.png");
    item5->setPosition(ccp(streng->getPosition().x + item5->getContentSize().width + ALIGN , ice->getPosition().y));
    this->addChild(item5);
    
    CCSprite * item6 = CCSprite::create("btn_normal.png");
    item6->setPosition(ccp(item5->getPosition().x, invi->getPosition().y));
    this->addChild(item6);
    CCSprite * item7 = CCSprite::create("btn_normal.png");
    item7->setPosition(ccp(item5->getPosition().x + ice->getContentSize().width + ALIGN , ice->getPosition().y));
    this->addChild(item7);
    CCSprite * item8 = CCSprite::create("btn_normal.png");
    item8->setPosition(ccp(item7->getPosition().x, invi->getPosition().y));
    this->addChild(item8);
}

void GameScreen::autoCreateItem(){
    
    
}

void GameScreen::showGameOver(){
    CCSprite* sprGameOver = CCSprite::create("frame-dialog.png");
    sprGameOver->setPosition(ccp(size.width/2, size.height * 7/12));
    sprGameOver->setTag(GAMEOVER_TAG);
    this->addChild(sprGameOver, ZORDER_CHARACTER + 1);
    CCMenuItemImage * continueItem =
    CCMenuItemImage::create("btn_continues.png","btn_continues_active.png", this,
                            menu_selector(GameScreen::onContinue));
    continueItem->
    setPosition(ccp(_pauseLayer->getContentSize().width/2, _pauseLayer->getContentSize().height * 3/4));
    continueItem->setScale(0.8);
    CCMenuItemImage * restartItem =
    CCMenuItemImage::create("btn_continues.png", "btn_continues_active.png", this,
                            menu_selector(GameScreen::onRestart));
    restartItem->
    setPosition(ccp(continueItem->getPosition().x, _pauseLayer->getContentSize().height/2));
    restartItem->setScale(0.8);
    CCMenuItemImage * quitItem =
    CCMenuItemImage::create("btn_backmain.png", "btn_backmain_active.png", this,
                            menu_selector(GameScreen::onQuit));
    quitItem->
    setPosition(ccp(continueItem->getPosition().x, _pauseLayer->getContentSize().height * 1/4));
    quitItem->setScale(0.8);
    CCMenu * pauseMenu = CCMenu::create(continueItem, restartItem, quitItem, NULL);
    pauseMenu->setPosition(ccp(0, 0));
    sprGameOver->addChild(pauseMenu);
    
}

void GameScreen::initForItem(){
    arrIsItems = new CCArray();
    arrPosItems = new CCArray();
}
