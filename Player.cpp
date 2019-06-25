#include <iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

Player::Player(char pc){
	playerChar = pc;
}

Player::Player(){
	
}

char Player::getPlayerChar(){
	return playerChar;
}