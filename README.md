# JoyStick_Prototype
ProtoType for joyStick on Cocos2d-x engine

##���̽�ƽ�� ����ϴ� ������Ÿ���Դϴ�.

###���� ����
10/13 : Cocos2d-x ���ο� �����ϴ� �Լ��� ����Ϸ��� ��������. <br>
10/14~10/15 : ������ �������� ��õ���ֽ� gainput���̺귯�� ���. �ٸ� ����ϴٰ� �����߻�. <br>
gainput ���̺귯������ window���� Xinput���̺귯���� ����ϴ� �κ��� �ִµ�, ���ο� Xinput1_4.dll�� �����ϴµ��� �ұ��ϰ� ã���� ���ؼ� ��ũ ������ �ڲ� ��. <br>
���ξ��� ������ �޾� �ܿ�ܿ� gainput���̺귯���� ����.<br>
10/16 : gainput���̺귯�� ��� ����� ��� ���� �ľ�. �׷��� ��ƽ ������� �� �𸣰���. <br>
���� ������ ���, �ٸ� ��ƽ ���� ���� ���̺귯���� ����غ��� Ž��. (SFML ���̺귯�� ��) <br>

###����
���� ȭ�鿡 Smile�� ����Ű �Է��� �޾� �����̴� ������ ���α׷��Դϴ�.<br>
���̽�ƽ�� A��ư�� ������ ���α׷��� �������� ��������ϴ�.<br>

###Gainput ���̺귯��.
�켱 ���� �е带 �����ϱ� ���Ͽ� ������ �ʿ��մϴ�.<br>
```
gainput::InputManager manager;
gainput::InputMap map(manager)
```
gainput�� ����ϱ����ؼ��� �켱 InputManager�� �׸� �޾� �����ϴ� InputMap�� �ʿ��մϴ�.<br>
Manager�� ����ϴ� ���̺귯���� ��ü���� ������ �����մϴ�.<br>
gainput�� �Է��� map�� ���·� ������ �մϴ�. Map�� Ű�� �����ϴ� �Ѱ����� ������ �մϴ�.<br>

```
	manager.SetDisplaySize(visibleSize.width, visibleSize.height);
	const gainput::DeviceId padId = manager.CreateDevice<gainput::InputDevicePad>();
```
Manager�� ������ ���� ������ ���־�� �մϴ�. <br>
Line1�� manager���� ���÷��� ����� �ǳ��ִ� ����Դϴ�. <br>
Line2�� �Ŵ����� ����̽��� ������ִ� �Լ��Դϴ�. CreateDevice<gainput::InputDevicePad>()�� ���Ͽ� �е��� ����̽��� �����ϰ� �̸� padId�� �����մϴ�. <br>

```
	// Gamepad Key setting.
	map.MapBool(ButtonExit, padId, gainput::PadButtonA);
	map.MapBool(Left, padId, gainput::PadButtonLeft);
	map.MapBool(Right, padId, gainput::PadButtonRight);
	map.MapBool(Up, padId, gainput::PadButtonUp);
	map.MapBool(Down, padId, gainput::PadButtonDown)
```
�� ���� map�� �ڽ��� ����� Ű�� �������ݴϴ�. Left, Right, Up, Down�� �е��� ����Ű�� �������ִ� �ڵ��Դϴ�. <br>

```
	manager.Update();
	if (map.GetBoolWasDown(ButtonExit)) { exit(0); }
```
�� ���� cocos2d-x�� update�Լ� �ȿ� manager.Update() �Լ��� �־��ְ�, ������ ���Ͽ� ��ư�� ���ȴ��� �ƴ��� Ȯ�����ݴϴ�. <br>
cocos2d-x���� keyPressed�� keyReleased�� �ִ� �� ó��, map�ȿ��� GetBoolIsNew�� GetBoolWasDown�� ���Ͽ� ���� ������ �� �� �ֽ��ϴ�. <br>


## �ƽ��� ��.
�ܺ� ���̺귯���� ��ġ�ϴ� ������ ó���̶� ���� ������ ��.<br>
�� �߿����� ����ġ ���� ������ ���� �ð��� ���� ����� <br>
���̺귯���ȿ��� ��ƽ�� �����ϴ� �Լ��� ã�� ���Ͽ� ��ƽ���� ������ ���� ���� �� <br>
�� ���� ��ƽ�� �����ϴ� �ٸ� �ܺ� ���̺귯���� ����ؾ� �� ��? ��� �ؾ����� ����Դϴ�. <br>