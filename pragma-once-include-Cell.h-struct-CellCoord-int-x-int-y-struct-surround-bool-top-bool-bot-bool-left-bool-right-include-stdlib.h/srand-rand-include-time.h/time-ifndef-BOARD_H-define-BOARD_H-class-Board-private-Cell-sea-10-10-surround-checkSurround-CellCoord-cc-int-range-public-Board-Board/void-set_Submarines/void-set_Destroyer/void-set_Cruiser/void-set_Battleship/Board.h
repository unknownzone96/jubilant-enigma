#pragma once
#include "Cell.h"

struct CellCoord
{
	int x;
	int y;
};

struct surround
{
	bool  top;
	bool bot;
	bool left;
	bool right;
};

#include <stdlib.h>     // srand, rand 
#include <time.h>       // time 
#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
	Cell sea[10][10];
	surround checkSurround(CellCoord cc, int range);
	
public:
	Board();
	~Board();
	int num_of_occupied();
	void randShip(int n);
	void set_Board();



};


#endif // !BOARD_H
