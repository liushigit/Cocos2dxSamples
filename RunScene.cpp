#include "RunScene.h"
#include "TMXPlatform.h"
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
	
	TMXTiledMap * map = TMXTiledMap::create("map.tmx");

	auto platform = TMXPlatform::create();
	platform->setTiledMap(map);
	this->addChild(platform);

	this->addPlayer(platform);

	auto keyboard_listener = EventListenerKeyboard::create();
	keyboard_listener->onKeyPressed = CC_CALLBACK_2(RunScene::onKeyPressed, this);
	keyboard_listener->onKeyReleased = CC_CALLBACK_2(RunScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboard_listener, this);

	auto particleSystem = ParticleSystemQuad::create("particles/magic.plist");
	particleSystem->setPosition(Point{300, 300});
	particleSystem->setScale(3.f);
	this->addChild(particleSystem);
	this->scheduleUpdate();

	NotificationCenter::getInstance()->addObserver(
		this,
		callfuncO_selector(RunScene::onCollision),
		"collision",
		nullptr);


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

void RunScene::addPlayer(TMXPlatform * platform) {

	_player = Player::create();
	/*Sprite* playerSprite = Sprite::create("player.png");
	_player->bindSprite(playerSprite);*/

	_player->setPosition(Vec2{ 70, 150 });
	// _player->setTiledMap(map);
	_player->setPlatform(platform);
	
	this->addChild(_player);
	_player->run();
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

#pragma mark Handling Notification

void RunScene::onCollision(Ref* sender) {
	cocos2d::log("Hi iiiii ");
}