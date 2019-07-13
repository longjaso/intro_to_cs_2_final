/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "Location.hpp"

/* --- CONSTRUCTOR/DESTRUCTOR --- */
Location::Location()
{
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
	map = NULL;
	len = 0;
	width = 0;
	roomName = "";
}

Location::Location(int y, int x, string name)
{
	len = y;
	width = x;

	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;

	mapGeneration();

	roomName = name;
}

Location::~Location()
{
	deleteMap();
}

/* --- GET FUNCTIONS --- */
string Location::getRoomName()
{
	return roomName;
}

Tile *** Location::retMap()
{
	return map;
}

Tile * Location::retCell(int y, int x)
{
	return map[y][x];
}

Location * Location::getNorth()
{
	return north;
}

Location * Location::getEast()
{
	return east;
}

Location * Location::getSouth()
{
	return south;
}

Location * Location::getWest()
{
	return west;
}

int Location::getLen()
{
	return len;
}

int Location::getWidth()
{
	return width;
}

/* --- SET FUNCTIONS --- */
void Location::setNorth(Location *room)
{
	north = room;
}

void Location::setEast(Location *room)
{
	east = room;
}

void Location::setSouth(Location *room)
{
	south = room;
}

void Location::setWest(Location *room)
{
	west = room;
}

/* ----------------------------------- MAP FUNCTIONS ----------------------------------- */
/******************************************************************************************
* Description: Uses the location's len and width to build a 2D array of the specified size.
*******************************************************************************************/
void Location::mapGeneration()
{
	//Instantiating Map
	map = new Tile**[len];
	for (int row = 0; row < len; ++row) {
		map[row] = new Tile*[width];
	}

	//Setting up initial map (walls as boundaries, floor everywhere else)
	for (int row = 0; row < len; row++) {
		for (int col = 0; col < width; col++) {
			if (row == 0 || row == len - 1
				|| col == 0 || col == width - 1) {
				map[row][col] = new Wall;
			}
			else {
				map[row][col] = new Floor;
			}
		}
	}
}

/******************************************************************************************
* Description: manualInsert is used to replace a tile on the board with a specified tile.
* This should be a static tile that DOES NOT MOVE as this deletes the underlying tile.
******************************************************************************************/
void Location::manualInsert(Tile *toIns, int y, int x)
{
	delete map[y][x];
	map[y][x] = toIns;
}

/******************************************************************************************
* Description: manualInsertBunk inserts a bunk at specified coordinates
******************************************************************************************/
void Location::manualInsertBunk(int roomY, int roomX) {
	delete map[roomY][roomX];
	map[roomY][roomX] = new Bunk();
}

/******************************************************************************************
* Description: manualInsertBlockase inserts a blockade at specified coordinates
******************************************************************************************/
void Location::manualInsertBlockade(int roomY, int roomX, string name) {
	delete map[roomY][roomX];
	map[roomY][roomX] = new Blockade(name);
}

/******************************************************************************************
* Description: manualInsertCryoChamber inserts a StasisCapsule at specified coordinates
******************************************************************************************/
void Location::manualInsertCryoChamber(int y, int x)
{
	delete map[y][x];
	map[y][x] = new StasisCapsule;
}

/******************************************************************************************
* Description: This functions takes in two int parameters and two strings to place a locked
* interior door on the map. The first two ints (roomY and roomX) specify the door's resting
* spot on the map. The first string (iName) indicates the name that will be passed into the
* getInteract function to unlock the door. The second string indicates the actual door's
* name. This is used when the door unlocks to tell the player which door has unlocked.
******************************************************************************************/
void Location::manualInsertDoorInteriorLockedItem(int roomY, int roomX, string iName, string dName) {
	delete map[roomY][roomX];
	map[roomY][roomX] = new Door(false, iName, dName);
}

/******************************************************************************************
* Description: This functions takes in four int parameters to place an unlocked door that 
* leads to another Location.  The first two ints (roomY and roomX) specify the door's resting
* spot on the map.  The second set specify where the player will be when they cross through
* the doorway and appear in the next Location.
******************************************************************************************/
void Location::manualInsertDoorToRoomUnlocked(int roomY, int roomX, int nextY, int nextX)
{
	delete map[roomY][roomX];
	map[roomY][roomX] = new Door(nextY, nextX);
}

/******************************************************************************************
* Description: This functions takes in 4 int parameters and two strings to place a locked 
* door that leads to another Location. The first two ints (roomY and roomX) specify the 
* door's resting spot on the map. The second set specify where the player will be when they 
* cross through the doorway and appear in the next Location.  The first string (iName)
* indicates the name that will be passed into the getInteract function to unlock the door.  
* The second string indicates the actual door's name. This is used when the door unlocks to
* tell the player which specific door has unlocked.
******************************************************************************************/
void Location::manualInsertDoorToRoomLockedItem(int roomY, int roomX, int nextY, int nextX, string iName, string dName)
{
	delete map[roomY][roomX];
	map[roomY][roomX] = new Door(false, nextY, nextX, iName, dName);
}

/******************************************************************************************
* Description: manualInsertTerminalBroken inserts a broken terminal at specified coordinates
******************************************************************************************/
void Location::manualInsertTerminalBroken(int roomY, int roomX)
{
	delete map[roomY][roomX];
	map[roomY][roomX] = new Terminal(true);
}

/******************************************************************************************
* Description: manualInsertTerminalLockedItem inserts an item-specific locked terminal at
* the specified coordinates.  It requires a Tile as a paramter to know what should be
* affected by its unlocking.  It is also important to provide the item name that unlocks
* the terminal and the name of the computer to the affected tile may be provided with its
* name.
******************************************************************************************/
void Location::manualInsertTerminalLockedItem(int roomY, int roomX, bool locked, string iName, string cName, Tile *affect)
{
	delete map[roomY][roomX];
	map[roomY][roomX] = new Terminal(locked, iName, cName, affect);
}

/******************************************************************************************
* Description: This allows the user to insert walls wheever they see fit since the boundary
* drawing by default only does the edges of the map.
******************************************************************************************/
void Location::manualInsertWall(int y, int x)
{
	delete map[y][x];
	map[y][x] = new Wall;
}

void Location::displayMap()
{
	for (int row = 0; row < len; row++) {
		for (int col = 0; col < width; col++) {
			cout << map[row][col]->getSymbol() << " ";
		}
		cout << endl;
	}
}
/******************************************************************************************
* END MAP FUNCTIONS --- END MAP FUNCTIONS --- END MAP FUNCTIONS --- END MAP FUNCTIONS ---
******************************************************************************************/

/* --- DELETE FUNCTIONS --- */
void Location::deleteMap()
{
	for (int row = 0; row < len; row++) {
		for (int col = 0; col < width; col++) {
			delete map[row][col];
		}
		delete[] map[row];
	}
	delete[] map;
	cout << endl;
}

void Location::deleteDirections()
{
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
	delete north;
	delete east;
	delete south;
	delete west;
}
