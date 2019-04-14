#pragma once
#include "Base.h"
#include "Obstacle.h"
#include<vector>
#include<iostream>
using namespace std;

class Game:public Base
{
	
public:
	struct Data
	{
		char name[32];
		int score;
		int difficulty;

	};
	bool play;
	vector <Base*> obj;
	int level;
	void Quit();
	int Askint();
	void Textout();
	void Textin();
	void Binaryout();
	void Binaryin();
	void Customout(char out);
	void Customin(char in);
	void Endmenu();
	void Collision();
	void Update();
	void Render();
	Game();
	~Game();
};

