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
	
	if (_platform->isCollidableAtPositionInLayerNamed(dstPos, "meta")) {
		return;
	}
	
	Node::setPosition(x, y);
}
