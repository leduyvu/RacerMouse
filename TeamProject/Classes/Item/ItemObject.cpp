//
//  Item.cpp
//  TeamProject
//
//  Created by NgocDu on 14/01/25.
//
//

#include "ItemObject.h"
ItemObject::ItemObject(){
}
ItemObject::~ItemObject(){
}
void ItemObject::create(int type){
    switch (type) {
        case 1:
            this->spr = CCSprite::create("ball1.png");
            break;
        case 2:
            this->spr = CCSprite::create("ball2.png");
            break;
        case 3:
            this->spr = CCSprite::create("ball3.png");
            break;
        case 4:
            this->spr = CCSprite::create("ball4.png");
            break;
        case 5:
            this->spr = CCSprite::create("ball5.png");
            break;
        case 6:
            this->spr = CCSprite::create("ball6.png");
            break;
        case 7:
            this->spr = CCSprite::create("ball7.png");
            break;
        case 8:
            this->spr = CCSprite::create("ball8.png");
            break;
        case 9:
            this->spr = CCSprite::create("ball9.png");
            break;
        default:
            break;
    }
    this->setType(type);
    this->spr->setScale(0.2);
}
void ItemObject::addToMap(CCPoint location, CCLayer* layer, RMTiledMap *tiledMap){
    this->setLocation(location);
    this->spr->setPosition(tiledMap->convertPosMapToPoint(location));
    layer->addChild(spr, ZORDER_ITEM);
}

void ItemObject::deleteItem(CCLayer* layer){
    layer->removeChild(this->spr);
}