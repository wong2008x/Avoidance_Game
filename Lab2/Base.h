#pragma once
#include "Console.h"
using namespace System;

class Base
{
public:
	
	int xpo;
	int ypo;
	char pic;
	WORD  Forecolor;
	WORD  Backcolor;


	int getX();
	int getY();
	void setX(int x);
	void setY(int y);

	virtual void Update();
	virtual void Render() const;
	void setChar(char c);

	Base();
	~Base();
private:
	//Why do I need this shit
	/*int xpo;
	int ypo;*/
};

