#include "Player.h"

//constructor
Player::Player(int playerID, int x, int y)
{
	this->x = x;
	this->y = y;
	this->playerID = playerID;
}

//getter of player ID
int Player::getPlayerID()
{
	return this->playerID;
}

//getter of x
int Player::getXcoord()
{
	return this->x;
}

//getter of y
int Player::getYcoord()
{
	return this->y;
}

//setter of ID
void Player::setPlayerID(int newPlayerID)
{
	this->playerID = newPlayerID;
}

//set new values for x, y
void Player::setCoord(int newXcoord, int newYcoord)
{
	this->x = newXcoord;
	this->y = newYcoord;
}