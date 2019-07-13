/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "Tile.hpp"

class Floor : public Tile
{
private:
	bool itemHidden;

public:
	Floor();
	~Floor();

	void setItemHidden(bool);

	string getInteract(string = "");
	string getInvestigate();
};

#endif