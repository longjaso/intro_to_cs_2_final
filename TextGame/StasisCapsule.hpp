/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef STASISCAPSULE_HPP
#define STASISCAPSULE_HPP

#include "Tile.hpp"

class StasisCapsule : public Tile
{
private:
	bool isOpenable;
	bool hasOpened;
	bool isSpecial;
	
public:
	StasisCapsule();
	StasisCapsule(bool);
	~StasisCapsule();

	//Get Functions
	bool getIsOpenable();
	bool getHasOpened();
	string getInteract(string = "");
	string getInvestigate();

	//Set Functions
	void setIsOpenable(bool);
	void setHasOpened(bool);

	//Other Functions
};

#endif