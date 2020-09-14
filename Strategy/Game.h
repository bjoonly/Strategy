#pragma once
#include<ctime>
#include<iostream>
#include<Windows.h>
#include"Strategy.h"
using namespace std;


struct Position {
	int x;
	int y;
	Position(int x, int y) :x(x), y(y) {}
};


class Game {
	const int SIZER ;
	const int SIZEC ;
	char**field;
	Position playerPos;
	int goal;
	Strategy* strategy;
	int moveNumber;
public:
	Game();
	~Game();
	void FillField();
	bool MovingOnTheField();
	void SetStrategy(Strategy* strategy);
	void Show()const;
	int GetMoveNumber()const;
};




