#pragma once
#ifndef _GameObject_H_
#define _GameObject_H_

#include "cocos2d.h"
using namespace cocos2d;

class GameObject: public Node
{
public:
	GameObject();
	~GameObject();

	void bindSprite(Sprite* sprite);

protected:
	Sprite* _sprite;

};





#endif