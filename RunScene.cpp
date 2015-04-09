#include "RunScene.h"
using namespace cocos2d;

RunScene::RunScene()
{
}


RunScene::~RunScene()
{
}

bool RunScene::init() {
	if (!Layer::init())
	{
		return false;
	}
	log("map....");
	TMXTiledMap * map = TMXTiledMap::create("map.tmx");

	this->addChild(map);
	this->addPlayer(map);

	auto keyboard_listener = EventListenerKeyboard::create();
	keyboard_listener->onKeyPressed = CC_CALLBACK_2(RunScene::onKeyPressed, this);
	keyboard_listener->onKeyReleased = CC_CALLBACK_2(RunScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboard_listener, this);

	return true;
}

Scene* RunScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = RunScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void RunScene::addPlayer(cocos2d::TMXTiledMap *map) {

	_player = Player::create();
	/*Sprite* playerSprite = Sprite::create("player.png");
	_player->bindSprite(playerSprite);*/

	_player->setPosition(Vec2{ 70, 150 });
	_player->setTiledMap(map);

	_player->run();
	this->addChild(_player);
}

void RunScene::onKeyPressed(EventKeyboard::KeyCode keycode, Event * event) {
	if (keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {

		_player->setVelocity(-200);
	}

	if (keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		_player->setVelocity(200);
	}
}

void RunScene::onKeyReleased(EventKeyboard::KeyCode keycode, Event * event) {
	if (keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW ||
		keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		_player->setVelocity(0);
	}
}