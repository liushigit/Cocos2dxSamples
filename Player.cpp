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


	this->animate_action_run = Animate::create(animation_run);

	this->scheduleUpdate();
	return true;
}

void Player::update(float dt) {
	float x = getPositionX();
	setPositionX(x + dt * velocity);
}

void Player::stop() {
	auto animation = this->animate_action_run->getAnimation();
	animation->setLoops(1);

	// _sprite->stopAction(this->animate_action_run);
	// _sprite->setDisplayFrameWithAnimationName("player_run", 0);
}

void Player::run() {
	_sprite->runAction(this->animate_action_run);
}

void Player::setVelocity(double v) {
	velocity = v;
}
