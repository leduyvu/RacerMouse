//
//  Dog.cpp
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#include "Dog.h"
//
//  Dog.cpp
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#include "Dog.h"
Dog::Dog(){
    this->setVelocity(VELOCITY_DOG);
    this->setIDCharac(ID_DOG);
    this->setDefaultID(ID_DOG);
}
Dog::~Dog(){
}
void Dog::create(){
    this->spr = CCSprite::create("Character/boot.png");
}

void Dog::autoRun(RMTiledMap* tileMap){
    if(this->getRunCurrent() == 1){
        if(this->checkBelow(tileMap, this->getPosition()) ||
           this->checkUpward(tileMap, this->getPosition())){
            int randNumber = rand() % 4;
            if(!checkRight(tileMap, this->getPosition())){
                randNumber = rand() % 2;
            }
            switch (randNumber) {
                case 3:
                    setRunValue(1);
                    break;
                case 2:
                    setRunValue(1);
                    break;
                case 1:
                    if(checkUpward(tileMap, this->getPosition())){
                        setRunValue(4);
                    }
                    else if (checkBelow(tileMap, this->getPosition())){
                        setRunValue(3);
                    }
                    break;
                case 0:
                    if(this->checkBelow(tileMap, this->getPosition())){
                        setRunValue(4);
                    }
                    else if (checkUpward(tileMap, this->getPosition())){
                        setRunValue(3);
                    }
                    break;
                default:
                    break;
            }
        }
        else if(!checkRight(tileMap, this->getPosition())){
            setRunValue(2);
        }
    }
    else if(this->getRunCurrent() == 2){
        if(this->checkBelow(tileMap, this->getPosition()) ||
           this->checkUpward(tileMap, this->getPosition())){
            int randNumber = rand() % 4;
            if(!checkLeft(tileMap, this->getPosition())){
                randNumber = rand() % 2;
            }
            switch (randNumber) {
                case 3:
                    setRunValue(2);
                    break;
                case 2:
                    setRunValue(2);
                    break;
                case 1:
                    if(checkUpward(tileMap, this->getPosition())){
                        setRunValue(4);
                    }
                    else if (checkBelow(tileMap, this->getPosition())){
                        setRunValue(3);
                    }
                    break;
                case 0:
                    if(this->checkBelow(tileMap, this->getPosition())){
                        setRunValue(4);
                    }
                    else if (checkUpward(tileMap, this->getPosition())){
                        setRunValue(3);
                    }
                    break;
                default:
                    break;
            }
        }
        else if(!checkLeft(tileMap, this->getPosition())){
            setRunValue(1);
        }
    }
    else if(this->getRunCurrent() == 3){
        if(this->checkLeft(tileMap, this->getPosition()) ||
           this->checkRight(tileMap, this->getPosition())){
            int randNumber = rand() % 4;
            if(!checkUpward(tileMap, this->getPosition())){
                randNumber = rand() % 2;
            }
            switch (randNumber) {
                case 3:
                    setRunValue(3);
                    break;
                case 2:
                    setRunValue(3);
                    break;
                case 1:
                    if(checkRight(tileMap, this->getPosition())){
                        setRunValue(1);
                    }
                    else if (checkLeft(tileMap, this->getPosition())){
                        setRunValue(2);
                    }
                    break;
                case 0:
                    if(this->checkLeft(tileMap, this->getPosition())){
                        setRunValue(2);
                    }
                    else if (checkRight(tileMap, this->getPosition())){
                        setRunValue(1);
                    }
                    break;
                default:
                    break;
            }
        }
        else if(!checkUpward(tileMap, this->getPosition())){
            setRunValue(4);
        }
    }
    else if(this->getRunCurrent() == 4){
        if(this->checkLeft(tileMap, this->getPosition()) ||
           this->checkRight(tileMap, this->getPosition())){
            int randNumber = rand() % 4;
            if(!checkBelow(tileMap, this->getPosition())){
                randNumber = rand() % 2;
            }
            switch (randNumber) {
                case 3:
                    setRunValue(4);
                    break;
                case 2:
                    setRunValue(4);
                    break;
                case 1:
                    if(checkRight(tileMap, this->getPosition())){
                        setRunValue(1);
                    }
                    else if (checkLeft(tileMap, this->getPosition())){
                        setRunValue(2);
                    }
                    break;
                case 0:
                    if(this->checkLeft(tileMap, this->getPosition())){
                        setRunValue(2);
                    }
                    else if (checkRight(tileMap, this->getPosition())){
                        setRunValue(1);
                    }
                    break;
                default:
                    break;
            }
        }
        else if(!checkBelow(tileMap, this->getPosition())){
            setRunValue(3);
        }
    }
}