/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Tile.hpp"
#include "Location.hpp"

class Player : public Tile
{
private:
	int INV_SIZE;
	Item **inventory;
	Location *current;

public:
	//Constructor/Destructor
	Player();
	~Player();

	//Set Functions
	void setCurrent(Location*);
	bool inputInventory(Item*);

	//Get Functions
	Location* getCurrent();
	string getInteract(string = "");
	Item** getInventory(); 
	int getInventorySize();
	string getInvestigate();

	//Other Functions
	void displayInventory();
};

#endif