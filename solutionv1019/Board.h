#ifndef BOARD__H  //prevent to include many times
#define BOARD__H

#include <iostream>
#include <map> 
#include <functional> 
#include <cmath>  //for abs function
using namespace std;

/*
Board class represents a board
*/
class Board
{
public:

	//constructor
	//m: size of the board m x m
	//precondition: m > 0
	Board(int m);

	//destructor
	~Board();

	/*
	insert the player with id = id at
	(x, y) position
	condition:
	 (i) a player with the same ID should not already exist on the board; AND 
	 (ii) the specified insertion position on board should be currently
	      unoccupied; AND
     (iii) ensure the total number of  players with this 
	      insertion (i.e., n) should not exceed m
	poscondition: board is updated or error message is printed
	*/
	void Insert(int id, int x, int y);

	/*
	remove the player with id from the board
	return true if player id is on board and is removed; otherwise, return false
	poscondition: if true, board is updated, n is updated
	*/
	bool Remove(int id);

	/*
	find the player with id on board
	return true if found; otherwise, return false
	*/
	bool Find(int id);

	/*
	move the player to new position (x2, y2)
	condition:
	(x2,y2) is within bounds, AND
	the movement from (x1, y1) to (x2, y2) is always along the same
    row or same column or same diagonal in any direction 
	(i.e., topleft -- right-bottom or top-right -- left-bottom)

	poscondition: the player at new position is removed if any
	              message is displayed to show the any action or failure to move
	*/
	void MoveTo(int id, int x2, int y2);

	/*
	print all the player IDs along with their (x,y) positions
	in the increasing order of IDS
	*/
	void PrintByID();

private:
	//board has size m x m
	int m;

	//number of players
	int n;

	//map of player id with its position
	//sorted by id
	map<int, pair<int, int>, less <int> > players;
};

#endif