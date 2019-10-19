#pragma once
#include<iostream>
#ifndef BOARD_H
#define BOARD_H

#define MAXROWS M
#define MAXCOLMS M
#include"Player.h"
#include<vector>

using std::pair;

using namespace std;
class Board
{
	vector<int x, int y>;
public:
	Board();
	Board(const Board &b);
	~Board();

	bool vector<int x, int y> insert(const Player &p);
	void remove();
	void Find();
	void MoveTo();
	void PrintID();
private:
	int x;
	int y;
	int spot;

};

#endif // !BOARD_H