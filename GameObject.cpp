#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::bindSprite(Sprite* sprite) {
	_sprite = sprite;
	this->addChild(sprite);
}