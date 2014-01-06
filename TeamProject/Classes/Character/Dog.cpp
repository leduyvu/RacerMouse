//
//  Dog.cpp
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#include "Dog.h"
Dog::Dog(){
}
Dog::~Dog(){
}
void Dog::create(){
    this->spr = CCSprite::create("Icon.png");
}