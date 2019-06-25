#ifndef BOARD_H
#define BOARD_H
#include "Player.h"

class Board{
	
	public:
		Board();
		void Draw();
		void Play(Player, int, int);
	private:
		char boardArr[3][3];//3 containers of 3 elements each
		char background;
};

#endif //BOARD_H