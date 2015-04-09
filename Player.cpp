#include "Player.h"
#include "animutils/AnimUtils.h"
#include <string>

Player::Player()
{
}


Player::~Player()
{
}

bool Player::init() {
	// initialize animate actions
	SpriteFrameCache * frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("boys.plist", "boys.png");

	Sprite * initialPose = Sprite::createWithSpriteFrameName("run1.png");
	this->bindSprite(initialPose);


	auto animation_run = LSAnimUtils::createAnimationWithFrameNameAndNumber("run%d.png", 15, .05f, -1);

	auto animationCache = AnimationCache::getInstance();
	animationCache->addAnimation(animation_run, std::string{ "player_run" });

	velocity = 0;
	this->animate_action_run = Animate::create(animation_run);

	this->scheduleUpdate();
	return true;
}

void Player::update(float dt) {
	float x = getPositionX();
	float y = getPositionY();
	//setPositionX(x + dt * velocity);
	log(velocity);
	setTargetPosition(x + dt * velocity, y);
}

void Player::stop() {
	auto animation = this->animate_action_run->getAnimation();
	animation->setLoops(1);

	// _sprite->stopAction(this->animate_action_run);
	_sprite->setDisplayFrameWithAnimationName("player_run", 0);
}

void Player::run() {
	_sprite->runAction(this->animate_action_run);
}

void Player::setVelocity(double v) {
	velocity = v;
}

void Player::setTiledMap(TMXTiledMap *map){
	// p.184
	this->_map = map;
	_meta = map->getLayer("meta");
	// _meta->setVisible(false);
	_meta->setVisible(false);

}

void Player::setTargetPosition(int x, int y) {
	Size spriteSize = _sprite->getContentSize();
	Point dstPos = Point( x + spriteSize.width / 2, y );

	Point tilePos = tileCoordForPosition(Point(dstPos.x, dstPos.y));
	log(tilePos.x);
	int tileGid = this->_meta->getTileGIDAt(tilePos);

	if (tileGid != 0) {
		Value props = _map->getPropertiesForGID(tileGid);
		Value prop = props.asValueMap().at("collidable");
		if (prop.asString().compare("true") == 0) {
				return;
		}
	}
	Node::setPosition(x, y);
}

Point Player::tileCoordForPosition(Point pos)
{
	Size tileSize = _map->getTileSize();
	int x = pos.x / tileSize.width;
	int y = (700 - pos.y) / tileSize.height;
	if (x > 0) {
		x -= 0;
	}
	if (y > 0) {
		y += 1;
	}

	return Point( x, y );

}