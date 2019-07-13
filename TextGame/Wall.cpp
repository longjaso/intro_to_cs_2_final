/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "Wall.hpp"

Wall::Wall() : Tile('#', false)
{
	isSpecial = false;
}

Wall::Wall(bool ignore) : Tile('?', false)
{
	isSpecial = true;
}

Wall::~Wall()
{
}

string Wall::getInteract(string)
{
	string ret = "";
	if (isSpecial) {
		ret = "There's something etched here...";
	} 
	else {
		ret = "There's nothing to do with this wall.";
	}

	return ret;
}

string Wall::getInvestigate()
{
	string ret = "";
	if (isSpecial) {
		ret += "There are markings on this wall.\n";
		ret += "|||||  |||||  |||||  |||||\n|||||  |||||  |||||  |||||\n|||||  |";
	}
	else {
		ret = "It\'s a wall.";
	}
	return ret;
}
