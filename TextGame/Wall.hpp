/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef WALL_HPP
#define WALL_HPP

#include "Tile.hpp"

class Wall : public Tile
{
private:
	bool isSpecial;

public:
	Wall();
	Wall(bool);
	~Wall();

	string getInteract(string = "");
	string getInvestigate();
};

#endif