//
//  RankingScene.h
//  BallJumpping
//
//  Created by macbook_016 on 2013/12/24.
//
//

#ifndef __BallJumpping__RankingScene__
#define __BallJumpping__RankingScene__

#include <iostream>
#include "cocos2d.h"

#include "GameManager.h"

#include "CCTableView.h"
#include "CCTableViewCell.h"
#include "CCScrollView.h"
#include "curl/curl.h"
#include "rapidjson.h"
#include "document.h"
#include "GameMenu.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class RankingScene : public CCLayer , public CCTableViewDelegate, CCTableViewDataSource {
private:
    CCSize size;
    int celltouch;
    float SIZE_RATIO, SIZE_RATIO_X, SIZE_RATIO_Y;
    string dataBuf;
public:
    virtual bool init();
    static CCScene * scene();
    void menuPlay(CCObject * pSender);
    void menuQuit(CCObject * pSender);
    virtual void scrollViewDidScroll(CCScrollView* view){};
    virtual void scrollViewDidZoom(CCScrollView* view){}
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCSize tableCellSizeForIndex(CCTableView *table, unsigned int idx);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(CCTableView *table);
    CREATE_FUNC(RankingScene);
    
    void getRanking();
    void displayRanking();
};

#endif /* defined(__BallJumpping__RankingScene__) */
