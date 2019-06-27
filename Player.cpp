#include <iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

Player::Player(char pc){
	playerChar = pc;				//Character to put on the board, given when making the player objects.
}

Player::Player(){					//Empty constructor to maybe make AI to play against in the furure.
	
}

char Player::getPlayerChar(){
	return playerChar;				//Returns character for current player object(X or O).
}