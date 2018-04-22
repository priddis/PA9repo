#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
using::std::string;
class why
{
public:
	struct node
	{
		string x;
		string y;
		string unit;
		string terrain;
		node *next;
		node *prev;
	};



	why();
	~why();
#define MAX_ROWS 11
#define MAX_COLS 11
	void init_board(char board[][MAX_COLS], int num_rows, int num_cols);
	void print_board(char board[][MAX_COLS], int num_rows,
		int num_cols);
	void manualPlace(char board[][MAX_COLS], int num_rows, int num_cols);
	void Openfile();
	void insert(string x, string y, string pterrain, string punit);

	//link lists
	void createNode(string tx, string ty, string pterrain, string punit);
	void display();
	void userInput(char board[][MAX_COLS], int num_rows, int num_cols);
private:
	node *head, *tail;



};

