/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "Door.hpp"

/* --- DOOR CONSTRUCTORS --- READ THE NOTES --- */
/******************************************************************************************
* Description: Interior - Unlocked
******************************************************************************************/
Door::Door() : Tile('=', true)
{
	doorNextRoomX = 0;
	doorNextRoomY = 0;
	requiresItem = false;
	doorName = "";
	itemName = "";
}

/******************************************************************************************
* Description: Interior - Locked
******************************************************************************************/
Door::Door(bool f, string n) : Tile('=', false)
{
	doorNextRoomX = 0;
	doorNextRoomY = 0;
	requiresItem = false;
	doorName = "A door";
	itemName = "";
}

/******************************************************************************************
* Description: Interior - Locked - Name Specific Unlocker
******************************************************************************************/
Door::Door(bool ignore, string i, string d) : Tile('=', false) 
{	
	doorNextRoomX = 0;
	doorNextRoomY = 0;
	requiresItem = false;
	itemName = i;
	doorName = d;
}

/******************************************************************************************
* Description: Map Connector - Unlocked
******************************************************************************************/
Door::Door(int y, int x) : Tile('=', true)
{
	doorNextRoomX = x;
	doorNextRoomY = y;
	requiresItem = false;
	itemName = "";
	doorName = "";
}

/******************************************************************************************
* Description: Map Connector - Locked
******************************************************************************************/
Door::Door(bool ignore, int y, int x) : Tile('=', false)
{
	doorNextRoomX = x;
	doorNextRoomY = y;
	requiresItem = false;
	doorName = "A door";
	itemName = "";
}

/******************************************************************************************
* Description: Map Connector - Locked - Name Specific Unlocker
******************************************************************************************/
Door::Door(bool ignore, int y, int x, string i, string n) : Tile('=', false)
{
	doorNextRoomX = x;
	doorNextRoomY = y;
	requiresItem = true;
	itemName = i;
	doorName = n;
}

Door::~Door()
{
}

int Door::getDoorNextRoomX()
{
	return doorNextRoomX;
}

int Door::getDoorNextRoomY()
{
	return doorNextRoomY;
}

string Door::getInteract(string o)
{
	string ret = "";
	if (!accessible && doorName == "Airlock" && itemName != "" && o != "") {
		if (itemName == o) {
			ret = "The Airlock has opened!  The debris clogged the open airlock\n... this may need to be addressed later.";
			symbol = 'X';
		}
	}
	else if (!accessible && itemName != "" && o != "") {
		if (itemName == o) {
			accessible = true;
			ret = doorName + " has been unlocked!";
		}
		else {
			ret = "These two things don\'t go together.";
		}
	}
	else
		ret = getInvestigate();

	return ret;
}

string Door::getInvestigate()
{
	string ret = "";
	if (!accessible && doorName == "") {
		ret =  "This door is locked.";
	}
	else if (!accessible && doorName != "") {
		ret = "This is the " + doorName + ". It is locked";
	}
	else if (doorName != "") {
		ret = "This is the " + doorName;
	}
	else {
		ret = "This door is fairly ordinary";
	}

	return ret;
}
