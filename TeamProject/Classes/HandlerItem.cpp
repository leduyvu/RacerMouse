//
//  HandlerItem.cpp
//  TeamProject
//
//  Created by macbook_006 on 1/25/14.
//
//

#include "GameScreen.h"

void GameScreen::impactWithPlayer(CCArray* arrPlayer, CCArray* arrItems){
    CCObject* objPlayer;
    CCARRAY_FOREACH(arrPlayer, objPlayer){
        Player* player = dynamic_cast<Player*>(objPlayer);
        CCObject* objItem;
        CCARRAY_FOREACH(arrItems, objItem){
            ItemObject* item = dynamic_cast<ItemObject*>(objItem);
            if((int)item->getLocation().x ==  (int)player->getPosition().x && (int)item->getLocation().y == (int)player->getPosition().y){
                CCLOG("item : %d", item->getType());
                switch (item->getType()) {
                    case 1:
                        //slow
                        slowCharacters(false);
                        break;
                    case 2:
                        //ice
                        itemICE();
                        break;
                    case 3:
                        //transform
                        transformPlayer(player);
                        break;
                    case 4:
                        //invisibility
                        player->invisibilityItem();
                        break;
                    case 5:
                        //increaseVelocityPlayer
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                    case 9:
                        break;
                        
                    default:
                        break;
                }
                arrItems->removeObject(item);
                item->deleteItem(this);
            }
        }
    }
}

//slow
void GameScreen::slowCharacters(bool bICE){
    this->unschedule(schedule_selector(GameScreen::autoCharactersPlay));
    CCObject* objCharac;
    float velocity =  0;
    isSlow = true;
    CCARRAY_FOREACH(arrCharacters, objCharac){
        Character* charac = dynamic_cast<Character*>(objCharac);
        if(bICE){
            charac->setVelocity(10);
        }
        else{
            charac->setVelocity(VELOCITY_SLOW);
        }
        velocity = charac->getVelocity();
    }
    this->schedule(schedule_selector(GameScreen::autoCharactersPlay), velocity);
}

void GameScreen::normalCharacters(){
    this->unschedule(schedule_selector(GameScreen::autoCharactersPlay));
    CCObject* objCharac;
    float velocity =  0;
    CCARRAY_FOREACH(arrCharacters, objCharac){
        Character* charac = dynamic_cast<Character*>(objCharac);
        charac->setVelocity(VELOCITY_NORMAL);
        velocity = charac->getVelocity();
    }
    this->schedule(schedule_selector(GameScreen::autoCharactersPlay), velocity);
}

void GameScreen::itemICE(){
    this->unschedule(schedule_selector(GameScreen::autoCharactersPlay));
    this->schedule(schedule_selector(GameScreen::iceCount), TIME_ICE/2);
}

void GameScreen::iceCount(){
    if(iceTime >= TIME_ICE){
        this->schedule(schedule_selector(GameScreen::autoCharactersPlay), VELOCITY_NORMAL);
        this->unschedule(schedule_selector(GameScreen::iceCount));
        iceTime = 0;
    }
    else{
        iceTime += TIME_ICE/2;
    }
}


void GameScreen::increaseVelocityPlayer(){
    this->unschedule(schedule_selector(GameScreen::autoPlay));
    player->setVelocity(VELOCITY_FAST);
    this->schedule(schedule_selector(GameScreen::autoPlay), VELOCITY_FAST);
}

//void GameScreen::invisibility(Player* palyer){
//}

void GameScreen::chivy(int type){
}

void GameScreen::transformPlayer(Player* player){
    if(player->getIDCharac() == 2){
        player->transformation(player->getIDCharac() + 2);
    }
    else if(player){
        player->transformation(player->getIDCharac() + 1);
    }
}
