//
//  GameMenu.h
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#ifndef __TeamProject__GameMenu__
#define __TeamProject__GameMenu__

#include <iostream>
#include "cocos2d.h"
#include "GameScreen.h"
#include "RankingScene.h"
using namespace cocos2d;
class GameMenu : public CCLayer {
private:
    CCSize _size;
    float _width;
    float _height;
    float _SIZE_RATIO;
    float _SIZE_RATIO_X;
    float _SIZE_RATIO_Y;
public:
    virtual bool init();
    static CCScene * scene();
    void menuCloseCallback(CCObject * pSender);
    void menuStart(CCObject * pSender);
    void menuRank(CCObject * pSender);
    CREATE_FUNC(GameMenu);
};


#endif /* defined(__TeamProject__GameMenu__) */
