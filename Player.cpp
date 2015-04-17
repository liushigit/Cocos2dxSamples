#include "Player.h"
#include "TMXPlatform.h"
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


void Player::setPlatform(TMXPlatform *platform){
	_platform = platform;
}

void Player::setTargetPosition(int x, int y) {
	Size spriteSize = _sprite->getContentSize();
	Point dstPos = Point( x + spriteSize.width / 2, y );
	
	// 如果Player的位置 >= 中点， Player不动，平台向反方向动。
	Size viewPortSize = Director::getInstance()->getVisibleSize();
	/*auto director = Director::getInstance();
	Size viewPortSize = director->getVisibleSize();*/


	if (x >= viewPortSize.width / 2) {
		float distance = x - this->getPositionX();
		_platform->setPositionX(_platform->getPositionX() - distance);
		return;
	}

	if (_platform->isCollidableAtPositionInLayerNamed(dstPos, "meta")) {
		NotificationCenter::getInstance()->postNotification("collision");
		return;
	}
	
	Node::setPosition(x, y);
}
