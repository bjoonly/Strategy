#include "Game.h"

Game::Game() :moveNumber(0), strategy(new StrategyPlus2()), playerPos(0, 0), goal(0), SIZER(6), SIZEC(25) {
	field = new char* [SIZER];
	for (int i = 0; i < SIZER; i++) {
		field[i] = new char[SIZEC];
	}
	for (int i = 0; i < SIZER; i++) {
		for (int j = 0; j < SIZEC; j++)
			field[i][j] = ' ';
	}
}

Game::~Game() {
	for (int i = 0; i < SIZER; i++)
		delete[] field[i];
	delete[]field;
}

void Game::FillField() {

	int random = 0;
	if (moveNumber == 0) {
		random = rand() % 25;
		playerPos.x = 0;
		playerPos.y = random;
	}
	random = rand() % SIZEC - 1;

	for (int i = 0; i < SIZER; i++) {
		for (int j = 0; j < SIZEC; j++) {
			if (i == playerPos.x && j == playerPos.y)
				field[i][j] = '$';
			else if ((i == SIZER - 1 && (j != random && j != random + 1)) || (moveNumber != 0 && i == 0 && (j != goal && j != goal + 1)))
				field[i][j] = 'X';
			else
				field[i][j] = ' ';
		}
	}
	goal = random;
}

bool Game::MovingOnTheField() {
	int move = strategy->Move();
	field[playerPos.x][playerPos.y] = ' ';
	playerPos.x++;

	if (playerPos.y + move > SIZEC - 1) {
		move -= SIZEC - playerPos.y;
		playerPos.y = 0;
	}
	else if (playerPos.y + move < 0) {
		move += playerPos.y;
		playerPos.y = SIZEC;
	}
	playerPos.y += move;
	if (playerPos.x == SIZER - 1 && playerPos.y != goal && playerPos.y != goal + 1) 
		return false;
	

	if (playerPos.x == SIZER - 1)
		playerPos.x = 0;


	field[playerPos.x][playerPos.y] = '$';
	moveNumber++;
	return true;
}

void Game::SetStrategy(Strategy* strategy) {
	this->strategy = strategy;
}

void Game::Show() const {
	for (int i = 0; i < SIZER; i++) {
		cout << i << "| ";
		for (int j = 0; j < SIZEC; j++) {
			if (isspace(field[i][j]))
				cout << " ";
			else
				cout << field[i][j];

			cout << " | ";
		}
		cout << endl;
	}
}

int Game::GetMoveNumber() const {
	return moveNumber;
}