/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "Terminal.hpp"

Terminal::Terminal() : Tile('C', true)
{
	end = false;
	isBroken = false;
	isLocked = false;
	itemName = "";
	affected = NULL;
}

Terminal::Terminal(bool ignore) : Tile('X', false)
{
	end = false;
	isBroken = true;
	isLocked = false;
	itemName = "";
	affected = NULL;
}

Terminal::Terminal(bool locked, string iName, string cName, Tile *affect) : Tile('C', true)
{
	end = false;
	isBroken = false;
	isLocked = locked;
	itemName = iName;
	compName = cName;
	affected = affect;
}

Terminal::~Terminal()
{
}

string Terminal::getInteract(string o)
{
	string ret = "";
	if (isLocked && itemName != "" && o != "") {
		if (itemName == o) {
			ret = "The computer has accepted the Key Card.";
			if (dynamic_cast<Door*>(affected)) {
				ret += "\n" + affected->getInteract(compName);
			}
			//Game End Verification
			if ((itemName == o) && (o == "Captain Key Card")) {
				ret = "The computer has accepted the Key Card.  Life support is back on!";
				end = true;
			}
		}
		else
			ret = "These two things don't go together.";
	}
	else if (isBroken) {
		ret = "This computer is just a junk heap now. I can't use it.";
	}
	else
		ret = "I should find something to use with this computer.";

	return ret;
}

string Terminal::getInvestigate()
{
	string ret = "";
	if (isLocked) {
		ret = "This computer is locked.  There might be something I can use to unlock it.";
	}
	if (isBroken) {
		ret = "It's weird.  This ship looks fine.  Just random things like this computer are broken.";
	}
	return ret;
}

bool Terminal::getEnd()
{
	return end;
}
