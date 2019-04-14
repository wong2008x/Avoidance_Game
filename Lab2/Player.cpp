#include "pch.h"
#include "Player.h"
#include "Base.h"
#include "Console.h"
#include <stdlib.h>
using namespace System;
using namespace std;



Player::Player()
{
	xpo = Console::WindowWidth() / 2;
	ypo = Console::WindowHeight();
	pic = 'n';
	
	score = 0;
	Forecolor = Yellow;
	Backcolor = DarkBlue;
}


void Player::goLeft() {
	
	if (xpo > 0) {
		xpo--;
	}
	else {
		/*xpo = 0;*/
		xpo = Console::WindowWidth();
	}
}
void Player::goRight() {
	if (xpo < Console::WindowWidth()) {
		xpo++;
	}
	else {
		/*xpo = Console::WindowWidth();*/
		xpo = 0;
	}
}
void Player::goDown() {
	if (ypo < Console::WindowHeight()) {
		ypo++;
	}
	else {
		/*ypo = Console::WindowHeight();*/
		ypo = 0;
	}
}
void Player::goUp() {
	if (ypo > 0) {
		ypo--;
	}
	else {
		/*ypo = 0;*/
		ypo = Console::WindowHeight();
	}
}

void Player::Update() {
	if (GetAsyncKeyState(VK_LEFT)) {
		goLeft();
	}
	else if (GetAsyncKeyState(VK_UP)) {
		goUp();
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		goRight();
	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		goDown();
	}
}
void Player::Render() {
	
	Console::SetCursorPosition(0, 0);
	cout << "Score:" << score;
	Console::SetCursorPosition(0, 1);
	cout << "Name:" << name;

	Base::Render();
	
}


Player::~Player()
{
}
