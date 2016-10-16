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
	if (st >= 0.05f) {
		manager.Update();
		if (map.GetBoolWasDown(ButtonExit))
		{
			exit(0);
		}
		if (map.GetBoolIsNew(Left))
		{
			m_Direction = Left;
		}
		else if (map.GetBoolIsNew(Right))
		{
			m_Direction = Right;
		}
		else if (map.GetBoolIsNew(Up))
		{
			m_Direction = Up;
		}
		else if (map.GetBoolIsNew(Down))
		{
			m_Direction = Down;
		}
		else  if (map.GetBoolWasDown(Left)  ||
			      map.GetBoolWasDown(Right) ||
			      map.GetBoolWasDown(Up)    ||
			      map.GetBoolWasDown(Down))
		{
			m_Direction = 0;
		}
		MoveHead();
		st = 0.f;
	}
}

void HelloWorld::MoveHead()
{
	auto moveUp = MoveBy::create(0, Vec2(0, MOVE_SPEED));
	auto moveDown = MoveBy::create(0, Vec2(0, -MOVE_SPEED));
	auto moveRight = MoveBy::create(0, Vec2(MOVE_SPEED, 0));
	auto moveLeft = MoveBy::create(0, Vec2(-MOVE_SPEED, 0));

	switch (m_Direction) {
		case Up :
			m_pHead->runAction(moveUp);
			break;
		case Down :
			m_pHead->runAction(moveDown);
			break;
		case Right :
			m_pHead->runAction(moveRight);
			break;
		case Left :
			m_pHead->runAction(moveLeft);
			break;
		Default :
			break;
	}
}
