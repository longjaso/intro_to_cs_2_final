/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "Tile.hpp"

Tile::Tile()
{
}

Tile::Tile(char sym, bool a)
{
	symbol = sym;
	accessible = a;
	hold = NULL;
}

Tile::~Tile()
{
	if (hold != NULL) {
		delete hold;
	}
}

char Tile::getSymbol()
{
	return symbol;
}

bool Tile::isAccessible()
{
	return accessible;
}

Item * Tile::getHoldItem()
{
	return hold;
}

/******************************************************************************************
* Description: setItem is only to be used for level generation.  This is because using it
* during run-time runs the risk of accidentally setting the symbol of a tile to something
* other than what is intended.
******************************************************************************************/
void Tile::setItem(Item *i)
{
	hold = i;
	if (i != NULL) {
		symbol = '!';
	}
}

void Tile::setSymbol(char s)
{
	symbol = s;
}
