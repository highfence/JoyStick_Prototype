# JoyStick_Prototype
ProtoType for joyStick on Cocos2d-x engine

##조이스틱을 사용하는 프로토타입입니다.

###진행 일정
10/13 : Cocos2d-x 내부에 존재하는 함수를 사용하려고 투닥투닥. <br>
10/14~10/15 : 서형석 교수님이 추천해주신 gainput라이브러리 사용. 다만 사용하다가 문제발생. <br>
gainput 라이브러리에서 window내의 Xinput라이브러리를 사용하는 부분이 있는데, 내부에 Xinput1_4.dll이 존재하는데도 불구하고 찾지를 못해서 링크 에러가 자꾸 뜸. <br>
석민씨의 도움을 받아 겨우겨우 gainput라이브러리를 장착.<br>
10/16 : gainput라이브러리 사용 방법을 어느 정도 파악. 그러나 스틱 사용방법은 잘 모르겠음. <br>
관련 문서가 없어서, 다른 스틱 방향 제공 라이브러리를 사용해볼까 탐색. (SFML 라이브러리 등) <br>

###개요
검은 화면에 Smile이 방향키 입력을 받아 움직이는 간단한 프로그램입니다.<br>
조이스틱의 A버튼을 누르면 프로그램이 꺼지도록 만들었습니다.<br>

###Gainput 라이브러리.
우선 게임 패드를 관리하기 위하여 세팅이 필요합니다.<br>
```
gainput::InputManager manager;
gainput::InputMap map(manager)
```
gainput을 사용하기위해서는 우선 InputManager와 그를 받아 생성하는 InputMap이 필요합니다.<br>
Manager는 사용하는 라이브러리의 전체적인 세팅을 관리합니다.<br>
gainput은 입력을 map의 형태로 관리를 합니다. Map은 키를 관리하는 총괄적인 역할을 합니다.<br>

```
	manager.SetDisplaySize(visibleSize.width, visibleSize.height);
	const gainput::DeviceId padId = manager.CreateDevice<gainput::InputDevicePad>();
```
Manager를 생성한 이후 세팅을 해주어야 합니다. <br>
Line1은 manager에게 디스플레이 사이즈를 건네주는 모습입니다. <br>
Line2는 매니저에 디바이스를 만들어주는 함수입니다. CreateDevice<gainput::InputDevicePad>()를 통하여 패드의 디바이스를 생성하고 이를 padId에 저장합니다. <br>

```
	// Gamepad Key setting.
	map.MapBool(ButtonExit, padId, gainput::PadButtonA);
	map.MapBool(Left, padId, gainput::PadButtonLeft);
	map.MapBool(Right, padId, gainput::PadButtonRight);
	map.MapBool(Up, padId, gainput::PadButtonUp);
	map.MapBool(Down, padId, gainput::PadButtonDown)
```
그 이후 map에 자신이 사용할 키를 세팅해줍니다. Left, Right, Up, Down에 패드의 방향키를 세팅해주는 코드입니다. <br>

```
	manager.Update();
	if (map.GetBoolWasDown(ButtonExit)) { exit(0); }
```
그 이후 cocos2d-x의 update함수 안에 manager.Update() 함수를 넣어주고, 조건을 통하여 버튼이 눌렸는지 아닌지 확인해줍니다. <br>
cocos2d-x에서 keyPressed와 keyReleased가 있는 것 처럼, map안에도 GetBoolIsNew와 GetBoolWasDown을 통하여 같은 역할을 할 수 있습니다. <br>


## 아쉬운 점.
외부 라이브러리를 설치하는 경험이 처음이라 많이 막혔던 점.<br>
그 중에서도 예상치 못한 에러가 나서 시간을 많이 까먹음 <br>
라이브러리안에서 스틱을 지원하는 함수를 찾지 못하여 스틱으로 구현을 하지 못한 점 <br>
이 이후 스틱을 지원하는 다른 외부 라이브러리를 사용해야 할 지? 어떻게 해야할지 고민입니다. <br>


## Thanks To.
라이브러리 세팅을 도와주신 노석민, 송원석씨
