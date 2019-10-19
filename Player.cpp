#include "Player.h"

Player::Player(int playerID, int x, int y)
{
	this->x = x;
	this->y = y;
	this->playerID = playerID;
}

Player::~Player()
{

}

int Player::getPlayerID()
{
	return this->playerID;
}

int Player::getXcoord()
{
	return this->x;
}

int Player::getYcoord()
{
	return this->y;
}

void Player::setPlayerID(int newPlayerID)
{
	this->playerID = newPlayerID;
}

void Player::setCoord(int newXcoord, int newYcoord)
{
	this->x = newXcoord;
	this->y = newYcoord;
}