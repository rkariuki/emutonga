#ifndef PLAYER__H  //prevent to include many times
#define PLAYER__H

using namespace std;
#include<iostream>

//Player class
//represents a player that can put in a board
class Player
{
public:

	//constructor
	Player(int playerID, int x, int y);

	//getter methods
	int getPlayerID();
	int getXcoord();
	int getYcoord();

	//setter methods
	void setPlayerID(int newPlayerID);
	void setCoord(int newXcoord, int newYcoord);

private:

	//x, y coordinate (1-based)
	int x, y;

	//player ID
	int playerID;
};

#endif