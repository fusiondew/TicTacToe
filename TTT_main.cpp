#include <iostream>
#include "Player.h"
#include "Board.h"
using namespace std;

int main(){
	bool boardIsFull = false;
	bool someoneWon = false;
	int x, y;
	Board boardObj;
	Player XPlayer('X');
	Player OPlayer('O');
	
	while(boardIsFull == false || someoneWon == false){
		boardObj.Draw();
		cout << "Player X Input coordinates: " << endl;
		cin >> x >> y;
		boardObj.Play(XPlayer, x-1, y-1);
		cout << endl;
		boardObj.Draw();
		cout  << "Player O Input coordinates: " << endl;
		cin >> x >> y;
		boardObj.Play(OPlayer, x-1, y-1);
		cout << endl;
	}
	
}
//To Do:
//Comment this shit.