#include "pch.h"
#include "JoyStickScene.h"
#include "SimpleAudioEngine.h"
#include "base/CCEventListenerController.h"


gainput::InputManager manager;
gainput::InputMap map(manager);


enum Button
{
	ButtonA,
	LeftStickX,
	LeftStickY
};

enum DIRECTION
{
	UP = 1,
	DOWN = 2,
	RIGHT = 4,
	UP_RIGHT = 5,
	DOWN_RIGHT = 6,
	LEFT = 8,
	UP_LEFT = 9,
	DOWN_LEFT = 10,
	
};

const float INIT_HEAD_WIDTH = 0.5f;
const float INIT_HEAD_HEIGHT = 0.5f;
const int MOVE_SPEED = 10;

const char headFile[] = "logo.png";
const char ButtonCloseNormal[] = "CloseNormal.png";
const char ButtonCloseSelected[] = "CloseSelected.png";

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

    auto closeItem = MenuItemImage::create(ButtonCloseNormal, ButtonCloseSelected, CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

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
	MapKeySetting(padId);
	
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
		StickMove();
		HandlingButtonInput();
		st = 0.f;
	}
}


void HelloWorld::StickMove()
{
	if (map.GetBool(LeftStickX) || map.GetBool(LeftStickY))
	{
		float x = map.GetFloat(LeftStickX);
		float y = map.GetFloat(LeftStickY);
		auto move = MoveBy::create(0, Vec2(x * MOVE_SPEED, y * MOVE_SPEED));
		m_pHead->runAction(move);
	}
}


void HelloWorld::MapKeySetting(gainput::DeviceId padId)
{
	map.MapBool(ButtonA, padId, gainput::PadButtonA);
	map.MapFloat(LeftStickX, padId, gainput::PadButtonLeftStickX);
	map.MapFloat(LeftStickY, padId, gainput::PadButtonLeftStickY);
}

void pressedButtonA()
{
	exit(0);
}

void HelloWorld::HandlingButtonInput()
{
	void(*handler[4])();

	handler[0] = pressedButtonA;
	

}