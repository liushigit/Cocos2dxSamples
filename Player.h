#pragma once
#include "cocos2d.h"
#include "GameObject.h"


using namespace cocos2d;

class Player : public GameObject
{
public:
	Player();
	~Player();

	CREATE_FUNC(Player);
	virtual bool init();
	virtual void run();
	virtual void stop();
	virtual void update(float dt);
	virtual void setVelocity(double v);
	virtual void setTiledMap(TMXTiledMap *map);
	virtual void Player::setTargetPosition(int x, int y);
protected:
	Animate * animate_action_run;
	double velocity;
	TMXTiledMap *_map;
	Point tileCoordForPosition(Point pos);
	TMXLayer *_meta;
};

