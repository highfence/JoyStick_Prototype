#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	void update(float);
	//void MapKeySetting(const gainput::DeviceId);
	void MoveHead();
	void CheckNewInput();
	void CheckInputRelease();

    void menuCloseCallback(cocos2d::Ref* pSender);

	cocos2d::Sprite* m_pHead;
	unsigned int m_keyboardInput = 0;
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
