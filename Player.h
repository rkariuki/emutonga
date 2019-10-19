#pragma once
using namespace std;
#include<iostream>

class Player
{
public:
	Player(int playerID, int x, int y);
	~Player();

	int getPlayerID();
	int getXcoord();
	int getYcoord();

	void setPlayerID(int newPlayerID);
	void setCoord(int newXcoord, int newYcoord);

private:
	int x, y, playerID;

};