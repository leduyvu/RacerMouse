//
//  RMTiledMap.cpp
//  TeamProject
//
//  Created by Vinh Nhon on 20/01/14.
//
//

#include "RMTiledMap.h"
#include "Definition.h"
using namespace cocos2d;
bool RMTiledMap::init(){
    if (!CCLayer::init()) {
        return false;
    }
//    TMX tile map: Only base64 and/or gzip/zlib maps are supported
//    TMX: Only 1 tileset per layer is supported
    tileMap = new CCTMXTiledMap();
    tileMap->initWithTMXFile("tileMap.tmx");
    tileMap->retain();
    meta = tileMap->layerNamed("Meta");
    meta->retain();
    this->addChild(tileMap);
    return true;
}

CCTMXLayer* RMTiledMap::getMetaLayer(){
        return meta;
}

CCPoint RMTiledMap::tileCoordForPosition(cocos2d::CCPoint position){
    int x = (position.x /*- MARGIN_WIDTH*/) / tileMap->getTileSize().width;
    int y = ((tileMap->getMapSize().height*tileMap->getTileSize().height) - position.y /*+ */) / tileMap->getTileSize().height;
    return ccp(x,y);
}

CCTMXTiledMap* RMTiledMap::getTiledMap(){
    return tileMap;
}

CCString* RMTiledMap::typeAtTileCoord(cocos2d::CCPoint tileCoord){
    CCLog("hang: %f, cot: %f", tileCoord.y, tileCoord.x);
    int tileGid = meta->tileGIDAt(tileCoord);
    CCLog("tileGid: %f", tileGid);
    if (tileGid) {
        CCDictionary *properties = tileMap->propertiesForGID(tileGid);
        if (properties) {
            CCString *type = new CCString();
            *type = *properties->valueForKey("type");
            return type;
        }
    }
    return NULL;
}

CCPoint RMTiledMap::convertPosMapToPoint(CCPoint posMap){
    int x = this->getPosition().x + tileMap->getMapSize().width * (posMap.x) + tileMap->getMapSize().width/2;
    int y = this->getPosition().y + tileMap->getMapSize().width * (29 - posMap.y) - tileMap->getMapSize().width/2;
    return ccp(x, y);
}