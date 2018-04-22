#include "header/Engine.h"
#include "why.h"


int main()
{
	string x, y, terrain, unit;

	char p1_board[MAX_ROWS][MAX_COLS] = { '\0' };
	int num_rows = 0, num_cols = 0;
	why test;
	test.init_board(p1_board, MAX_ROWS, MAX_COLS);
	test.print_board(p1_board, MAX_ROWS, MAX_COLS);
	test.Openfile();
	test.insert(x, y, terrain, unit);
	test.createNode(x, y, terrain, unit);
	test.display();
	test.manualPlace(p1_board, MAX_ROWS, MAX_COLS);
	test.userInput(p1_board, MAX_ROWS, MAX_COLS);
	return 0;
}