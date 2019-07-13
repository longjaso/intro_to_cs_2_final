/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef DOOR_HPP
#define DOOR_HPP

#include "Tile.hpp"
class Door : public Tile
{
private:
	int doorNextRoomX;
	int doorNextRoomY;
	bool requiresItem;
	string doorName;
	string itemName;

public:
	Door();
	Door(bool, string);
	Door(bool, string, string);
	Door(int, int);
	Door(bool, int, int);
	Door(bool, int, int, string, string);
	~Door();

	//Get Functions
	int getDoorNextRoomX();
	int getDoorNextRoomY();

	//Other Functions
	string getInteract(string = "");
	string getInvestigate();
};

#endif