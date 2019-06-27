#ifndef BOARD_H
#define BOARD_H
#include "Player.h"

class Board{
	
	public:
		Board();
		void Draw();						//Draws the board in beginning and after every move.
		bool Move(Player, int, int);	//Takes a player object and puts their character at the given coordinates.
		bool CheckForWinner(Player);		//Checks if the given players character makes any winning patterns.
		bool BoardIsFull();				//To check if the board is full.
	private:
		char boardArr[3][3];				//3 containers of 3 elements each(helps me remember, I'm bad with arrays).
		char background;				//Stores the background character to fill array and be replaced by player pieces.
		
};

#endif //BOARD_H