#include "AnimationScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"



USING_NS_CC;

using namespace cocostudio::timeline;

Scene* AnimationScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = AnimationScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool AnimationScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	auto mouse_listener = EventListenerMouse::create();
	mouse_listener->onMouseDown = CC_CALLBACK_1(AnimationScene::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouse_listener, this);

	auto keyboard_listener = EventListenerKeyboard::create();
	keyboard_listener->onKeyPressed = CC_CALLBACK_2(AnimationScene::onKeyPressed, this);
	keyboard_listener->onKeyReleased = CC_CALLBACK_2(AnimationScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboard_listener, this);

	cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo("DemoPlayer/DemoPlayer.ExportJson");

	armature = cocostudio::Armature::create("DemoPlayer");
	armature->setName("DemoPlayer");

	armature->setPosition(550, 300);
	armature->setScale(.25f);
	this->addChild(armature);
	
	armature->getAnimation()->play("stand");

    return true;
}

void AnimationScene::onKeyPressed(EventKeyboard::KeyCode keycode, Event * event) {
	if (keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {

		//_player->setVelocity(-200);
	}

	if (keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		// _player->setVelocity(200);
	}
}

void AnimationScene::onKeyReleased(EventKeyboard::KeyCode keycode, Event * event) {
	if (keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW ||
		keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		// _player->setVelocity(0);
	}
}

void AnimationScene::onMouseDown(Event *unused_event) {
//	_player->stop();
	armature->getAnimation()->play("dead", -1, 0);
}

