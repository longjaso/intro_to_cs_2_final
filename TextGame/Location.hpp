/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "Blockade.hpp"
#include "Bunk.hpp"
#include "Door.hpp"
#include "Floor.hpp"
#include "StasisCapsule.hpp"
#include "Switch.hpp"
#include "Terminal.hpp"
#include "Wall.hpp"

#include <cstdlib>
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Location
{
private:
	//Self Information
	string roomName;

	//Map information
	Tile ***map;
	int len;
	int width;

	//Surrounding Information
	Location *north;
	Location *east;
	Location *south;
	Location *west;

public:
	//Constructors
	Location();
	Location(int, int, string);
	~Location();

	//Get Functions
	string getRoomName();
	Tile*** retMap();
	Tile* retCell(int, int);
	Location* getNorth();
	Location* getEast();
	Location* getSouth();
	Location* getWest();
	int getLen();
	int getWidth();

	//Set Functions
	void setNorth(Location*);
	void setEast(Location*);
	void setSouth(Location*);
	void setWest(Location*);

	//General Map Functions
	void mapGeneration();
	void manualInsert(Tile*, int, int);
	void manualInsertBunk(int, int);
	void manualInsertBlockade(int, int, string);
	void manualInsertCryoChamber(int, int);
	void manualInsertDoorInteriorLockedItem(int, int, string, string);
	void manualInsertDoorToRoomUnlocked(int, int, int, int);
	void manualInsertDoorToRoomLockedItem(int, int, int, int, string, string);
	void manualInsertTerminalBroken(int, int);
	void manualInsertTerminalLockedItem(int, int, bool, string, string, Tile*);
	void manualInsertWall(int, int);
	void displayMap();

	//Delete Functions
	void deleteMap();
	void deleteDirections();
};

#endif