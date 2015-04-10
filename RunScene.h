#pragma once
#include "cocos2d.h"
#include "Player.h"
class Player;

class RunScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	CREATE_FUNC(RunScene);
	virtual bool init();
	RunScene();
	~RunScene();
protected:
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event);
	void addPlayer(TMXPlatform * platform);
	Player * _player;
};

