#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

enum Button {
	ButtonExit,
	Left,
	Right,
	Up,
	Down
};

const float INIT_HEAD_WIDTH = 0.5f;
const float INIT_HEAD_HEIGHT = 0.5f;
const int MOVE_SPEED = 10;

const char headFile[] = "logo.png";

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	void update(float);

    void menuCloseCallback(cocos2d::Ref* pSender);

	cocos2d::Sprite* m_pHead;

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
