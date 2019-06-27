#include <iostream>
#include <string>
#include "Player.h"
#include "Board.h"
using namespace std;

Player XPlayer('X');								//Makes player object for 'X' pieces.
Player OPlayer('O');									//Makes player object for 'O' pieces.

void Game(Player XPlayer, Player OPlayer){
	
	int x, y;																//To store coordinates.
	bool retry = false;															//To store returned value of Board::Draw(). True if the user needs to retry/false if not.
	bool theresAWinner = false;												//To check for cat's game.
	Board boardObj;																//Initializes the board.
	int smileValue = 1;													//-|Gets rid of pesky conversion
	char smile = smileValue;											//-|warnings for the ASCII smile :D
	
	cout << "Enter one coordinate at a time, and have fun!" << smile << "\n\n";
	boardObj.Draw();														//Draws the empty board before game start.
	
	while(boardObj.BoardIsFull() == false){										//Beginning of game loop. Checks if board is full after player O's move.
	
		cout << "Player X Input coordinates((1,1)-(3,3)): " << endl;
		cin >> x >> y; 														//Gets input of x and y values for player X
		retry = boardObj.Move(XPlayer, x-1, y-1);								//Sends the move of player X to Board::Move() and gives returned value to retry.
		
		while(retry == true){												//-|
			cout << "There's already a piece there, try again." << endl;	// |
			cout << "Player X Input coordinates((1,1)-(3,3)): " << endl;	// | If the coordinates inputted already contain a character
			cin >> x >> y;													// | this makes the player retry until they enter coordinates
			retry = boardObj.Move(XPlayer, x-1, y-1);						// | of a free spot.
		}																	//-|

		cout << endl;
		boardObj.Draw();													//Updates the board display
		if(boardObj.CheckForWinner(XPlayer) == true){							//Checks if X won
			cout << "Winner is X!!!" << endl;
			theresAWinner = true;											//Lets program know it wasn't a cat's game
			break;																//Breaks loop if X won
		}
		
		//------------------------------------------------------------------
		else if (boardObj.BoardIsFull() == true){							//Checks if board is full after player X's move
			break;																//Breaks loop if board is full after X's turn
		}
		//------------------------------------------------------------------
		
		cout  << "Player O Input coordinates((1,1)-(3,3)): " << endl;
		cin >> x >> y;														//Gets input of x and y values for player O
		retry = boardObj.Move(OPlayer, x-1, y-1);								//Sends the move of player O to Board::Move() and gives returned value to retry.
		
		while(retry == true){												//-|
			cout << "There's already a piece there, try again." << endl;	// |
			cout << "Player O Input coordinates((1,1)-(3,3)): " << endl;	// | If the coordinates inputted already contain a character
			cin >> x >> y;													// | this makes the player retry until they enter coordinates
			retry = boardObj.Move(OPlayer, x-1, y-1);						// | of a free spot.
		}																	//-|
		
		cout << endl;
		boardObj.Draw();													//Updates the board display
		if(boardObj.CheckForWinner(OPlayer) == true){							//Checks if O won
			cout << "Winner is O!!!" << endl;
			theresAWinner = true;											//Lets program know it wasn't a cat's game
			break;																//Breaks loop if O won
		}
	}//Game Loop
	
	if(theresAWinner == false){												//If the game ends with no winner
		cout << "Cat's Game! Nobody won!" << endl;								//Prints this.
	}
	//return 0;
}

int main(){
	/*
	Player XPlayer('X');
	Player OPlayer('O');
	*/
	bool finished = false;							//To check wheather the player is finished playing or wants to play again.
	char playAgain;										//Stores the players answer for that ^
	do{												//Runs game loop at least once
		Game(XPlayer, OPlayer);
		cout << "Play again?[Y/N]" << endl;			//-| Asks if user wants to play again.
		cin >> playAgain;							// |
		if(playAgain == 'N' || playAgain == 'n'){	// | If user enters 'N' or 'n' the program quits.
			finished = true;						// |
		}											//-|
	}while(finished == false);							//If the user wants to play again, runs game loop again.
}


//To Do:
//Comment this mess. -done... I think.
//Make able to win. -done
//When a player makes a move, check if there is already a character in that position and if there is, re-do the move. -done
//Find every place to use pointers and references.