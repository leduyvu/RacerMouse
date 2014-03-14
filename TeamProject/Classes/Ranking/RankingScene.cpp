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

int rankingWriter(char *data, size_t size, size_t nmemb, string *buffer)
{
    int result = 0;
    
    if (buffer != NULL)
    {
        //バッファ追記
        buffer->append(data, size * nmemb);
        result = size * nmemb;
    }
    
    return result;
}


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
    this->getRanking();
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
    if (GameManager::sharedGameManager()->getSound()) {
        //SimpleAudioEngine::sharedEngine()->playEffect("button.wav");
    }
    //CCScene * scene = BeginScene::scene();
    //CCDirector::sharedDirector()->replaceScene(scene);
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

    rapidjson::Document document;
    string nameLocal = GameManager::sharedGameManager()->getName();
    // convertName2((char*)nameLocal.c_str());
    //int pointLocalBest = GameManager::sharedGameManager()->getBestScore();
    int k = 0;
    if(dataBuf.c_str() != NULL && !document.Parse<0>(dataBuf.c_str()).HasParseError()) {
        //for (rapidjson::SizeType  i = 0; i < document.Size(); i++)
        {
            string name = document[idx]["name"].GetString();
            printf("name: %s \n", name.c_str());
            
            string mail = document[idx]["email"].GetString();
            string time = document[idx]["updated_at"].GetString();
            int p = document[idx]["point"].GetInt();
            //int r = document[i]["reward"].GetInt();
            
            
            CCString * strpoint = CCString::createWithFormat("high_score%d", idx + 1);
           // int p = CCUserDefault::sharedUserDefault()->getIntegerForKey(strpoint->getCString());
            CCString * point = CCString::createWithFormat("%d", p);
            CCLabelTTF * pointLabel =
            CCLabelTTF::create(point->getCString(),"Time New Roman",50 * SIZE_RATIO);
            pointLabel->setPosition(ccp(800 * SIZE_RATIO_X, 48 * SIZE_RATIO_Y));
            pointLabel->setAnchorPoint(ccp(1, 0.5f));
            cell->addChild(pointLabel);
            
            CCString * strname = CCString::createWithFormat("name%d", idx + 1);
           // string name = CCUserDefault::sharedUserDefault()->getStringForKey(strname->getCString());
            CCLabelTTF * nameLabel =
            CCLabelTTF::create(name.c_str(),"Time New Roman",50 * SIZE_RATIO);
            nameLabel->setAnchorPoint(ccp(0, 0.5));
            nameLabel->setPosition(ccp(150 * SIZE_RATIO_X, 48 * SIZE_RATIO_Y));
            cell->addChild(nameLabel);
            
        }
    } else {
        CCLog(document.GetParseError());
    }
    
    
    return cell;
}

unsigned int RankingScene::numberOfCellsInTableView(CCTableView *table) {
    return 10;
}
void RankingScene::getRanking() {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        //133.242.203.251
        //http://Pe4L60aeke:dhWLtJ8F1w@takasuapp.com
        
        string ipAddr = GameManager::sharedGameManager()->getIpAddr();
        string url = ipAddr + ":3000/users.json";
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERNAME, "admin");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "1234");
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, rankingWriter);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &dataBuf);
        res = curl_easy_perform(curl);
        printf("data: %s", dataBuf.c_str());
        curl_easy_cleanup(curl);
        if (res == 0) {
            CCLOG("0 response OK\n");
        } else {
            CCLog("code: %i",res);
            CCLabelTTF *checkInternetMsg = CCLabelTTF::create("現在ランキングは閉じています", "", 30*SIZE_RATIO);
            //checkInternetMsg->setPosition(ccp(w/2, h/2 - 30*SIZE_RATIO));
            checkInternetMsg->setColor(ccYELLOW);
            this->addChild(checkInternetMsg);
        }
    } else {
        CCLOG("no curl\n");
    }
    
}
void RankingScene::displayRanking() {
    this->getRanking();
    rapidjson::Document document;
    string nameLocal = GameManager::sharedGameManager()->getName();
   // convertName2((char*)nameLocal.c_str());
    //int pointLocalBest = GameManager::sharedGameManager()->getBestScore();
    int k = 0;
    if(dataBuf.c_str() != NULL && !document.Parse<0>(dataBuf.c_str()).HasParseError()) {
        for (rapidjson::SizeType  i = 0; i < document.Size(); i++) {
            string name = document[i]["name"].GetString();
            printf("name: %s \n", name.c_str());
            
            string mail = document[i]["email"].GetString();
            string time = document[i]["updated_at"].GetString();
            int p = document[i]["point"].GetInt();
            int r = document[i]["reward"].GetInt();
        }
    } else {
        CCLog(document.GetParseError());
    }
    dataBuf = "";
   // players->removeAllObjects();
}

