//
//  RMMap.cpp
//  TeamProject
//
//  Created by Vinh Nhon on 9/01/14.
//
//

#include "RMMap.h"
#include "Cat.h"
#include "cocos2d.h"
using namespace cocos2d;

bool RMMap::init()
{
    if (!CCLayer::init() ) {
        return false;
    }
    
//    Character *charac = new Cat();
//    charac->create();
//    charac->addToMap(ccp(400,400), this);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("spriteSheet.plist");
    gameBatchNode = CCSpriteBatchNode::create("spriteSheet.png");
    this->addChild(gameBatchNode);
    // test to create matrix
    mapInfo = CCDictionary::create();
    mapInfo->retain();
    matrixInfo = new CCArray;
    charactersInfo = new CCArray;
    testCreateMap();
//    testLoadMap();
    testDraw();
    return true;
}

void RMMap::testCreateMap(){
    // create matrix
    for (int i = 0; i < 29; i++) {
        CCArray *column = new CCArray;
        column->autorelease();
        for (int j = 0; j < 26; j++) {
            CCDictionary *square = CCDictionary::create();
            switch (rand()%3) {
                case 0:
                    square->setObject(CCNumber::create(-1), "type");
                    break;
                
                case 1:
                    square->setObject(CCNumber::create(0), "type");
                    break;
                    
                case 2:
                    square->setObject(CCNumber::create(1), "type");
                    break;
                default:
                    break;
            }
            
            column->addObject(square);
        }
        matrixInfo->addObject(column);
    }
    
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(0))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(1))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(2))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(3))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(4))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(5))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(6))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(7))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(8))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(9))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(10))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(11))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(12))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(13))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(14))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(15))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(16))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(17))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(18))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(19))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(20))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(21))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(22))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(23))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(24))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(0))->objectAtIndex(25))->setObject(CCNumber::create(1), "type");

//    row 2
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(0))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(1))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(2))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(3))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(4))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(5))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(6))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(7))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(8))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(9))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(10))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(11))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(12))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(13))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(14))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(15))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(16))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(17))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(18))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(19))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(20))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(21))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(22))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(23))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(24))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(1))->objectAtIndex(25))->setObject(CCNumber::create(1), "type");

//    row 3
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(0))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(1))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(2))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(3))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(4))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(5))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(6))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(7))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(8))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(9))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(10))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(11))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(12))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(13))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(14))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(15))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(16))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(17))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(18))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(19))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(20))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(21))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(22))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(23))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(24))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(2))->objectAtIndex(25))->setObject(CCNumber::create(1), "type");
    
//    row 4
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(0))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(1))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(2))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(3))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(4))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(5))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(6))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(7))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(8))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(9))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(10))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(11))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(12))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(13))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(14))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(15))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(16))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(17))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(18))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(19))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(20))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(21))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(22))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(23))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(24))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(3))->objectAtIndex(25))->setObject(CCNumber::create(1), "type");
    
//  row 5
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(0))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(1))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(2))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(3))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(4))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(5))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(6))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(7))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(8))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(9))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(10))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(11))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(12))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(13))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(14))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(15))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(16))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(17))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(18))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(19))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(20))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(21))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(22))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(23))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(24))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(4))->objectAtIndex(25))->setObject(CCNumber::create(1), "type");

    //  row 6
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(0))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(1))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(2))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(3))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(4))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(5))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(6))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(7))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(8))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(9))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(10))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(11))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(12))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(13))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(14))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(15))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(16))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(17))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(18))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(19))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(20))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(21))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(22))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(23))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(24))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(5))->objectAtIndex(25))->setObject(CCNumber::create(1), "type");


    //  row 7
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(0))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(1))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(2))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(3))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(4))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(5))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(6))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(7))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(8))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(9))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(10))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(11))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(12))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(13))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(14))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(15))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(16))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(17))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(18))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(19))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(20))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(21))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(22))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(23))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(24))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(6))->objectAtIndex(25))->setObject(CCNumber::create(1), "type");

    //  row 8
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(0))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(1))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(2))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(3))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(4))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(5))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(6))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(7))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(8))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(9))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(10))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(11))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(12))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(13))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(14))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(15))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(16))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(17))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(18))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(19))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(20))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(21))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(22))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(23))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(24))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(7))->objectAtIndex(25))->setObject(CCNumber::create(1), "type");

    //  row 9
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(0))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(1))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(2))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(3))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(4))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(5))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(6))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(7))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(8))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(9))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(10))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(11))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(12))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(13))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(14))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(15))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(16))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(17))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(18))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(19))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(20))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(21))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(22))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(23))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(24))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(8))->objectAtIndex(25))->setObject(CCNumber::create(-1), "type");

    //  row 10
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(0))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(1))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(2))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(3))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(4))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(5))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(6))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(7))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(8))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(9))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(10))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(11))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(12))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(13))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(14))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(15))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(16))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(17))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(18))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(19))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(20))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(21))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(22))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(23))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(24))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(9))->objectAtIndex(25))->setObject(CCNumber::create(0), "type");

    //  row 11
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(0))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(1))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(2))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(3))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(4))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(5))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(6))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(7))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(8))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(9))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(10))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(11))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(12))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(13))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(14))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(15))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(16))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(17))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(18))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(19))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(20))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(21))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(22))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(23))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(24))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(10))->objectAtIndex(25))->setObject(CCNumber::create(0), "type");

    //  row 12
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(0))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(1))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(2))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(3))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(4))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(5))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(6))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(7))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(8))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(9))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(10))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(11))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(12))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(13))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(14))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(15))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(16))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(17))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(18))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(19))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(20))->setObject(CCNumber::create(1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(21))->setObject(CCNumber::create(-1), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(22))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(23))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(24))->setObject(CCNumber::create(0), "type");
    dynamic_cast<CCDictionary*>(dynamic_cast<CCArray*>(matrixInfo->objectAtIndex(11))->objectAtIndex(25))->setObject(CCNumber::create(0), "type");

}

void RMMap::testLoadMap(){
    CCPoint drawPosition = ccp(MARGIN_WIDTH + SIZE_COMPONENT/2, 1024 -( MARGIN_HEIGHT + SIZE_COMPONENT/2));
    int i, j;
    i = 0;
    j = 0;
    CCObject *obj1;
    CCARRAY_FOREACH(matrixInfo, obj1){
        CCArray* rowArray = dynamic_cast<CCArray*>(obj1);
        rowArray->autorelease();
        CCObject *obj2;
        CCARRAY_FOREACH(rowArray, obj2){
            CCDictionary* squareInfo = CCDictionary::create();
            
            squareInfo = dynamic_cast<CCDictionary*>(obj2);
            int type = dynamic_cast<CCNumber*>(squareInfo->objectForKey("type"))->getIntValue();
            CCLog("type: %d", type);
            switch (type) {
                case -1:
                {
                    CCDrawNode *circle = CCDrawNode::create();
                    
//                    for (float angle = 0; angle <= 2 * M_PI; angle += 0.01)
//                    {
//                        circle->drawSegment(Point(0.0, 0.0), Point(radius * cos(angle), radius * sin(angle)), 1, Color4F(1.0, 0.0, 0.0, 1.0));
//                    }
                    circle->drawDot(drawPosition, 2.0, ccc4FFromccc3B(ccc3(255, 0, 0)));
                    this->addChild(circle);
                    break;
                }
                    
                case 0:
                    break;
                    
                case 1:
                {
//                    CCSprite* squareSprite = CCSprite::create();
//                    squareSprite = CCSprite::createWithSpriteFrameName("26x26.png");
//                    squareSprite->setPosition(drawPosition);
//                    this->addChild(squareSprite);
                    CCDrawNode *wall = CCDrawNode::create();
                    CCPoint filledVertices[] = { ccp(0,26), ccp(26,26), ccp(26,0), ccp(0,0)};
                    wall->drawPolygon(filledVertices, 4, ccc4FFromccc3B(ccc3(0, 0, 255)), 0, ccc4FFromccc3B(ccc3(255, 255, 255)));
                    wall->setPosition(drawPosition);
                    this->addChild(wall);
                    break;
                }
                default:
                    break;
            }
            
            
            
            
            // calculate to draw next position
            drawPosition = ccp(drawPosition.x + SIZE_COMPONENT, drawPosition.y);
        }
        drawPosition = ccp(MARGIN_WIDTH + SIZE_COMPONENT/2, drawPosition.y - SIZE_COMPONENT);
    }
}

RMMap::~RMMap(){
    CCObject* obj;
    CCARRAY_FOREACH(matrixInfo, obj){
        CC_SAFE_DELETE_ARRAY(obj);
    }
    
    CC_SAFE_DELETE_ARRAY(matrixInfo);
    
}

void RMMap::testDraw(){
    CCPoint drawPosition = ccp(MARGIN_WIDTH + SIZE_COMPONENT/2, 1024 -( MARGIN_HEIGHT + SIZE_COMPONENT/2));
    CCDrawNode *wall = CCDrawNode::create();
    CCPoint filledVertices[] = { ccp(20,20), ccp(20,40), ccp(40,40), ccp(40,20)};
    wall->drawPolygon(filledVertices, 4, ccc4FFromccc3B(ccc3(0, 0, 255)), 0, ccc4FFromccc3B(ccc3(255, 255, 255)));
//    wall->setPosition(drawPosition);
    CCLog("fill rectangle is at position: %f and %f", wall->getPosition().x, wall->getPosition().y);
    this->addChild(wall);

}

RMMap::RMMap(){
    
}