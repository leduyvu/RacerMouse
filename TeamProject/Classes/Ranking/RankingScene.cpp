//
//  RankingScene.cpp
//  BallJumpping
//
//  Created by macbook_016 on 2013/12/24.
//
//

#include "RankingScene.h"
#include "SimpleAudioEngine.h"
#include "GameScreen.h"
using namespace cocos2d;
using namespace CocosDenshion;

CCScene * RankingScene::scene() {
    CCScene * scene = CCScene::create();
    RankingScene * layer = RankingScene::create();
    scene->addChild(layer);
    return scene;
}

bool RankingScene::init() {
    if (!CCLayer::init()) {
        return false;
    }
    size = CCDirector::sharedDirector()->getWinSize();
    SIZE_RATIO = GameManager::sharedGameManager()->getSIZE_RATIO();
    SIZE_RATIO_X = GameManager::sharedGameManager()->getSIZE_RATIO_X();
    SIZE_RATIO_Y = GameManager::sharedGameManager()->getSIZE_RATIO_Y();
    CCSprite * bg = CCSprite::create("HelloWorld.png");
    bg->setPosition(ccp(size.width / 2, size.height / 2));
    bg->setScaleX(SIZE_RATIO_X);
    bg->setScaleY(SIZE_RATIO_Y);
    this->addChild(bg);
    CCLOG("X: %f      Y: %f", SIZE_RATIO_X, SIZE_RATIO_Y);
    CCSprite * frame = CCSprite::create("frame_top.png");
    frame->setScaleX(SIZE_RATIO_X);
    frame->setScaleY(SIZE_RATIO_Y);
    frame->setPosition(ccp(size.width / 2, size.height / 2));
    this->addChild(frame);

    CCMenuItemImage * playItem =
    CCMenuItemImage::create("play.png", "play_active.png",this,
                            menu_selector(RankingScene::menuPlay));
    playItem->setScale(SIZE_RATIO * 0.6f);
    playItem->setPosition(ccp(130 * SIZE_RATIO_X, 565 * SIZE_RATIO_Y));

    CCMenuItemImage * quitItem =
    CCMenuItemImage::create("close.png", "close.png", this,
                            menu_selector(RankingScene::menuQuit));
    quitItem->setScale(SIZE_RATIO);
    quitItem->setPosition(ccp(830 * SIZE_RATIO_X, 565 * SIZE_RATIO_Y));

    CCMenu * pMenu = CCMenu::create(playItem, quitItem, NULL);
    pMenu->setPosition(ccp(0, 0));
    this->addChild(pMenu, 1);
    CCTableView* tableView =
    CCTableView::create(this, CCSizeMake(830 * SIZE_RATIO_X, 470 * SIZE_RATIO_Y));
	tableView->setDirection(kCCScrollViewDirectionVertical);
    tableView->setAnchorPoint(ccp(0.5, 0.5));
	tableView->setPosition(ccp(55 * SIZE_RATIO_X, 38 * SIZE_RATIO_Y));
	tableView->setDelegate(this);
	tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
	this->addChild(tableView);
	tableView->reloadData();

    return true;
}

void RankingScene::menuQuit(CCObject *pSender) {
    CCScene * scene = GameMenu::scene();
    CCDirector::sharedDirector()->replaceScene(scene);
}

void RankingScene::menuPlay(CCObject *pSender) {
    if (GameManager::sharedGameManager()->getSound()) {
        //SimpleAudioEngine::sharedEngine()->playEffect("button.wav");
    }
    CCScene * scene = GameScreen::scene();
    CCDirector::sharedDirector()->replaceScene(scene);
}

void RankingScene::tableCellTouched(CCTableView *table, CCTableViewCell *cell){
    CCLOG("%d", cell->getIdx());
    celltouch = cell->getIdx();
}

CCSize RankingScene::tableCellSizeForIndex(CCTableView *table, unsigned int idx) {
    return CCSizeMake(820 * SIZE_RATIO_X, 95 * SIZE_RATIO_Y);
}

CCTableViewCell * RankingScene::tableCellAtIndex(CCTableView *table, unsigned int idx) {
    CCTableViewCell * cell = new CCTableViewCell();
    CCSprite * frame1 = CCSprite::create("frame_player.png");
    frame1->setScaleX(SIZE_RATIO_X);
    frame1->setScaleY(SIZE_RATIO_Y);
    frame1->setPosition(ccp(820 * SIZE_RATIO_X / 2, 95 * SIZE_RATIO_Y / 2));
    cell->addChild(frame1);

    CCString * rank = CCString::createWithFormat("%d", idx + 1);
    CCLabelTTF * rankLabel =
    CCLabelTTF::create(rank->getCString(),"Time New Roman",50 * SIZE_RATIO);
    rankLabel->setAnchorPoint(ccp(1, 0.5f));
    rankLabel->setPosition(ccp(70 * SIZE_RATIO_X, 48 * SIZE_RATIO_Y));
    cell->addChild(rankLabel);

    CCString * strpoint = CCString::createWithFormat("high_score%d", idx + 1);
    int p = CCUserDefault::sharedUserDefault()->getIntegerForKey(strpoint->getCString());
    CCString * point = CCString::createWithFormat("%d", p);
    CCLabelTTF * pointLabel =
    CCLabelTTF::create(point->getCString(),"Time New Roman",50 * SIZE_RATIO);
    pointLabel->setPosition(ccp(800 * SIZE_RATIO_X, 48 * SIZE_RATIO_Y));
    pointLabel->setAnchorPoint(ccp(1, 0.5f));
    cell->addChild(pointLabel);
    
    CCString * strname = CCString::createWithFormat("name%d", idx + 1);
    string name = CCUserDefault::sharedUserDefault()->getStringForKey(strname->getCString());
    CCLabelTTF * nameLabel =
    CCLabelTTF::create(name.c_str(),"Time New Roman",50 * SIZE_RATIO);
    nameLabel->setAnchorPoint(ccp(0, 0.5));
    nameLabel->setPosition(ccp(150 * SIZE_RATIO_X, 48 * SIZE_RATIO_Y));
    cell->addChild(nameLabel);
    return cell;
}

unsigned int RankingScene::numberOfCellsInTableView(CCTableView *table) {
    return 10;
}

