/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include "Tile.hpp"
#include "Door.hpp"

class Terminal : public Tile
{
private:
	bool end;
	bool isBroken;
	bool isLocked;
	string itemName;
	string compName;
	Tile *affected;

public:
	Terminal();
	Terminal(bool);
	Terminal(bool, string, string, Tile*);
	~Terminal();

	string getInteract(string = "");
	string getInvestigate();
	bool getEnd();
};

#endif