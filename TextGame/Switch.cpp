/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "Switch.hpp"

Switch::Switch() : Tile ('\\', true)
{
	on = false;
	dependent1 = NULL;
	dependent2 = NULL;
	affected = NULL;
	affected2 = NULL;
	affected3 = NULL;
	setName = "";
}

/******************************************************************************************
* Description: When creating a set of switches that will be linked together, it is VERY
* IMPORTANT that you provide the EXACT same name in the constructor for entire SET.  This
* ensures that the user won't be required to use a specific switch in order to progress.
******************************************************************************************/
Switch::Switch(bool val, string name) : Tile ('\\', true)
{
	setOn(val);
	dependent1 = NULL;
	dependent2 = NULL;
	affected = NULL;
	affected2 = NULL;
	affected3 = NULL;
	setName = name;
}

Switch::~Switch()
{
}

string Switch::getInteract(string optional)
{
	string ret = "I've flipped a switch";
	ret += "\n" + alternateSpecial();
	return ret;
}

string Switch::getInvestigate()
{
	return "This switch looks like it can be flipped.";
}

bool Switch::getOn()
{
	return on;
}

Tile * Switch::getAffected()
{
	return affected;
}

Switch * Switch::getD1() {
	return dependent1;
}

Switch * Switch::getD2() {
	return dependent2;
}

/******************************************************************************************
* Description: Force a specified value for "on".  Should rarely be used outside of the
* alternate function.
******************************************************************************************/
void Switch::setOn(bool val)
{
	on = val;
	if (on == true) {
		symbol = '/';
	}
	else {
		symbol = '\\';
	}
}

/******************************************************************************************
* Description: The setDependent functions are used to set the dependent switch objects for
* this particular switch.  This will need to be called up to two times, allowing for three
* switches to be interconnected.  The dependents will (usually) also have dependents, likely
* the switch for whom it is a dependent to.  This allows the objects to interconnect into
* a circuit.
******************************************************************************************/
void Switch::setDep1(Switch *provided)
{
	dependent1 = provided;
}

void Switch::setDep2(Switch *provided)
{
	dependent2 = provided;
}

void Switch::setAffected(Tile *affect)
{
	affected = affect;
}

void Switch::setAffected2(Tile *affect)
{
	affected2 = affect;
}

void Switch::setAffected3(Tile *affect)
{
	affected3 = affect;
}

/******************************************************************************************
* Description: This function should only be used by the alternateSpecial function or ones
* like it.  Otherwise this function does nothing except flipping a switch ... which ...
* well who knows - that might provide hours of entertainment.
******************************************************************************************/
void Switch::alternate()
{
	if (on) {
		setOn(false);
	}
	else {
		setOn(true);
	}
}

/******************************************************************************************
* Description: alternateSpecial should be the main function that is called when interacting.
* This is because it will work with its dependent switches if they exist (which needs to be
* set prior to runtime).  Once the switch verifies that itself and its dependents are on, 
* it will send its setName (the name of the set of switches) to whichever tile is expecting
* the special getInteract call.
******************************************************************************************/
string Switch::alternateSpecial()
{
	string passBack = "";
	bool d1 = false;
	bool d2 = false;

	alternate();
	if (dependent1 != NULL && dependent2 != NULL) {
		//Dependent 1
		dependent1->alternate();
		d1 = dependent1->getOn();
		//Dependent 2
		dependent2->alternate();
		d2 = dependent2->getOn();

		//If everything is detected as being ON
		if (on && d1 && d2) {
			//IF THE SWITCHES OPERATE DOORS
			if (dynamic_cast<Door*>(affected)) {
				passBack += affected->getInteract(setName);
			}
			if (dynamic_cast<Door*>(dependent1->getAffected())) {
				passBack += "\n" + dependent1->getAffected()->getInteract(setName);
			}
			if (dynamic_cast<Door*>(dependent2->getAffected())) {
				passBack += "\n" + dependent2->getAffected()->getInteract(setName);
			}
		}
	}
	else if (dependent1 != NULL && dependent2 == NULL) {
		//Dependent 1
		dependent1->alternate();
		d1 = dependent1->getOn();
		//Dependent 2
		d2 = dependent1->getD2()->getOn();

		//If everything is detected as being ON
		if (on && d1 && d2) {
			//IF THE SWITCHES OPERATE DOORS
			if (dynamic_cast<Door*>(affected)) {
				passBack += affected->getInteract(setName);
			}
			if (dynamic_cast<Door*>(dependent1->getAffected())) {
				passBack += "\n" + dependent1->getAffected()->getInteract(setName);
			}
			if (dynamic_cast<Door*>(dependent1->getD2()->getAffected())) {
				passBack += "\n" + dependent1->getD2()->getAffected()->getInteract(setName);
			}
		}
	}
	else if (dependent1 == NULL && dependent2 == NULL) {
		if (on) {
			if (dynamic_cast<Door*>(affected)) {
				passBack += affected->getInteract(setName);
			}
			if (dynamic_cast<Floor*>(affected)) {
				passBack += affected->getInteract(setName);
			}
			//Below is specific to the bridge_hall
			if (dynamic_cast<Door*>(affected) && dynamic_cast<Blockade*>(affected2) && dynamic_cast<Blockade*>(affected3)) {
				affected->getInteract(setName);
				affected2->getInteract(setName);
				affected3->getInteract(setName);
			}
		}
	}

	return passBack;
}