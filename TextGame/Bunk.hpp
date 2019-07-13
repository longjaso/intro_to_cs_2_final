/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef BUNK_HPP
#define BUNK_HPP

#include "Tile.hpp"
class Bunk : public Tile
{
public:
	Bunk();
	~Bunk();

	string getInteract(string optional = "");
	string getInvestigate();
};

#endif