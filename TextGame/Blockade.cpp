/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "Blockade.hpp"

Blockade::Blockade() : Tile('X', false)
{
	specialName = "";
}

Blockade::Blockade(string name) : Tile('X', false)
{
	specialName = name;
}

Blockade::~Blockade()
{
}

string Blockade::getInteract(string o)
{
	string ret = "";
	if ((specialName == "" && o != "") || (specialName != "" && o != "" && o != specialName)) {
		ret = "I can't use these two things together";
	}
	else if (o == specialName) {
		accessible = true;
		symbol = ' ';
	}
	else
		ret = "It would take me hours to move all of this debris.";

	return ret;
}

string Blockade::getInvestigate()
{
	string ret = "This debris looks pretty difficult to move on my own.\nI think I will need some help with this.";
	return ret;
}
