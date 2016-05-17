# jubilant-enigma

#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}

int Board::num_of_occupied()
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (sea[i][j].get_occupied())
			{
				count++;
			}
		}
	}
	return count;
}

CellCoord randCoord() {
	CellCoord randResult;
	srand(time(NULL));
	// generates number between 0 and 10:
	randResult.x = rand() % 10;
	randResult.y = rand() % 10;
	return randResult;
}

surround Board::checkSurround(CellCoord cc, int range) {
	surround result;
	result.bot = true;
	result.top = true;
	result.left = true;
	result.right = true;

	for (int i = 0; i < range; i++)
	{
		if (sea[cc.x + range - i][cc.y].get_occupied() || cc.x + range > 9)
		{
			result.right = false;
		}
		if (sea[cc.x - range - i][cc.y].get_occupied() || cc.x - range > 9)
		{
			result.left = false;
		}
		if (sea[cc.x][cc.y + range - i].get_occupied() || cc.y + range > 9)
		{
			result.bot = false;
		}
		if (sea[cc.x][cc.y - range - i].get_occupied() || cc.y - range > 9)
		{
			result.top = false;
		}
	}
	return result;
}

void Board::randShip(int n) {
	CellCoord CellCheck;
	int r;
	do
	{
		do
		{
			CellCheck = randCoord();
		} while (sea[CellCheck.x][CellCheck.y].get_occupied());

	} while (!checkSurround(CellCheck, n).bot &&
		!checkSurround(CellCheck, n).top && !checkSurround(CellCheck, n).left &&
		!checkSurround(CellCheck, n).right);

	sea[CellCheck.x][CellCheck.y].set_occupied();

	if (checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).top &&
		checkSurround(CellCheck, n).left && checkSurround(CellCheck, n).right)
	{
		//rand of all 4
		r = rand() % 4;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			case 2: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 3: sea[CellCheck.x - i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).top &&
		checkSurround(CellCheck, n).left)
	{
		r = rand() % 3;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 2: sea[CellCheck.x - i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).top && checkSurround(CellCheck, n).right)
	{
		r = rand() % 3;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 2: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			}
		}

	}
	else if (checkSurround(CellCheck, n).left && checkSurround(CellCheck, n).top && checkSurround(CellCheck, n).right)
	{
		r = rand() % 3;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 2: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			}
		}

	}
	else if (checkSurround(CellCheck, n).left && checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).right)
	{
		r = rand() % 3;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 1: sea[CellCheck.x - i][CellCheck.y].set_occupied();
				break;
			case 2: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			}
		}

	}
	else if (checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).top)
	{
		r = rand() % 2;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).top && checkSurround(CellCheck, n).left)
	{
		r = rand() % 2;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x - i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).top && checkSurround(CellCheck, n).right)
	{
		r = rand() % 2;
		for (int i = 1; i < n; i++)
		{	
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).left)
	{
		r = rand() % 2;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 1: sea[CellCheck.x - i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).right)
	{
		r = rand() % 2;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 1: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).left && checkSurround(CellCheck, n).right)
	{
		r = rand() % 2;
		for (int i = 1; i < n; i++)
		{	
			switch (r)
			{
			case 0: sea[CellCheck.x - i][CellCheck.y].set_occupied();
				break;
			case 1: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).bot)
	{
		for (int i = 1; i < n; i++)
		{
			sea[CellCheck.x][CellCheck.y + i].set_occupied();
		}
	}
	else if (checkSurround(CellCheck, n).top)
	{
		for (int i = 1; i <= n; i++)
		{
			sea[CellCheck.x][CellCheck.y - i].set_occupied();
		}

	}
	else if (checkSurround(CellCheck, n).left)
	{
		for (int i = 1; i < n; i++)
		{
			sea[CellCheck.x - i][CellCheck.y].set_occupied();
		}

	}
	else if (checkSurround(CellCheck, n).right)
	{
		for (int i = 1; i < n; i++)
		{
			sea[CellCheck.x + i][CellCheck.y].set_occupied();
		}
	}

}

void Board::set_Board()
{
	randShip(1);
	randShip(1);
	randShip(2);
	randShip(2);
	randShip(3);
	randShip(4);
	randShip(5);
}


