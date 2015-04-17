#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIButton.h"
#include "AnimationScene.h"
#include "RunScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainMenu.csb");
	ui::Button * startButton = (ui::Button *) rootNode->getChildByName("StartButton");
	startButton->addClickEventListener(CC_CALLBACK_1(HelloWorld::onClickStart, this));

    addChild(rootNode);

    return true;
}

void HelloWorld::onClickStart(Ref *sender) {
	
	Director::getInstance()->pushScene(
		TransitionFlipY::create(2.0f, RunScene::createScene())
	);

}