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
    this->spr->release();
}

void Character::autoRun(RMTiledMap* tileMap){
}

void Character::create(){
}

void Character::addToMap(CCPoint location, CCLayer* layer, RMTiledMap *tiledMap){
    this->position  = location;
    this->spr->setPosition(tiledMap->convertPosMapToPoint(location));
    layer->addChild(spr);
}

bool Character::checkLeft(RMTiledMap *tiledMap, CCPoint currenPos){
    if(currenPos.x == 0 && currenPos.y == 13){
        return true;
    }
    if(currenPos.x <= 0)
        return false;
    CCString *type = tiledMap->typeAtTileCoord(ccp(currenPos.x - 1 , currenPos.y));
    if (type && (type->compare("1") == 0 || type->compare("2") == 0) && currenPos.x > 0) {
        return true;
    }
    else if(type == NULL){
        return true;
    }
    else return false;
}

bool Character::checkRight(RMTiledMap *tiledMap, CCPoint currenPos){
    if(currenPos.x >= 25 && currenPos.y == 13){
        return true;
    }
    if(currenPos.x >= 25)
        return false;
    CCString *type = tiledMap->typeAtTileCoord(ccp(currenPos.x + 1 , currenPos.y));
    if (type && (type->compare("1") == 0 || type->compare("2") == 0) && currenPos.x < 25) {
        return true;
    }
    else if(type == NULL){
        return true;
    }
    else return false;
}

bool Character::checkBelow(RMTiledMap *tiledMap, CCPoint currenPos){
    if(currenPos.y >= 28)
        return false;
    CCString *type = tiledMap->typeAtTileCoord(ccp(currenPos.x, currenPos.y + 1));
    if (type && (type->compare("1") == 0 || type->compare("2") == 0)) {
        return true;
    }
    else if(type == NULL){
        return true;
    }
    else return false;
}

bool Character::checkUpward(RMTiledMap *tiledMap, CCPoint currenPos){
    if(currenPos.y <= 0)
        return false;
    CCString *type = tiledMap->typeAtTileCoord(ccp(currenPos.x, currenPos.y - 1));
    if (type && (type->compare("1") == 0 || type->compare("2") == 0)) {
        return true;
    }
    else if(type == NULL){
        return true;
    }
    else return false;
}

void Character::moveLeft(RMTiledMap *tiledMap){
    if(this->getPosition().x == 0 && this->getPosition().y == 13){
        this->setPosAgian(ccp(25, 13), (CCLayer*)this->getSprite()->getParent() , tiledMap);
        this->setRunCurrent(2);
    }
    else if(checkLeft(tiledMap, this->position)){
        this->spr->runAction(CCMoveBy::create(this->getVelocity(), ccp(tiledMap->getTiledMap()->getTileSize().width * (-1), 0)));
        this->position = ccp(this->position.x - 1, this->position.y);
        this->setRunCurrent(2);
    }
}

void Character::moveRight(RMTiledMap *tiledMap){
    if(this->getPosition().x == 25 && this->getPosition().y == 13){
        this->setPosAgian(ccp(0, 13), (CCLayer*)this->getSprite()->getParent(), tiledMap);
        this->setRunCurrent(1);
    }
    else
    if(checkRight(tiledMap, this->position)){
        this->spr->runAction(CCMoveBy::create(this->getVelocity(), ccp(tiledMap->getTiledMap()->getTileSize().width, 0)));
        this->position = ccp(this->position.x + 1, this->position.y);
        this->setRunCurrent(1);
    }
}

void Character::moveBelow(RMTiledMap *tiledMap){
    if(checkBelow(tiledMap, this->position)){
        this->spr->runAction(CCMoveBy::create(this->getVelocity(), ccp(0, tiledMap->getTiledMap()->getTileSize().width * (-1))));
        this->position = ccp(this->position.x, this->position.y + 1);
        this->setRunCurrent(4);
    }
}

void Character::moveUpward(RMTiledMap *tiledMap){
    if(checkUpward(tiledMap, this->position)){
        this->spr->runAction(CCMoveBy::create(this->getVelocity(), ccp(0, tiledMap->getTiledMap()->getTileSize().width)));
        this->position = ccp(this->position.x, this->position.y - 1);
        this->setRunCurrent(3);
    }
}

void Character::setPosAgian(CCPoint location, CCLayer* layer, RMTiledMap *tiledMap){
    this->position  = location;
    this->spr->setPosition(tiledMap->convertPosMapToPoint(location));
}

void Character::transformation(int idCharac){
    if(idCharac == 1){
        
    }
    else if (idCharac == 2){
    
    }
    else if (idCharac == 3){
        
    }
    else if (idCharac == 4){
        CCAnimation *animation = CCAnimation::create();
        for (int i = 1; i <= 6; i++)
        {
            std::string str = static_cast<ostringstream*>(&(ostringstream() << i))->str();
            str = "Animation/Transformation/fx0" + str + ".png";
            animation->addSpriteFrameWithFileName(str.c_str());
        }
        animation->setDelayPerUnit(0.02);
        animation->setLoops(1);
        animation->setRestoreOriginalFrame(true);
        CCAnimate *action = CCAnimate::create(animation);
        this->getSprite()->runAction(CCSequence::create(action,
                                                        CCDelayTime::create(0.8),
                                                        CCCallFuncND::create(this,callfuncND_selector(Character::setSpriteWithIDCharac),(void*)(new int(1))),
                                                        NULL));
    }
}

void Character::setSpriteWithIDCharac(CCNode* sender, void* idCharac){
    this->spr->setTexture(CCSprite::create("blue.png")->getTexture());
}