#pragma once

#include "cocos2d.h"
#include <string>

using namespace cocos2d;

class TMXPlatform : public Node
{
public:
	CREATE_FUNC(TMXPlatform);
	//TMXPlatform();
	//~TMXPlatform();

	virtual Point tileCoordForPosition(const Point & point);

	virtual bool init();
	virtual void setTiledMap(TMXTiledMap * tiledMap);
	
	virtual bool isCollidableAtPositionInLayerNamed(const Point &pos, const std::string layerName);


protected:
	TMXTiledMap * _tiledMap;
	Size _tileSize;
	TMXLayer * _meta;

};

