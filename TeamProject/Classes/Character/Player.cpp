//
//  Player.cpp
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#include "Player.h"
Player::Player(){
}
Player::~Player(){
}
void Player::create(){
    this->spr = CCSprite::create("Icon-72.png");
}