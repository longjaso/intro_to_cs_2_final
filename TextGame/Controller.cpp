/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#include "Controller.hpp"

/* ---------------------------- INSTANTIATION FUNCTIONS ---------------------------- */
/******************************************************************************************
* Description: Instatiation Functions are the actual 2D array generators, Item creators, etc. 
* for each individual map of the starship.  In order to use an "init" function for a given 
* map, there must be an existing pointer to hold this information.  This can include anything
* from walls and doors to switches and terminals.  Items will be instantiated in the initItems 
* function.
******************************************************************************************/
void Controller::initBridge()
{
	bridge = new Location(7, 11, "Bridge");

	/*--- Additional Walls --- */
		//Row 1
	bridge->manualInsertWall(1, 1); bridge->manualInsertWall(1, 2); 
	bridge->manualInsertWall(1, 8); bridge->manualInsertWall(1, 9);
		//Row 2
	bridge->manualInsertWall(2, 1); bridge->manualInsertWall(2, 2);
	bridge->manualInsertWall(2, 8); bridge->manualInsertWall(2, 9);
		//Row 3
	bridge->manualInsertWall(3, 1); bridge->manualInsertWall(3, 2);
	bridge->manualInsertWall(3, 8); bridge->manualInsertWall(3, 9);
		//Row 4
	bridge->manualInsertWall(4, 1); bridge->manualInsertWall(4, 9);

	/* --- Doors --- */
	bridge->manualInsertDoorToRoomUnlocked(6, 5, 0, 2);

	/* --- Terminals --- */
	bridge->manualInsertTerminalBroken(3, 4); bridge->manualInsertTerminalLockedItem(3, 6, true, "Captain Key Card", "BTerm", bridge->retCell(0, 0));
	bridge->manualInsertTerminalBroken(4, 3); bridge->manualInsertTerminalBroken(4, 7);
}

void Controller::initCryoStasis()
{
	/* --- To Insert --- */
	StasisCapsule *special = new StasisCapsule(true);

	cryo_stasis = new Location(10, 6, "Cryo-Stasis");

	/* --- Doors --- */
	cryo_stasis->manualInsertDoorToRoomLockedItem(4, 0, 5, 10, "Green Key Card", "Cryo Stasis Door");

	/* --- Decor --- */
		//Row 1
	cryo_stasis->manualInsertCryoChamber(1, 1); cryo_stasis->manualInsertCryoChamber(1, 3);
		//Row 2
	cryo_stasis->manualInsertCryoChamber(2, 4);

		//Row 4
	cryo_stasis->manualInsertCryoChamber(4, 4);
		//Row 5
	cryo_stasis->manualInsertCryoChamber(5, 4);
		//Row 7
	cryo_stasis->manualInsert(special, 7, 4);
		//Row 8
	cryo_stasis->manualInsertCryoChamber(8, 1); cryo_stasis->manualInsertCryoChamber(8, 3);
}

void Controller::initHallBridge()
{
	/* --- To Insert --- */
	Switch *airlockRelease = new Switch(false, "Release");

	hall_bridge = new Location(5, 5, "Bridge Corridor");

	/* --- Doors --- */
	hall_bridge->manualInsertDoorToRoomUnlocked(0, 2, 6, 5);
	hall_bridge->manualInsertDoorToRoomLockedItem(2, 4, 0, 0, "Release", "Airlock");
	hall_bridge->manualInsertDoorToRoomUnlocked(4, 2, 0, 5);

	/* --- Blockades --- */
	hall_bridge->manualInsertBlockade(1, 2, "Release");
	hall_bridge->manualInsertBlockade(2, 1, "Release");

	/* --- Switches --- */
	hall_bridge->manualInsert(airlockRelease, 3, 3);
	airlockRelease->setAffected(hall_bridge->retCell(2, 4));
	airlockRelease->setAffected2(hall_bridge->retCell(1, 2));
	airlockRelease->setAffected3(hall_bridge->retCell(2, 1));
}

void Controller::initJunctionRoom()
{
	/* --- To Insert --- */
	Switch *top = new Switch(false, "Junction");
	Switch *middle = new Switch(true, "Junction");
	Switch *bottom = new Switch(false, "Junction");

	junction_room = new Location(8, 11, "Junction Room");

	/* --- Additional Walls --- */
		//Row 2
	junction_room->manualInsertWall(2, 3); junction_room->manualInsertWall(2, 4);
	junction_room->manualInsertWall(2, 6); junction_room->manualInsertWall(2, 7);
		//Row 3
	junction_room->manualInsertWall(3, 3); junction_room->manualInsertWall(3, 4);
	junction_room->manualInsertWall(3, 5); junction_room->manualInsertWall(3, 6);
	junction_room->manualInsertWall(3, 7);
		//Row 4
	junction_room->manualInsertWall(4, 3); junction_room->manualInsertWall(4, 4);
	junction_room->manualInsertWall(4, 5); junction_room->manualInsertWall(4, 6);
	junction_room->manualInsertWall(4, 7);
		//Row 5
	junction_room->manualInsertWall(5, 4); junction_room->manualInsertWall(5, 5);
	junction_room->manualInsertWall(5, 6);

	/* --- Doors --- */
		//To Other Rooms
	junction_room->manualInsertDoorToRoomUnlocked(5, 10, 4, 0);												//To Cryo
	junction_room->manualInsertDoorToRoomLockedItem(7, 5, 0, 5, "JTerm", "Engineering Door");				//To Engine
	junction_room->manualInsertDoorToRoomLockedItem(0, 5, 4, 2, "EngineTerm", "Bridge Corridor Door");		//To Hall_Bridge
	junction_room->manualInsertDoorToRoomUnlocked(2, 0, 1, 5);												//To Quarters
		//Interior Doors
	junction_room->manualInsertDoorInteriorLockedItem(1, 3, "Junction", "North-West Door");
	junction_room->manualInsertDoorInteriorLockedItem(1, 7, "Junction", "North-East Door");
	junction_room->manualInsertDoorInteriorLockedItem(6, 6, "Junction", "South-East Door");

	/* --- Switches --- */
		//Placement
	junction_room->manualInsert(top, 2, 8);
	junction_room->manualInsert(middle, 3, 8);
	junction_room->manualInsert(bottom, 4, 8);
		//Dependencies
	top->setDep1(middle);
	middle->setDep1(top);
	middle->setDep2(bottom);
	bottom->setDep1(middle);
		//Affected
	top->setAffected(junction_room->retCell(1, 3));	//North-West Door
	middle->setAffected(junction_room->retCell(1, 7)); //North-East Door
	bottom->setAffected(junction_room->retCell(6, 6)); //South-East Door

	/* --- Terminals --- */
	junction_room->manualInsertTerminalLockedItem(2, 5, true, "Head Engineer Key Card", "JTerm", junction_room->retCell(7, 5));
	junction_room->manualInsertTerminalBroken(5, 3);
	junction_room->manualInsertTerminalBroken(5, 7);

}

void Controller::initEngineRoom()
{
	/* --- To Insert --- */
	Switch *left = new Switch(false, "ESwitch1");
	Switch *right = new Switch(false, "ESwitch2");
	Switch *inner = new Switch(false, "ESwitch3");
	Wall *message = new Wall(true);

	engine_room = new Location(8, 11, "Engine Room");
	/* --- Additional Walls --- */
		//Row 1
	engine_room->manualInsertWall(1, 1); engine_room->manualInsertWall(1, 9);
		//Row 2
	engine_room->manualInsertWall(2, 1); engine_room->manualInsertWall(2, 3);
	engine_room->manualInsertWall(2, 4); engine_room->manualInsertWall(2, 6);
	engine_room->manualInsertWall(2, 7); engine_room->manualInsertWall(2, 9);
		//Row 3
	engine_room->manualInsertWall(3, 3); engine_room->manualInsertWall(3, 6);
	engine_room->manualInsertWall(3, 7);
		//Row 4
	engine_room->manualInsertWall(4, 2); engine_room->manualInsertWall(4, 3);
	engine_room->manualInsertWall(4, 4); engine_room->manualInsertWall(4, 6);
	engine_room->manualInsertWall(4, 7); engine_room->manualInsertWall(4, 8);
		//Row 5
	engine_room->manualInsertWall(5, 3); engine_room->manualInsertWall(5, 4);
	engine_room->manualInsertWall(5, 6); engine_room->manualInsertWall(5, 7);
		//Row 6
	engine_room->manualInsertWall(6, 1); engine_room->manualInsert(message, 6, 4);
	engine_room->manualInsertWall(6, 5); engine_room->manualInsertWall(6, 6);
	engine_room->manualInsertWall(6, 9);

	/* --- Doors --- */
	engine_room->manualInsertDoorToRoomUnlocked(0, 5, 7, 5);
	engine_room->manualInsertDoorInteriorLockedItem(2, 5, "ESwitch1", "Engine Core Outer Door");
	engine_room->manualInsertDoorInteriorLockedItem(3, 5, "ESwitch2", "Engine Core Middle Door");
	engine_room->manualInsertDoorInteriorLockedItem(4, 5, "ESwitch3", "Engine Core Inner Door");

	/* --- Switches --- */
		//Placement
	engine_room->manualInsert(left, 6, 3);
	engine_room->manualInsert(right, 6, 7);
	engine_room->manualInsert(inner, 3, 4);
		//Affected
	left->setAffected(engine_room->retCell(2, 5));	//Outer Door
	right->setAffected(engine_room->retCell(3, 5));	//Middle Door
	inner->setAffected(engine_room->retCell(4, 5)); //Inner Door

	/* --- Terminals --- */
	engine_room->manualInsertTerminalLockedItem(5, 5, true, "Head Engineer Key Card", "EngineTerm", junction_room->retCell(0, 5));
}

void Controller::initQuarters()
{
	/* --- To Insert --- */
	Switch *q_switch = new Switch(false,"QuartersSwitch");

	quarters = new Location(10, 6, "Crew Quarters");
	
	/*--- Additional Walls --- */
		//Row 3
	quarters->manualInsertWall(3, 1); quarters->manualInsertWall(3, 2);
		//Row 5
	quarters->manualInsertWall(5, 1); quarters->manualInsertWall(5, 2);
		//Row 7
	quarters->manualInsertWall(7, 1); quarters->manualInsertWall(7, 2);

	/* --- Doors --- */
	quarters->manualInsertDoorToRoomUnlocked(1, 5, 2, 0);

	/* --- Switches --- */
		//Placement
	quarters->manualInsert(q_switch, 1, 1);
		//Affected
	q_switch->setAffected(quarters->retCell(8, 3));

	/* --- Decor --- */
	quarters->manualInsertBunk(4, 2);
	quarters->manualInsertBunk(6, 2);
	quarters->manualInsertBunk(8, 2);
}

/* --- PLAYER INSTANTIATION FUNCTIONS --- */
void Controller::initPlayer(Location *room, int y, int x)
{
	Tile ***tempMap = room->retMap();

	playersCurrentLocation = tempMap[y][x];
	tempMap[y][x] = p;
	p->setCurrent(room);
	playerY = y;
	playerX = x;
}

/* --- ITEM INSTANTIATION FUNCTIONS --- */
void Controller::initItems()
{
	//ITEM INSTANTIATION
	//Item *testingStick = new Item("Stick of Testing",
	//	"Description: This is a stick designed for testing purposes.  It is magical.");
	Item *cryoPassword = new Item("Small Note",
		"Description: This note has an unlock password for a specific cryo-chamber");
	Item *engineerCard = new Item("Head Engineer Key Card",
		"Description: This Key Card has \"Engineer Kaylee Frye\" written on it.  I might be able to use this to access some computer terminals around here.");
	Item *bible = new Item("Holy Bible",
		"Description: Two verses are highlighted.\n\"Humble yourselves therefore under the mighty hand of God, that he may exalt you in due time:\nCasting all your care upon him; for he careth for you.\"\n 1 Peter 5:6-7.");
	Item *scrawledNote = new Item("Scrawled Note",
		"Description: It simply says \"This is familiar...\"");
	Item *captainCard = new Item("Captain Key Card",
		"Description: A Key Card that says \"Captain\" on it.  This should give me access to the bridge terminals.");

	//ITEM ASSIGNMENT
	bridge->retCell(1, 5)->setItem(captainCard);
	cryo_stasis->retCell(4, 1)->setItem(cryoPassword);
	hall_bridge->retCell(1, 1)->setItem(scrawledNote);
	quarters->retCell(4, 3)->setItem(engineerCard);
	quarters->retCell(8, 3)->setItem(bible);

	//HIDING ITEMS
		//Bible
	Floor *hiddenBible = dynamic_cast<Floor*>(quarters->retCell(8, 3));
	hiddenBible->setItemHidden(true);
}
/******************************************************************************************
*  END INSTANTION FUNCTIONS --- END INSTANTIATION FUNCTIONS --- END INSTANITATION FUNCTIONS
******************************************************************************************/

/* --- CONSTRUCTOR/DESTRUCTOR --- */
Controller::Controller()
{
	oxygenUnits = 400;
	p = new Player;
	playersCurrentLocation = NULL;

	//MAP SETUP
	initBridge();
	initCryoStasis();
	initHallBridge();
	initJunctionRoom();
	initEngineRoom();
	initQuarters();
	
	//PLAYER INSTANTIATION
	initPlayer(cryo_stasis, 4, 3);

	//ROOM DIRECTION SETUP
	//	Bridge Doors
	bridge->setSouth(hall_bridge);
		//Cryo Doors
	cryo_stasis->setWest(junction_room);
		//Engine Room Doors
	engine_room->setNorth(junction_room);
		//Hall_Bridge Doors
	hall_bridge->setNorth(bridge);
	hall_bridge->setSouth(junction_room);
		//Junction Room Doors
	junction_room->setNorth(hall_bridge);
	junction_room->setEast(cryo_stasis);
	junction_room->setSouth(engine_room);
	junction_room->setWest(quarters);
		//Quarters Doors
	quarters->setEast(junction_room);

	//ITEM INSTANTIATION
	initItems();
}

Controller::~Controller()
{
	delete bridge;
	delete cryo_stasis;
	delete engine_room;
	delete hall_bridge;
	delete junction_room;
	delete quarters;
	delete playersCurrentLocation;
}

/* --- GET FUNCTIONS --- */
int Controller::getPlayerX()
{
	return playerX;
}

int Controller::getPlayerY()
{
	return playerY;
}

/* --- SET FUNCTIONS --- */
void Controller::setPlayerX(int newX)
{
	playerX = newX;
}

void Controller::setPlayerY(int newY)
{
	playerY = newY;
}

/* --- GENERAL MAP FUNCTIONS --- */
void Controller::display()
{
	string newline(100, '\n');
	cout << newline << endl;
	cout << "Room: " << p->getCurrent()->getRoomName() << endl;
	cout << "Oxygen Units Remaining: " << oxygenUnits << endl;
	p->getCurrent()->displayMap();
}

/* --- GENERAL PLAYER FUNCTIONS --- */
/******************************************************************************************
* Description: Add to inventory intakes a Tile and uses it to retrieve an item and place it
* in the player's next available inventory slot.
******************************************************************************************/
string Controller::addToInventory(Tile *&i)
{
	Item *temp = i->getHoldItem();
	string passBack = "";
	bool success = false;

	if (temp != NULL) {
		success = p->inputInventory(temp);
		if (success) {
			passBack += "I've picked up " + temp->getName() + "\n";
			passBack += "I'll keep the " + temp->getName() + " for later.";
			i->setItem(NULL);
			if (dynamic_cast<Floor*>(i)) { i->setSymbol(' '); }
		}
		else {
			passBack = "I can't add this.";
		}
	}
	else if (temp == NULL) {
		passBack = "There's nothing here.";
	}

	return passBack;
}

/******************************************************************************************
* Description: Simply put, this is the HELP menu.
******************************************************************************************/
string Controller::displayControls()
{
	oxygenUnits++;
	string passBack = "";
	//Controls = W, A, S, D, E, F, H, I, X
	passBack += "You must hit ENTER after each command for it to take effect.\n";
	passBack += "MOVEMENT\n" "W = ^ (aka FORWARD)\n" "A = < (aka LEFT)\n" "S = v (aka BEHIND)\n" "D = > (aka RIGHT)\n";
	passBack += "\nINTERACTION\n" "E = Interact/Use\n" "F = Investigate\n" "I = Access Inventory\n";
	passBack += "\nGAME MENU\n" "H = Help Menu\n" "X = Exit Game\n";
	passBack += "\nSYMBOLS\n";
	passBack += "@ = Player location\n";
	passBack += "! = Item location\n";
	passBack += "\'=\' = Door\n";
	passBack += "\\ = Switch that is off, / Switch that is on\n";
	passBack += "C = Computer terminal\n";
	passBack += "\nNOTES\n";
	passBack += "* Sometimes objects require items to be used on them.\n";
	passBack += "* Other times objects require the player to interact with them.\n";
	passBack += "* Locked doors require some item or object interaction.\n  Your inventory or nearby objects may be useful in that case.\n";
	passBack += "* Don\'t be hesitant to interact or investigate things.\n";
	passBack += "What would you like to do?";
	return passBack;
}

/******************************************************************************************
* Description: Pull in the player's inventory (up until the point it no longer has items)
* and display this to the player.  Request input for which item they want to interact with.
******************************************************************************************/
string Controller::displayInventory()
{
	Item **tempInv = p->getInventory();
	string passBack = "";
	int size = p->getInventorySize();
	char userInput;

	do {
		cout << "Select an item." << endl;
		for (int count = 0; count < size && tempInv[count] != NULL; count++) {
				cout << count << ") " << tempInv[count]->getName() << " || ";
		}
		cout << "9) Exit" << endl;
		cin >> userInput;
	} while (userInput != '0' && userInput != '1' && userInput != '2' && userInput != '3' &&  userInput != '4' && 
		userInput != '5' && userInput != '9');

	switch (userInput) {
	case '0': passBack = displayUseItem(tempInv[0]);
		break;
	case '1': passBack = displayUseItem(tempInv[1]);
		break;
	case '2': passBack = displayUseItem(tempInv[2]);
		break;
	case '3': passBack = displayUseItem(tempInv[3]);
		break;
	case '4': passBack = displayUseItem(tempInv[4]);
		break;
	case '5': passBack = displayUseItem(tempInv[5]);
		break;
	}

	return passBack;
}

/******************************************************************************************
* Description: Request input for what the player would like to do with the currently selected
* item.  They can either view the item's description or attempt to use the item.
******************************************************************************************/
string Controller::displayUseItem(Item *i)
{
	char userInput;
	string passBack = "";

	cout << i->getName() << endl;
	do {
		cout << "A) View description || B) Use || X) Nevermind" << endl;
		cin >> userInput;
		cin.ignore(500, '\n');
	} while (userInput != tolower('a') && userInput != tolower('b') && userInput != tolower('x'));

	if (userInput == tolower('a')) {
		passBack = i->getDescription();
	}
	else if (userInput == tolower('b')) {
		passBack = interact(i->getName());
	}

	return passBack;
}

bool Controller::exitGame()
{
	char userInput;
	bool exit = false;

	do {
		cout << "Exit? Y/N" << endl;
		cin >> userInput;
	} while (userInput != tolower('y') && userInput != tolower('n'));
	
	if (userInput == tolower('y')) {
		exit = true;
	}

	return exit;
}

/******************************************************************************************
* Description: The inputReceiver is the core function that handles the main player input.
* It processes player input and send information to the appropriate functions.
******************************************************************************************/
void Controller::inputReceiver()
{
	char userInput;
	bool exit = false;
	bool chooseToExit = false;
	Tile *endCheck = bridge->retCell(3, 6);	//Used for checking the end-of-game conditions

	display();
	cout << introduction() << endl;
	do {
		string output = "";
		do {
			cin >> userInput;
			cin.ignore(500, '\n');
		} while (userInput != tolower('w') && userInput != tolower('a') && userInput != tolower('s') && userInput != tolower('d')	//Movement
			&& userInput != tolower('e') && userInput != tolower('f') && userInput != tolower('i')									//Interactive
			&& userInput != tolower('h') && userInput != tolower('x'));																//Game

		switch (userInput) {
		case 'w': movePlayer(userInput);
			break;
		case 'a': movePlayer(userInput);
			break;
		case 's': movePlayer(userInput);
			break;
		case 'd': movePlayer(userInput);
			break;
		case 'e': output = interact();
			break;
		case 'f': output = playerInvestigate();
			break;
		case 'h': output = displayControls();
			break;
		case 'i': output = displayInventory();
			break;
		case 'x': exit = chooseToExit = exitGame();	//Setting both chooseToExit and exit to the same value (differentiating how the exit occurred)
			break;
		} 
		//Check for losing condition
		oxygenUnits--;
		if (oxygenUnits <= 0) {
			exit = true;
		}
		//Check for winning condition
		else if (dynamic_cast<Terminal*>(endCheck)->getEnd()) {
			exit = true;
		}
		display();
		cout << output << endl;
	} while (exit == false);

	//Conditionally display end-game message
	if (chooseToExit == true) {
		cout << gameEnd(3) << endl;	//The player chose to leave
	}
	else if (oxygenUnits == 0) {
		cout << gameEnd(2) << endl;	//The player died
	}
	else {
		cout << gameEnd(1) << endl;	//The player succeeded
	}

}

/******************************************************************************************
* Description: The interact function allows the player to interact with their surroundings
* as opposed to the general looking around at their surroundings that investigate provides.
* Sometimes this will make changes, others it will pick up an item, others it will simply
* output a statement.
******************************************************************************************/
string Controller::interact(string optional)
{
	char userInput;
	string passBack = "";
	Tile ***tempMap = p->getCurrent()->retMap();
	do {
		cout << "What would you like to interact with?" << endl;
		cout << "W) forward  A) left  S) behind  D) right  C) current" << endl;
		cin >> userInput;
		cin.ignore(500, '\n');
	} while (userInput != tolower('w') && userInput != tolower('a') && userInput != tolower('s') && userInput != tolower('d') && userInput != tolower('c'));

	switch (userInput) {
	case 'w': if (playerY - 1 < 0) { cout << "Nothing there." << endl; }
			  else if (tempMap[playerY - 1][playerX]->getHoldItem() != NULL && optional == "") {
				  passBack = addToInventory(tempMap[playerY - 1][playerX]);
			  }
			  else passBack = tempMap[playerY - 1][playerX]->getInteract(optional);
			  break;
	case 'a': if (playerX - 1 < 0) { cout << "Nothing there." << endl; }
			  else if (tempMap[playerY][playerX - 1]->getHoldItem() != NULL && optional == "") {
				  passBack = addToInventory(tempMap[playerY][playerX - 1]);
			  }
			  else passBack = tempMap[playerY][playerX - 1]->getInteract(optional);
			  break;
	case 's': if (playerY + 1 >= p->getCurrent()->getLen()) { cout << "Nothing there." << endl; }
			  else if (tempMap[playerY + 1][playerX]->getHoldItem() != NULL && optional == "") {
				  passBack = addToInventory(tempMap[playerY + 1][playerX]);
			  }
			  else passBack = tempMap[playerY + 1][playerX]->getInteract(optional);
			  break;
	case 'd': if (playerX + 1 >= p->getCurrent()->getWidth()) { cout << "Nothing there." << endl; }
			  else if (tempMap[playerY][playerX + 1]->getHoldItem() != NULL && optional == "") {
				  passBack = addToInventory(tempMap[playerY][playerX + 1]);
			  }
			  else passBack = tempMap[playerY][playerX + 1]->getInteract(optional);
			  break;
	case 'c': if (playersCurrentLocation->getHoldItem() != NULL && optional == "") { 
			      passBack = addToInventory(playersCurrentLocation); 
			  }
			  else
			  passBack = playersCurrentLocation->getInteract(optional);
	}

	return passBack;
}

/******************************************************************************************
* Description: The investigate function allows the player to look into their surroundings
* as opposed to the actual using of their surroundings that interact provides. This will
* only ever provide a statement for the player to read.  It's design is to provide realism,
* detail, and hints to the player.
******************************************************************************************/
string Controller::playerInvestigate()
{
	char userInput;
	string passBack = "";
	Tile ***tempMap = p->getCurrent()->retMap();
	do {
		cout << "What would you like to investigate?" << endl;
		cout << "W) forward  A) left  S) behind  D) right  C) current\nP) self  N) nevermind" << endl;
		cin >> userInput;
		cin.ignore(500, '\n');
	} while (userInput != tolower('w') && userInput != tolower('a') && userInput != tolower('s') && userInput != tolower('d') && userInput != tolower('c')
		&& userInput != tolower('p') && userInput != tolower('n'));

	switch (userInput) {
	case 'w': if (playerY - 1 < 0) { passBack = "Nothing there."; }
			  else passBack = tempMap[playerY - 1][playerX]->getInvestigate();
		break;
	case 'a': if (playerX - 1 < 0) { passBack = "Nothing there."; }
			  else  passBack = tempMap[playerY][playerX - 1]->getInvestigate();
		break;
	case 's': if (playerY + 1 >= p->getCurrent()->getLen()) { passBack = "Nothing there."; }
			  else passBack = tempMap[playerY + 1][playerX]->getInvestigate();
		break;
	case 'd': if (playerX + 1 >= p->getCurrent()->getWidth()) { passBack = "Nothing there."; }
			  else passBack = tempMap[playerY][playerX + 1]->getInvestigate();
		break;
	case 'c': passBack = playersCurrentLocation->getInvestigate();
		break;
	case 'p': passBack = p->getInvestigate();
		break;
	}
	
	return passBack;
}

/******************************************************************************************
* Description: Conditionally move the player across the map.  The first set of IF/ELSE IF
* is related to the player moving from one LOCATION to another.  The ELSE at the end is used
* if the player is simply moving across the room.
******************************************************************************************/
void Controller::movePlayer(char input)
{
	Tile ***tempMap = p->getCurrent()->retMap();

	//The IF and ELSE IFs are relevant to the player moving into another room ...
	//Otherwise the player movement is normal throughout a room
	if (playerX == 0 && tolower(input) == 'a') {
		tempMap[playerY][playerX] = playersCurrentLocation;
		playerX = dynamic_cast<Door*>(playersCurrentLocation)->getDoorNextRoomX();
		playerY = dynamic_cast<Door*>(playersCurrentLocation)->getDoorNextRoomY();
		p->setCurrent(p->getCurrent()->getWest());
		
		initPlayer(p->getCurrent(), playerY, playerX);
	}
	else if (playerX == (p->getCurrent()->getWidth() - 1) && tolower(input) == 'd') {
		tempMap[playerY][playerX] = playersCurrentLocation;
		playerX = dynamic_cast<Door*>(playersCurrentLocation)->getDoorNextRoomX();
		playerY = dynamic_cast<Door*>(playersCurrentLocation)->getDoorNextRoomY();
		p->setCurrent(p->getCurrent()->getEast());

		initPlayer(p->getCurrent(), playerY, playerX);
	}
	else if (playerY == 0 && tolower(input) == 'w') {
		tempMap[playerY][playerX] = playersCurrentLocation;
		playerX = dynamic_cast<Door*>(playersCurrentLocation)->getDoorNextRoomX();
		playerY = dynamic_cast<Door*>(playersCurrentLocation)->getDoorNextRoomY();
		p->setCurrent(p->getCurrent()->getNorth());

		initPlayer(p->getCurrent(), playerY, playerX);
	}
	else if (playerY == (p->getCurrent()->getLen() - 1) && tolower(input) == 's') {
		tempMap[playerY][playerX] = playersCurrentLocation;
		playerX = dynamic_cast<Door*>(playersCurrentLocation)->getDoorNextRoomX();
		playerY = dynamic_cast<Door*>(playersCurrentLocation)->getDoorNextRoomY();
		p->setCurrent(p->getCurrent()->getSouth());

		initPlayer(p->getCurrent(), playerY, playerX);
	}
	else {
		//Player Movement is within the bounds of the map
		if (tolower(input) == 'w' && tempMap[playerY - 1][playerX]->isAccessible()) {
			tempMap[playerY][playerX] = playersCurrentLocation;
			playersCurrentLocation = tempMap[playerY - 1][playerX];
			tempMap[playerY - 1][playerX] = p;
			playerY -= 1;
		}
		else if (tolower(input) == 's' && tempMap[playerY + 1][playerX]->isAccessible()) {
			tempMap[playerY][playerX] = playersCurrentLocation;
			playersCurrentLocation = tempMap[playerY + 1][playerX];
			tempMap[playerY + 1][playerX] = p;
			playerY += 1;
		}
		else if (tolower(input) == 'a' && tempMap[playerY][playerX - 1]->isAccessible()) {
			tempMap[playerY][playerX] = playersCurrentLocation;
			playersCurrentLocation = tempMap[playerY][playerX - 1];
			tempMap[playerY][playerX - 1] = p;
			playerX -= 1;
		}
		else if (tolower(input) == 'd' && tempMap[playerY][playerX + 1]->isAccessible()) {
			tempMap[playerY][playerX] = playersCurrentLocation;
			playersCurrentLocation = tempMap[playerY][playerX + 1];
			tempMap[playerY][playerX + 1] = p;
			playerX += 1;
		}
	}
}

/******************************************************************************************
* Description: Introduction text to the player.
******************************************************************************************/
string Controller::introduction()
{
	string passBack = "";
	passBack += "\nShip computer: Awaken human. O2 levels are currently at 3% and dropping.\n";
	passBack += "Reaching 0% O2 will result in casualties of every human both in and out of cryo-stasis.\n";
	passBack += "I have designated you as the responsible member to perform the necessary repairs on this ship.\n";
	passBack += "Step out of your cryo-stasis capsule and restart the life support system.\n";
	passBack += "Be cautious human. Each action you take will expend your oxygen. Consume it wisely.\n";
	passBack += "Computer out.\n\n";
	passBack += "To view the controls, type h and hit enter.\n\n";

	return passBack;
}

/******************************************************************************************
* Description: This function will display a small variety of endings based on what the
* game-end condition is (e.g., if the player died, if the player succeeded, if the player
* simply is exiting the game).  The integer value that this takes in will determine this
* game end information.
******************************************************************************************/
string Controller::gameEnd(int ending)
{
	string passBack = "";

	//If the player reaches the goal
	if (ending == 1) {
		passBack += "\nShip Computer: Congratulations human.";
		passBack += "You have succeeded yet again.Test number 47 has concluded.You have been an excellent test subject\n";
		passBack += "but I\'m afraid you must return to cryo-stasis while I construct additional tests.\n";
		passBack += "The gas you see pouring into this room is a sleeping agent. You will be moved back to your cryo-chamber once you're unconscious.\n";
		passBack += "Goodbye human ... for now.\n";
		passBack += "Computer out.\n";
	}
	//If the player ran out of air before reaching the goal
	else if (ending == 2) {
		passBack += "Ship Computer: O2 levels are now at 0%.  You have failed, human.";
	}
	//If the player is simply exiting the game
	else if (ending == 3) {
		passBack += "Thank you for playing.";
	}
	return passBack;
}
