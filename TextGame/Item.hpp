/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
using std::string;

class Item
{
private:
	string name;
	string description;

public:
	//Constructor/Destructor
	Item();
	Item(string, string);
	~Item();

	//Get Functions
	string getName();
	string getDescription();
};

#endif