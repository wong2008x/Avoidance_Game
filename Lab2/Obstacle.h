#pragma once
#include "Base.h"
class Obstacle:public Base
{
public:
	int point;
	int speed;
	void Update();
	int getPoint();
	Obstacle();
	~Obstacle();
};

