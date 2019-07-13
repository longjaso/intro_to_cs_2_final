/*************************************************************************
* Author: Jason Long
* Date: 11/24/2016
* Assignment: Final Project
*************************************************************************/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Location.hpp"
#include "Player.hpp"

class Controller
{
private:
	//Game Control Data Members
	int oxygenUnits;

	//Location and Map Pointers
	Location *bridge;
	Location *cryo_stasis;
	Location *engine_room;
	Location *hall_bridge;
	Location *junction_room;
	Location *quarters;

	//Player Information
	Player *p;						//Used for holding info about the player
	Tile *playersCurrentLocation;	//Used for holding info about the tile the player is on
	int playerX;					//The player's X Coord
	int playerY;					//The player's Y Coord

	//Map Instantiation Functions
	void initBridge();
	void initCryoStasis();
	void initEngineRoom();
	void initHallBridge();
	void initJunctionRoom();
	void initQuarters();

	//Player Instantiation Functions
	void initPlayer(Location*, int, int);

	//Item Initialization Functions
	void initItems();

public:
	//Constructor/Destructor
	Controller();
	~Controller();

	//Getter Functions
	int getPlayerX();
	int getPlayerY();
	
	//Setter Functions
	void setPlayerX(int);
	void setPlayerY(int);

	//General Map Functions
	void display();

	//General Player Functions
	string addToInventory(Tile*&);
	string displayControls();
	string displayInventory();
	string displayUseItem(Item*);
	bool exitGame();
	void inputReceiver();
	string interact(string optional = "");
	string playerInvestigate();
	void movePlayer(char);

	//Game Functions
	string introduction();
	string gameEnd(int);
};

#endif