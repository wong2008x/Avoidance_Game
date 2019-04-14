#pragma once
#include "Base.h"
class Player:public Base
{
public:
	Player();
	int score;
	char name[32];
	void Update();
	void Render();
	void goLeft();
	void goRight();
	void goUp();
	void goDown();
	~Player();
};

