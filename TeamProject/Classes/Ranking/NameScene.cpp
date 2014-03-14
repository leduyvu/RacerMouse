//
//  NameScene.cpp
//  BallJumpping
//
//  Created by macbook_016 on 2013/12/30.
//
//

#include "NameScene.h"
CCScene * NameScene::scene() {
    CCScene * scene = CCScene::create();
    NameScene * layer = NameScene::create();
    scene->addChild(layer);
    return scene;
}

bool NameScene::init() {
    if (!CCLayer::create()) {
        return false;
    }
    size = CCDirector::sharedDirector()->getWinSize();
    SIZE_RATIO = GameManager::sharedGameManager()->getSIZE_RATIO();
    SIZE_RATIO_X = GameManager::sharedGameManager()->getSIZE_RATIO_X();
    SIZE_RATIO_Y = GameManager::sharedGameManager()->getSIZE_RATIO_Y();
    
    CCSprite * bg = CCSprite::create("HelloWorld.png");
    bg->setScaleX(SIZE_RATIO_X);
    bg->setScaleY(SIZE_RATIO_Y);
    bg->setPosition(ccp(size.width / 2, size.height / 2));
    this->addChild(bg);
    
    CCSprite * frame = CCSprite::create("frame_top.png");
    frame->setScaleY(SIZE_RATIO_Y);
    frame->setScaleX(SIZE_RATIO_X);
    frame->setPosition(ccp(size.width / 2, size.height / 2));
    this->addChild(frame);

    CCSize editboxSize = CCSizeMake(600 * SIZE_RATIO_X, 100 * SIZE_RATIO_Y);
    m_pUserName = CCEditBox::create(editboxSize ,
                                    CCScale9Sprite::create("WhiteBox.png"));
    m_pUserName->setPosition(ccp(size.width / 2, size.height * 4 / 7));
    m_pUserName->setFontSize(5 * SIZE_RATIO_X);
    m_pUserName->setFontColor(ccc3(100, 100, 100));
    m_pUserName->setMaxLength(10);
    m_pUserName->setPlaceHolder("input");
    m_pUserName->setReturnType(kKeyboardReturnTypeDefault);
    m_pUserName->setInputMode(kEditBoxInputModeAny);
    m_pUserName->setDelegate(this);
    this->addChild(m_pUserName);

    CCMenuItemImage * accept =
    CCMenuItemImage::create("btn_accept.png", "btn_accept.png", this,
                            menu_selector(NameScene::menuAccept));
    accept->setScaleX(SIZE_RATIO_X);
    accept->setScaleY(SIZE_RATIO_Y);
    accept->setPosition(ccp(280 * SIZE_RATIO_X, size.height * 2 / 7));
    
    CCMenuItemImage * cance =
    CCMenuItemImage::create("btn_cancel.png", "btn_cancel.png", this,
                            menu_selector(NameScene::menuCance));
    cance->setScaleX(SIZE_RATIO_X);
    cance->setScaleY(SIZE_RATIO_Y);
    cance->setPosition(ccp(700 * SIZE_RATIO_X, size.height * 2 / 7));
    CCMenu * menu = CCMenu::create(accept, cance, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu);
    return true;
}
void NameScene::editBoxEditingDidBegin(CCEditBox *editBox) {
}

void NameScene::editBoxEditingDidEnd(CCEditBox *editBox) {
}

void NameScene::editBoxTextChanged(CCEditBox *editBox, string &text) {
}

void NameScene::editBoxReturn(CCEditBox *editBox) {
}

void NameScene::menuAccept() {
    CCScene * scene = RankingScene::scene();
    CCDirector::sharedDirector()->replaceScene(scene);
}
void NameScene::menuCance() {
//    CCScene * scene = GamePlayScene::scene();
//    CCDirector::sharedDirector()->replaceScene(scene);
}