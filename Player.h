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
protected:
	Animate * animate_action_run;
	double velocity;

};

