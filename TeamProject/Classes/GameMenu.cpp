//
//  GameMenu.cpp
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#include "GameMenu.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;
CCScene * GameMenu::scene() {
    CCScene * scene = CCScene::create();
    GameMenu * layer = GameMenu::create();
    scene->addChild(layer);
    return scene;
}

bool GameMenu::init() {
    if (!CCLayer::init()) {
        return false;
    }
    _size = CCDirector::sharedDirector()->getWinSize();
    _width = _size.width;
    _height = _size.height;
    _SIZE_RATIO = (_width + _height) / (640 + 960);
    _SIZE_RATIO_X = _width / 640;
    _SIZE_RATIO_Y = _height / 960;
    CCLOG("%f      %f", _width, _height);
    CCSprite * background = CCSprite::create("bg_maps.png");
    background->setAnchorPoint(ccp(0.5, 0.5));
    background->setPosition(ccp(_width / 2, _height / 2));
    background->setScaleX(_SIZE_RATIO_X);
    background->setScaleY(_SIZE_RATIO_Y);
    this->addChild(background);
    
    CCMenuItemImage * startButton =
    CCMenuItemImage::create("btn_continues.png", "btn_continues_active.png",
                            this, menu_selector(GameMenu::menuStart));
    startButton->setPosition(ccp(_width / 2, 3 * _height / 5));
    startButton->setScale(_SIZE_RATIO);
    
    CCMenuItemImage * quitButton =
    CCMenuItemImage::create("frame_room.png", "frame_room.png", this,
                            menu_selector(GameMenu::menuCloseCallback));
    quitButton->setPosition(ccp(_width / 2, _height / 5));
    quitButton->setScale(_SIZE_RATIO);

    CCMenuItemImage * rankButton =
    CCMenuItemImage::create("frame_room.png", "frame_room.png", this,
                            menu_selector(GameMenu::menuRank));
    rankButton->setPosition(ccp(_width / 2, 2 * _height / 5));
    rankButton->setScale(_SIZE_RATIO);

    CCMenu * pMenu = CCMenu::create(startButton, quitButton, rankButton, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu);
    return true;
}

void GameMenu::menuCloseCallback(CCObject * pSender){
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameMenu::menuStart(CCObject * pSender){
    CCScene * scene = GameScreen::scene();
    CCDirector::sharedDirector()->replaceScene(scene);
}

void GameMenu::menuRank(CCObject *pSender){
    CCScene * scene = RankingScene::scene();
    CCDirector::sharedDirector()->replaceScene(scene);
}
