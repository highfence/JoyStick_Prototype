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

	// Gamepad setting.
	manager.SetDisplaySize(visibleSize.width, visibleSize.height);
	const gainput::DeviceId padId = manager.CreateDevice<gainput::InputDevicePad>();
	
	// Gamepad Key setting.
	map.MapBool(ButtonExit, padId, gainput::PadButtonA);
	map.MapBool(Left, padId, gainput::PadButtonLeft);
	map.MapBool(Right, padId, gainput::PadButtonRight);
	map.MapBool(Up, padId, gainput::PadButtonUp);
	map.MapBool(Down, padId, gainput::PadButtonDown);
	
	// Sprite Setting.
	m_pHead = Sprite::create(headFile);
	m_pHead->setPosition(Vec2(visibleSize.width * INIT_HEAD_WIDTH,
							  visibleSize.height * INIT_HEAD_HEIGHT));
	addChild(m_pHead);


	// Schedule Update.
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
		if (map.GetBoolWasDown(ButtonExit))
		{
			exit(0);
		}
		if (map.GetBoolIsNew(Left))
		{
			auto moveLeft = MoveBy::create(0, Vec2(-MOVE_SPEED, 0));
			this->m_pHead->runAction(moveLeft);
		}
		else if (map.GetBoolIsNew(Right))
		{
			auto moveRight = MoveBy::create(0, Vec2(MOVE_SPEED, 0));
			this->m_pHead->runAction(moveRight);
		}
		else if (map.GetBoolIsNew(Up))
		{
			auto moveUp = MoveBy::create(0, Vec2(0, MOVE_SPEED));
			this->m_pHead->runAction(moveUp);
		}
		else if (map.GetBoolIsNew(Down))
		{
			auto moveDown = MoveBy::create(0, Vec2(0, -MOVE_SPEED));
			this->m_pHead->runAction(moveDown);
		}
		st = 0.f;
	}
}
