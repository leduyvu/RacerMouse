//
//  HandlerItem.cpp
//  TeamProject
//
//  Created by macbook_006 on 1/25/14.
//
//

#include "GameScreen.h"
//slow
void GameScreen::slowCharacters(bool bICE){
    this->unschedule(schedule_selector(GameScreen::autoCharactersPlay));
    CCObject* objCharac;
    float velocity =  0;
    isSlow = true;
    CCARRAY_FOREACH(arrCharacters, objCharac){
        Character* charac = dynamic_cast<Character*>(objCharac);
        if(bICE){
            charac->setVelocity(0);
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
    slowCharacters(true);
}

void GameScreen::increaseVelocityPlayer(){
    this->unschedule(schedule_selector(GameScreen::autoPlay));
    player->setVelocity(VELOCITY_FAST);
    this->schedule(schedule_selector(GameScreen::autoPlay), VELOCITY_FAST);
}

void GameScreen::invisibility(){
    player->getSprite()->setOpacity(125);
    player->setInvisibility(true);
}

void GameScreen::chivy(int type){
}
