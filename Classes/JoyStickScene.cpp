#include "pch.h"
#include "JoyStickScene.h"
#include "SimpleAudioEngine.h"
#include "base/CCEventListenerController.h"

gainput::InputManager manager;
gainput::InputMap map(manager);

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    
    auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	
	manager.SetDisplaySize(visibleSize.width, visibleSize.height);
	const gainput::DeviceId padId = manager.CreateDevice<gainput::InputDevicePad>();
	
	map.MapBool(ButtonConfirm, padId, gainput::PadButtonA);
	scheduleUpdate();
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void HelloWorld::update(float dt)
{
	static float st = 0.0f;
	st += dt;
	if (st >= 0.1f) {
		manager.Update();
		if (map.GetBoolWasDown(ButtonConfirm)) { exit(0); }
	}
}