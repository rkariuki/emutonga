#include "Board.h"


//this file implements the methods defined in the Board.h

//constructor
//m: size of the board m x m
//precondition: m > 0
Board::Board(int m){
	this->m = m;
	this->n = 0;
}

//destructor
Board::~Board(){

}

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
void Board::Insert(int id, int x, int y){

	//validate x, y
	if (x < 1 || x > m || y < 1 || y > m)
	{
		cout << "The position is invalid" << endl;
		return;
	}

	//validate n
	if (n == m)
	{
		cout << "The total number of players should not exceed " << m << endl;
		return;
	}

	//find by player id
	if (players.find(id) != players.end())
	{//found
		cout << "Player " << id << " already exist on the board" << endl;
	}else{ //id not found

		//check if upoccupied
		map<int, pair<int, int> >::iterator itr; 

		//iterate the map to check if (x,y) is occupied
		for (itr = players.begin(); itr != players.end(); ++itr) { 

			//occupied already
			if (itr->second.first == x && itr->second.second == y)
			{
				cout << "Player " << itr->first << " already exist on the position (" 
					<< x << "," << y << ")" << endl;
				return;
			}
		} 
  
		// update board and n
		players.insert(pair<int, pair<int, int> > (id, pair<int, int>(x, y)));

		n++; //increase number of players
	}
}

/*
remove the player with id from the board
return true if player id is on board and is removed; otherwise, return false
poscondition: if true, board is updated, n is updated
*/
bool Board::Remove(int id){
	//find by player id
	map<int, pair<int, int> >::iterator itr = players.find(id);

	if (itr != players.end())
	{//found

		//remove this player with id
		players.erase(itr);

		n--;//reduce number of players

		return true;
	}else{ //id not found
		return false;
	}
}

/*
find the player with id on board
return true if found; otherwise, return false
*/
bool Board::Find(int id){
	//find by player id
	if (players.find(id) != players.end())
	{//found
		return true;
	}else{ //id not found
		return false;
	}
}

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
void Board::MoveTo(int id, int x2, int y2){

	//validate x, y
	if (x2 < 1 || x2 > m || y2 < 1 || y2 > m)
	{
		cout << "The position is invalid" << endl;
		return;
	}

	//find by player id
	map<int, pair<int, int> >::iterator itr = players.find(id);

	if (itr != players.end())
	{//found
		
		//current position of player 
		int x = itr->second.first;
		int y = itr->second.second;

		//check same location
		if (x == x2 && y == y2)
		{
			cout << "The positions are the same" << endl;
			return;
		}

		//try to move (x,y) to (x2,y2)

		//same row, same column or same diagonal ?
		if (x == x2 || y == y2 || abs(x - x2) == abs(y - y2)){

			//position x2, y2 is empty or occupied
			//iterate the map to check if (x,y) is occupied
			map<int, pair<int, int> >::iterator itr2;
			for (itr2 = players.begin(); itr2 != players.end(); ++itr2) { 

				//occupied already
				if (itr2->second.first == x2 && itr2->second.second == y2)
				{
					cout << "Player " << itr2->first << " on the position (" 
						<< x2 << "," << y2 << ") has been replaced by player " << id << endl;

					//erase current user (x2,y2)
					players.erase(itr2);

					//replace with old location
					players.erase(itr);
					players.insert(pair<int, pair<int, int> > (id, pair<int, int>(x2, y2)));

					n--;//reduce number of players

					return;
				}
			} 

			//x2, y2 is empty
			//replace with old location
			players.erase(itr);
			players.insert(pair<int, pair<int, int> > (id, pair<int, int>(x2, y2)));

			cout << "Player " << id << " has been moved to the position (" 
						<< x2 << "," << y2 << ") successfully" << endl;
		}else{
			cout << "The new position must be in the same row, same column or same diagonal" << endl;
		}
		
	}else{ //id not found
		cout << "The player " << id << " not found" << endl;
	}
}

/*
print all the player IDs along with their (x,y) positions
in the increasing order of IDS
*/
void Board::PrintByID(){

	//map iterator
	map<int, pair<int, int> >::iterator itr; 

	//iterate the map
	for (itr = players.begin(); itr != players.end(); ++itr) {		
		cout << "player " << itr->first << " @ (" << itr->second.first << "," << itr->second.second << ")" << endl;
	} 
}
