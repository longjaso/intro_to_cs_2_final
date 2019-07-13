/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "StasisCapsule.hpp"

StasisCapsule::StasisCapsule() : Tile ('O', false)
{
	isOpenable = false;
	hasOpened = false;
	isSpecial = false;
}

StasisCapsule::StasisCapsule(bool ignore) : Tile ('O', false)
{
	isOpenable = true;
	hasOpened = false;
	isSpecial = true;
}

StasisCapsule::~StasisCapsule()
{
}

bool StasisCapsule::getIsOpenable()
{
	return isOpenable;
}

bool StasisCapsule::getHasOpened()
{
	return hasOpened;
}

string StasisCapsule::getInteract(string o)
{
	string ret = "";
	if (isSpecial && !hasOpened && o == "Small Note") {
		hasOpened = true;
		ret = "The capsule opened! This person has a Key Card on them.";
		Item *greenKeyCard = new Item("Green Key Card", "This Key Card has \"Crew Member\" written on it.  That will come in handy");
		hold = greenKeyCard;
	}
	else if (isSpecial && hasOpened) {
		ret = "This person smells odd.";
	}
	else if (isSpecial && !hasOpened) {
		ret = "The keypad on this is lit up.  Looks like it can be opened.";
	}
	else
		ret = "Doesn't look like this can be opened.";

	return ret;
}

string StasisCapsule::getInvestigate()
{
	if (isSpecial && !hasOpened) {
		return "It looks like this Cryo-Stasis pod can be opened ...";
	}
	else if (isSpecial && hasOpened && hold != NULL) {
		return "This person has a Key Card on them.  I should grab that.";
	}
	else if (isSpecial && hasOpened && hold == NULL) {
		return "I've searched through this Cryo-Stasis pod pretty thoroughly.";
	}
	else {
		return "It's a stasis capsule. \nThis person is frozen solid...";
	}
}

void StasisCapsule::setIsOpenable(bool val)
{
	isOpenable = val;
}

void StasisCapsule::setHasOpened(bool val)
{
	hasOpened = val;
}