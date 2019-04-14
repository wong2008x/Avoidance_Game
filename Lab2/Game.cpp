#include "pch.h"
#include "Game.h"
#include "Console.h"
#include "Player.h"
#include "Obstacle.h"
#include <iostream>
#include<fstream>
#include <vector>
using namespace System;
using namespace std;

Game::Game()
{
	Backcolor = DarkBlue;

	//first create a player
	obj.push_back(new Player());

	cout << "Enter a Level: (1-10)";
	level = Askint();
	int temp = level;
	if (temp > 0 && temp <= 10) {
		for (temp *= 3; temp > 0; temp--)
		{
			obj.push_back(new Obstacle());
		}
	}
	else {
		level = 1;
		obj.push_back(new Obstacle());
	}


	for (int i = 0; i <obj.size(); i++)
	{
		Player *playerptr = dynamic_cast<Player*>(obj[i]);
		if (playerptr != 0) {
			play = true; 
			cout << "please enter your name:  ";
			cin.ignore(INT_MAX, '\n');
			cin.getline(playerptr->name, 32);
		}
		else {
			break;
		}
	}

	for (; play; )
	{
		Console::BackgroundColor(Backcolor);
		Update();
		Render();
		Collision();
	}

	system("cls");
	Console::SetCursorPosition(Console::WindowWidth()/2, Console::WindowHeight() / 2);
	cout << "Game Over"<<endl;
	Textout();
	system("pause");
	Endmenu();
	
}



void Game::Update() {
	if (GetAsyncKeyState(VK_ESCAPE)) {
		Quit();
	}
	for ( int i = 0; i < obj.size(); i++)
	{
		obj[i]->Update();
	}
}

void Game::Render()  {
	Console::Lock(true);
	system("cls");
	for (int i = 0; i <obj.size(); i++)
	{
		Player *playerptr = dynamic_cast<Player*>(obj[i]);
		if (playerptr != 0) {
			playerptr->Render();
		}
		obj[i]->Render();
	}
	Console::Lock(false);
	Sleep(70);
}

void Game::Collision() 
{

	for (int i = 0; i < obj.size(); i++)
	{
		Player *playerptr = dynamic_cast<Player*>(obj[i]);
		if (playerptr != 0) {
			for (int j = 0; j < obj.size(); j++)
			{
				Obstacle *obst = dynamic_cast<Obstacle*>(obj[j]);
				if (obst != 0) {
					if(playerptr->getX()==obst->getX()&& playerptr->getY()==obst->getY()){
						playerptr->score-=30;
						//Game Over if score is below 0
						if (playerptr->score < 0) {
							Quit();
						}
						
					}
					if (obst->getPoint() > 0) {
						playerptr->score += obst->getPoint();
						obst->point = 0;
					}
				}
			}
		}
		else {
			break;
		}
	}
}

void Game::Endmenu() {
	while (true)
	{
		system("cls");
		cout << "Save and Load Menu  " << endl;
		cout << "1. See HighScores in Text  " << endl;
		cout << "2. Back up Copy in Binary " << endl;
		cout << "3. Read HighScores in Binary" << endl;
		cout << "4. Custom HighScore file " << endl;
		cout << "Else = Quit " << endl;

		int decision = Askint();
		if (decision == 1) {
			system("cls");
			Textin();
			system("pause");
		}
		else if (decision == 2) {
			Binaryout();
			system("pause");
		}
		else if(decision == 3){
			system("cls");
			Console::SetCursorPosition(Console::WindowWidth() / 2 - 10, 1);
		cout << "Well..."<<endl;
		Binaryin();
		system("pause");
		}
		else if (decision == 4) {

		}
		else {
			break;
		}
	}
}

int Game::Askint()
{

	bool IsValid = true;
	int num = 0;
	do
	{
		if (cin >> num)
		{
			IsValid = true;
		}
		else
		{
			IsValid = false;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid Input, please type again.\n";
		}
	} while (!IsValid);
	return num;
}

void Game::Textout() {
	fstream save;
	save.open("save.txt", ios_base::out | ios_base::app);
	if (save.is_open()) {
	for (int i = 0; i < obj.size(); i++)
	{
		Player *playerptr = dynamic_cast<Player*>(obj[i]);
		if (playerptr != 0) {
				save << playerptr ->name<< '\t' << playerptr ->score<<'\t'<<level<<'\n';
				
		}
		else {
		break;
		}
	}
	save.close();
	}
	else {
		cout << "File is already open.";
	}
}

void Game::Textin() {
	
			vector <Data> datas;
			Data data;
			fstream load;
			load.open("save.txt");
			if (load.is_open()) {

				while (true) {
					load.getline(data.name,INT_MAX,'\t');
					load >> data.score;
					load.ignore(INT_MAX, '\t');
					load >> data.difficulty;
					load.ignore(INT_MAX, '\n');
					if (load.eof())
						break;
					datas.push_back(data);
				}
				load.close();
			}
			else {
				cout << "File is already open.";
			}
			Console::SetCursorPosition(Console::WindowWidth() / 2 - 10, 0);
			cout << "Name" << '\t' << "Score" << '\t' << "Level" << '\n';
			for (int i = 0; i < datas.size(); i++)
			{
				Console::SetCursorPosition(Console::WindowWidth() / 2 - 10, i+1);
				cout << datas[i].name << '\t' << datas[i].score << '\t' << datas[i].difficulty << '\n';
			}

			//empty vector and its memory
			datas.clear();
			datas.shrink_to_fit();
		}
void Game::Binaryout() {

	//read the main save first
	vector <Data> datas;
	Data data;
	fstream load;
	load.open("save.txt");
	if (load.is_open()) {

		while (true) {
			load.getline(data.name, INT_MAX, '\t');
			load >> data.score;
			load.ignore(INT_MAX, '\t');
			load >> data.difficulty;
			load.ignore(INT_MAX, '\n');
			if (load.eof())
				break;
			datas.push_back(data);
		}
		load.close();
	}
	else {
		cout << "File is already open.";
	}
	fstream binsave;
	int *p;   //  the instruction said that I need to use Int.
	int a = datas.size();
	p = &a;
	binsave.open("save.bin", ios_base::out | ios_base::binary| ios_base::trunc);
	if (binsave.is_open()) {
		
		binsave.write((char*)p,sizeof(int));
		binsave.write((char*)&datas[0], datas.size()*sizeof(Data));
		binsave.close();
	}
	else {
		cout << "File is already open(binary).";
	}
	//empty vector and its memory
	datas.clear();
	datas.shrink_to_fit();
	}
void Game::Binaryin() {
	Data data;
	int number;
	fstream loadbin;
	loadbin.open("save.bin",ios_base::in | ios_base::binary);
	if (loadbin.is_open()) {

		loadbin.read((char*)&number, sizeof(int));
		cout << "We have " << number << " records."<<"\n";
		cout << "Name" << '\t' << "Score" << '\t' << "Level" << '\n';

		//Don't want to do the calculation anymore... Just READ TO THE END OF THE FILE!!
		while (loadbin.read((char*)&data,sizeof(data))) {
			cout<<data.name << '\t' << data.score << '\t' << data.difficulty << '\n';
		}
		loadbin.close();
	}
	else {
		cout << "something happened...";
	}
	

}
void Game::Quit() {
	play = false;
}

Game::~Game()
{
	for (int i = 0; i < obj.size(); i++)
	{
		delete obj[i];
	}
}
