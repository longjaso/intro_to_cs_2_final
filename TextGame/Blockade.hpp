/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef BLOCKADE_HPP
#define BLOCKADE_HPP

#include "Tile.hpp"
class Blockade : public Tile
{
private:
	string specialName;

public:
	Blockade();
	Blockade(string);
	~Blockade();

	string getInteract(string = "");
	string getInvestigate();
};

#endif