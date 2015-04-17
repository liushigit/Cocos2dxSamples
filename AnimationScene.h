#pragma once

#include "cocos2d.h"
#include "CCArmature.h"


class Player;


class AnimationScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(AnimationScene);

	void onMouseDown(cocos2d::Event *unused_event);
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event);
protected:
	//void addPlayer();
	// Player * _player;
	cocostudio::Armature* armature;
};


