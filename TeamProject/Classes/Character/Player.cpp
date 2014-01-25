//
//  Player.cpp
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#include "Player.h"
Player::Player(){
    this->setVelocity(0.2);
}
Player::~Player(){
}
void Player::create(){
    this->spr = CCSprite::create("blue.png");
}

void Player::autoRun(RMTiledMap *tileMap){
}