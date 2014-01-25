//
//  Dog.h
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#ifndef __TeamProject__Dog__
#define __TeamProject__Dog__

#include <iostream>
#include "Character.h"
class Dog : public Character{
public:
    Dog();
    ~Dog();
    void create();
    void autoRun(RMTiledMap* tileMap);
};
#endif /* defined(__TeamProject__Dog__) */
