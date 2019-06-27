#include <iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

Board::Board(){
	
	int squareCharValue = 219;							//Gets rid of conversion warning when giving a 'char' the ASCII integer value of a square.
	background = squareCharValue;							//Sets background character to use.
	
	for(int r = 0; r < 3; r++){
		for(int c = 0; c < 3; c++){
			boardArr[r][c] = background;				//Sets all array elements to the background character.
		}
	}
	
}

bool Board::Move(Player P, int col, int row){		//Takes player object to get the current playerChar
	
	if(boardArr[row][col] == background){				//If the given coordinates contain a background character
		boardArr[row][col] = P.getPlayerChar();		//Put the playerChar at the given coordinates.
		return false;									//Return false because the player does not need to retry
	} else {return true;}							//If the given coordinates do not contain the background character, the player needs to retry.
	
}
void Board::Draw(){
	
	int i = 0;							//To put coordinate numbering next to the board
	int TL_AsciiCharValue = 218;	//--|
	int TR_AsciiCharValue = 191;	//  |
	int BR_AsciiCharValue = 217;	//  |	To make the board look pretty.
	int BL_AsciiCharValue = 192;	//  |
	int S_AsciiCharValue = 179;		//  |
	int B_AsciiCharValue = 196;		//  |
	char TL = TL_AsciiCharValue;	//  |TL = TopLeft
	char TR = TR_AsciiCharValue;	//  |TR = TopRight
	char BR = BR_AsciiCharValue;	//  |BR = BottomRight
	char BL = BL_AsciiCharValue;	//  |BL = BottomLeft
	char S = S_AsciiCharValue;		//  |S = Side
	char B = B_AsciiCharValue;		//--|B = Bottom
	
	cout << TL << "123" << TR << endl;						//Prints the top of the board with corners and coordinate numbers.
	for(int r = 0; r < 3; r++){
		for(int c = 0; c < 3; c++){
			if(c == 0){									//Prints the last character in the row, then the "Side" character and goes to the next line.
				i++;										//Coordinate to print on left side of board.
				cout << i << boardArr[r][c];			//Prints the coordinate number then the first column of the row.
			} else if(c == 2){								//If the loop is at the first column of a row,
				cout << boardArr[r][c] << S << endl;	//If the loop reaches the last column of a row,
			}else{
				cout << boardArr[r][c];						//Prints all other characters that dont fit the above criteria.
			}
		}
	}
	cout << BL << B << B << B << BR << endl;			//Prints the bottom characters.
	
}

bool Board::CheckForWinner(Player P){
		
	if(boardArr[0][0] == P.getPlayerChar() && boardArr[1][1] == P.getPlayerChar() && boardArr[2][2] == P.getPlayerChar()){
		return true;
		/*
		Checks board for this pattern made with given playerChar:
		XOO
		OXO
		OOX
		*/
	} else if (boardArr[2][0] == P.getPlayerChar() && boardArr[1][1] == P.getPlayerChar() && boardArr[0][2] == P.getPlayerChar()){
		return true;
		/*
		Checks board for this pattern made with given playerChar:
		OOX
		OXO
		XOO
		*/
	} else if (boardArr[0][0] == P.getPlayerChar() && boardArr[1][0] == P.getPlayerChar() && boardArr[2][0] == P.getPlayerChar()){
		return true;
		/*
		Checks board for this pattern made with given playerChar:
		XOO
		XOO
		XOO
		*/
	} else if (boardArr[0][1] == P.getPlayerChar() && boardArr[1][1] == P.getPlayerChar() && boardArr[2][1] == P.getPlayerChar()){
		return true;
		/*
		Checks board for this pattern made with given playerChar:
		OXO
		OXO
		OXO
		*/
	}  else if (boardArr[0][2] == P.getPlayerChar() && boardArr[1][2] == P.getPlayerChar() && boardArr[2][2] == P.getPlayerChar()){
		return true;
		/*
		Checks board for this pattern made with given playerChar:
		OOX
		OOX
		OOX
		*/
	} else if (boardArr[0][0] == P.getPlayerChar() && boardArr[0][1] == P.getPlayerChar() && boardArr[0][2] == P.getPlayerChar()){
		return true;
		/*
		Checks board for this pattern made with given playerChar:
		XXX
		OOO
		OOO
		*/
	} else if (boardArr[1][0] == P.getPlayerChar() && boardArr[1][1] == P.getPlayerChar() && boardArr[1][2] == P.getPlayerChar()){
		return true;
		/*
		Checks board for this pattern made with given playerChar:
		OOO
		XXX
		OOO
		*/
	}  else if (boardArr[2][0] == P.getPlayerChar() && boardArr[2][1] == P.getPlayerChar() && boardArr[2][2] == P.getPlayerChar()){
		return true;
		/*
		Checks board for this pattern made with given playerChar:
		OOO
		OOO
		XXX
		*/
	}
	else{return false;}						//If no pattern has been made, nobody has won. So return false.
	
}

bool Board::BoardIsFull(){
	
	int spaceCheck = 0;							//To check how many spaces on the board have been used.
	for(int r = 0; r < 3; r++){
		for(int c = 0; c < 3; c++){
			if(boardArr[r][c] != background){
				spaceCheck++;
			}
		}
	}
	if(spaceCheck == 9){					//if 9 spaces on the board have been used, the board is full
		return true;							//So return true.
	} else {return false;}					//If not, return false.
}


