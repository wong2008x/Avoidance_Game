#include "pch.h"
#include "Base.h"
#include "Console.h"
#include<iostream>
#include "Obstacle.h"
using namespace System;

Obstacle::Obstacle()
{
	
	ypo = rand() % (Console::WindowHeight() / 8);
	xpo = rand() % Console::WindowWidth() + 1;
	pic = 'U';
	point = 0;
	Forecolor = Cyan;
	Backcolor = DarkGray;
}

void Obstacle::Update() {

	ypo++;
	if(ypo >= Console::WindowHeight()) {
		ypo = rand() % (Console::WindowHeight() / 4);
		xpo = rand() % Console::WindowWidth() + 1;
		point++;
	}
}
int Obstacle::getPoint() {
	
	return point;
}

Obstacle::~Obstacle()
{
}
