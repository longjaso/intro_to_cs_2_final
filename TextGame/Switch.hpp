/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "Tile.hpp"
#include "Blockade.hpp"
#include "Door.hpp"
#include "Floor.hpp"
#include "Terminal.hpp"

/******************************************************************************************
* Description: The name may be confusing since switch is a keyword.  This is meant as an
* actual on/off switch.  Think "Light Switch" or "Lever".  This is generally bad practice
* but for the sake of making sense, this name is the most accurate.
******************************************************************************************/
class Switch : public Tile
{
private:
	bool on;
	string setName;
	Switch *dependent1;
	Switch *dependent2;
	Tile *affected;
	Tile *affected2;
	Tile *affected3;

public:
	Switch();
	Switch(bool, string);
	~Switch();

	//Inherited Virtual Functions
	string getInteract(string optional = "");
	string getInvestigate();

	//Get Functions
	bool getOn();
	Tile* getAffected();
	Switch * getD1();
	Switch * getD2();

	//Set Functions
	void setOn(bool);
	void setDep1(Switch*);	//Declaring the switch for dependent1
	void setDep2(Switch*);	//Declaring the switch for dependent2
	void setAffected(Tile*);
	void setAffected2(Tile *);
	void setAffected3(Tile *);

	//Other Functions
	void alternate();
	string alternateSpecial();
};

#endif