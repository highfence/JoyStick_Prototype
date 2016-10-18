#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	void update(float);
	void MapKeySetting(const unsigned int);
	void MoveHead();
	void StickMove();
	void HandlingButtonInput();

    void menuCloseCallback(cocos2d::Ref* pSender);

	cocos2d::Sprite* m_pHead;
	unsigned int m_keyboardInput = 0;
    CREATE_FUNC(HelloWorld);
};


void pressedButtonA();

#endif // __HELLOWORLD_SCENE_H__
