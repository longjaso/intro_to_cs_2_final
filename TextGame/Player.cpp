/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "Player.hpp"

Player::Player() : Tile('@', false)
{
	INV_SIZE = 6;
	inventory = new Item*[INV_SIZE];
	for (int count = 0; count < INV_SIZE; count++) {
		inventory[count] = NULL;
	}
	current = NULL;
}

Player::~Player()
{
	for (int count = 0; count < INV_SIZE; count++) {
		delete inventory[count];
	}
	delete[] inventory;
}

void Player::setCurrent(Location *room)
{
	current = room;
}

/******************************************************************
* Description: This function attempts to add an item to the player's
* inventory.  If it's successful, then it returns true, otherwise it
* returns false.  The calling function will need to handle this return.
******************************************************************/
bool Player::inputInventory(Item *i)
{
	bool didPlace = false;
	for (int count = 0; count < INV_SIZE && didPlace == false; count++) {
		if (inventory[count] == NULL) {
			inventory[count] = i;
			didPlace = true;
		}
	}
	return didPlace;
}

/******************************************************************
* Description: getCurrent returns the player's current LOCATION
******************************************************************/
Location * Player::getCurrent()
{
	return current;
}

string Player::getInteract(string)
{
	string ret = "";
	return ret;
}

Item ** Player::getInventory()
{
	return inventory;
}

int Player::getInventorySize()
{
	return INV_SIZE;
}

string Player::getInvestigate()
{
	return "I wish I could remember this place ...\nI feel groggy.  This must be what cryo-stasis does to people.";
}

void Player::displayInventory()
{
	int totalInvItem = 1;
	for (int count = 0; count < INV_SIZE; count++) {
		if (inventory[count] != NULL) {
			cout << totalInvItem << ".) " << inventory[count]->getName() << "| |";
		}
	}
}
