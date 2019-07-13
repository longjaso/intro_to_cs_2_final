/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "Bunk.hpp"

Bunk::Bunk() : Tile(']', false)
{
}

Bunk::~Bunk()
{
}

string Bunk::getInteract(string optional)
{
	string ret = "";
	ret = "I don't think right now is a good time to sleep.";
	return ret;
}

string Bunk::getInvestigate()
{
	string ret = "";
	ret = "This bunk doesn't look like its ever been used ...";
	return ret;
}