//
//  NameScene.h
//  BallJumpping
//
//  Created by macbook_016 on 2013/12/30.
//
//

#ifndef __BallJumpping__NameScene__
#define __BallJumpping__NameScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "GameManager.h"
#include "RankingScene.h"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace std;
class NameScene : public CCLayer, public CCEditBoxDelegate {
    CCSize size;
    float SIZE_RATIO, SIZE_RATIO_X, SIZE_RATIO_Y;
    CCEditBox * m_pUserName;
public:
    virtual bool init();
    static CCScene * scene();
    void toExtensionsMainLayer(CCObject *sender);
    virtual void editBoxEditingDidBegin(CCEditBox* editBox);
    virtual void editBoxEditingDidEnd(CCEditBox* editBox);
    virtual void editBoxTextChanged(CCEditBox* editBox, string &text);
    virtual void editBoxReturn(CCEditBox * editBox);
    void menuAccept();
    void menuCance();
    CREATE_FUNC(NameScene);
};
#endif /* defined(__BallJumpping__NameScene__) */
