#include "TMXPlatform.h"


Point TMXPlatform::tileCoordForPosition(const Point & pos){
	// Size tileSize = _tiledMap->getTileSize();
	int x = pos.x / _tileSize.width;
	int y = (700 - pos.y) / _tileSize.height;
	if (x > 0) {
		x -= 0;
	}
	if (y > 0) {
		y += 1;
	}

	return Point(x, y);
}

bool TMXPlatform::init(){
	return true;
}

void TMXPlatform::setTiledMap(TMXTiledMap * tiledMap){
	_tiledMap = tiledMap;
	this->addChild(tiledMap);
	this->_meta = tiledMap->getLayer("meta");
	this->_meta->setVisible(false);
	
	_tileSize = _tiledMap->getTileSize();
}

bool TMXPlatform::isCollidableAtPositionInLayerNamed(const Point &pos, const std::string layerName)
{

	Point tilePos = tileCoordForPosition(Point(pos.x, pos.y));

	int tileGid = this->_meta->getTileGIDAt(tilePos);

	if (tileGid != 0) {
		Value props = _tiledMap->getPropertiesForGID(tileGid);
		Value prop = props.asValueMap().at("collidable");
		return prop.asString().compare("true") == 0;
	}
	
	return false;

}