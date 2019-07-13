/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "Floor.hpp"

Floor::Floor() : Tile(' ', true)
{
	itemHidden = false;
}

Floor::~Floor()
{
}

void Floor::setItemHidden(bool hidden)
{
	itemHidden = hidden;
	if (hold == NULL || hidden) {
		symbol = ' ';
	}
	else if (!hidden && hold != NULL) {
		symbol = '!';
	}
}

string Floor::getInteract(string optional)
{
	string ret = "";
	if (itemHidden && optional != "") {
		setItemHidden(false);
		ret += "A secret has been revealed!";
	}
	else {
		ret = "There's nothing I can do with the floor.";
	}
	return ret;
}

string Floor::getInvestigate()
{
	string ret = "";
	if (hold == NULL) {
		ret = "The floor is made of some type of metal.  Looks sturdy.";
	}
	else if (hold != NULL) {
		ret = "There's an item here.  I should pick this up.";
	}

	return ret;
}
