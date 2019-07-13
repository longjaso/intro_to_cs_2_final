/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef TILE_HPP
#define TILE_HPP

#include "Item.hpp"
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

class Tile
{
protected:
	Item *hold;
	char symbol;
	bool accessible;

public:
	Tile();
	Tile(char, bool);
	virtual ~Tile();

	//Get Functions
	char getSymbol();
	bool isAccessible();
	Item* getHoldItem();

	/**************************************************************************************
	* Description: These pure virutal functions will be used across all of the tiles in the
	* game.  These functions will allow the player to learn about their environment and
	* progress through it via interacting and investigating.  Each derived tile will have
	* its own unique set of interactions and interactions.
	**************************************************************************************/
	virtual string getInvestigate() = 0;
	virtual string getInteract(string = "") = 0;

	//Set Functions
	void setItem(Item*);
	void setSymbol(char);
};

#endif