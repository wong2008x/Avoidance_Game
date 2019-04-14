#include "pch.h"
#include "Base.h"
#include "Console.h"
#include<iostream>

using namespace std;
using namespace System;


Base::Base()
{
}
int Base::getX() {
	return xpo;
}
int Base::getY() {
	return ypo;
}
void Base::setX(int x){
	xpo = x;
}
void Base::setY(int y){
	ypo = y;
}
void Base::setChar(char n) {
	pic = n;
}
void Base::Update() {

}
void Base::Render() const{
	
	Console::ForegroundColor(Forecolor);
	Console::BackgroundColor(Backcolor);
	Console::Show(xpo, ypo, pic);
	Console::ResetColor();
	
	
}

Base::~Base()
{
}
