//
//  Player.h
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#ifndef __TeamProject__Player__
#define __TeamProject__Player__

#include <iostream>
#include "Character.h"
class Player : public Character{
public:
    Player();
    ~Player();
    void create();
    void autoRun(RMTiledMap* tileMap);
};
#endif /* defined(__TeamProject__Player__) */
