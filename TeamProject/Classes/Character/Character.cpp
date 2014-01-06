//
//  Character.cpp
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#include "Character.h"
Character::Character(){
}
Character::~Character(){
}
void Character::create(){
}
void Character::addToMap(CCPoint location, CCLayer* layer){
    this->position  = location;
//    this->spr = CCSprite::create("Icon-72.png");
    this->spr->setPosition(location);
    layer->addChild(spr);
}