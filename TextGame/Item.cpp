/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "Item.hpp"

Item::Item()
{
	name = "";
	description = "";
}

Item::Item(string n, string d)
{
	name = n;
	description = d;
}

Item::~Item()
{
}

string Item::getName()
{
	return name;
}

string Item::getDescription()
{
	return description;
}