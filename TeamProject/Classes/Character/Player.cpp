//
//  Player.cpp
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#include "Player.h"
Player::Player(){
    this->setVelocity(VELOCITY_PLAYER);
    this->setIDCharac(ID_PLAYER);
    this->setDefaultID(ID_PLAYER);
}
Player::~Player(){
}
void Player::create(){
    this->spr = CCSprite::create("blue.png");
}

void Player::autoRun(RMTiledMap *tileMap){
}

void Player::invisibilityItem(){
    this->spr->setOpacity(125);
    this->setInvisibility(true);
    this->getSprite()->runAction(CCSequence::create(CCDelayTime::create(TIME_OPACITY),
                                                    CCCallFunc::create(this,callfunc_selector(Player::setDefault)),
                                                    NULL));
}
void Player::setDefault(){
    this->setVelocity(VELOCITY_PLAYER);
    this->setIDCharac(ID_PLAYER);
    this->setDefaultID(ID_PLAYER);
    this->getSprite()->setOpacity(255);
}