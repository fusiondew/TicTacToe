#include <iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

Board::Board(){
	background = 219;// Sets Background Character.
	
	for(int r = 0; r < 3; r++){
		for(int c = 0; c < 3; c++){
			boardArr[r][c] = background;
		}
	}
	
}

void Board::Play(Player P, int col, int row){
	
	if(boardArr[row][col] == background){
		boardArr[row][col] = P.getPlayerChar();
	}
	
}
void Board::Draw(){
	
	for(int r = 0; r < 3; r++){
		for(int c = 0; c < 3; c++){
			if(c == 2){
				cout << boardArr[r][c] << endl;
			} else{
				cout << boardArr[r][c];
			}
		}
	}
	
}