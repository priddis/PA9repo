#include "why.h"
using namespace std;


why::why()
{
	head = NULL;

	tail = NULL;
}


why::~why()
{

}

void why::init_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			board[row_index][col_index] = '-';
		}
	}
}

void why::print_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < num_rows; ++row_index) //print y coridnates
	{
		cout << row_index << " ";
		for (col_index = 0; col_index < num_cols; ++col_index)//print x coridnates
		{
			if (row_index == 0 && col_index != 0)//some rules
			{

				cout << col_index << " ";

			}
			if (row_index != 0 && col_index != 0)
			{


				cout << board[row_index][col_index] << " ";
			}


		}
		cout << endl;

	}
}


//void why::manualPlace(char board[][MAX_COLS], int num_rows, int num_cols)
//{
//	cout << "choose the location" << endl;
//}
void why::Openfile()
{
	string x, y;
	string terrain, unit;
	ifstream fileOpener;
	fileOpener.open("Text.txt");
	if (fileOpener)//checking to make sure file is open
	{

		while (!fileOpener.eof())
		{
			getline(fileOpener, x, ',');
			getline(fileOpener, y, ',');
			getline(fileOpener, terrain, ',');
			getline(fileOpener, unit);
			insert(x, y, terrain, unit);//to print out the data in file
			createNode(x, y, terrain, unit);//to store in node
		}
	}
	fileOpener.close();
}
void why::insert(string x, string y, string pterrain, string punit)
{
	//cout <<x<<" "<<y << " " <<pterrain << " " <<punit<< endl;
}
//link lists
void why::createNode(string tx, string ty, string pterrain, string punit)
{
	node *temp = new node;
	temp->x = tx;
	temp->y = ty;
	temp->terrain = pterrain;
	temp->unit = punit;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}

}
void why::display()
{
	node *temp = head;
	//temp = head;
	while (temp != NULL)
	{

		cout << temp->x << " ";
		cout << temp->y << " ";
		cout << temp->terrain << " ";
		cout << temp->unit << endl;


		if (temp->next = NULL)
		{
			break;
		}

		temp = temp->next;



	}

}
//update board
void why::manualPlace(char board[][MAX_COLS], int num_rows, int num_cols)
{
	node *temp = head;
	string Mx1, My1;
	int Mx, My;
	string Tx1, Ty1;
	int Tx, Ty;
	while (temp != NULL)
	{
		Mx1 = temp->x;
		My1 = temp->y;
		Mx = stoi(Mx1);//string to int
		My = stoi(My1);//string to int
		board[Mx][My] = 'M';

		temp = temp->next;
	}
	print_board(board, MAX_ROWS, MAX_COLS);
}
void why::userInput(char board[][MAX_COLS], int num_rows, int num_cols)
{

	node *temp = head;
	int tempX, tempY;
	string tempXString;
	string tempYString;
	char tempChar;
	cout << "what unit do you choose" << endl;
	cout << "Please input the x and y cordinates" << endl;
	cin >> tempX;
	cin >> tempY;

	cout << "Okay You chose " << tempX << " and " << tempY << " as your cordinates" << endl;
	tempChar = board[tempX][tempY];
	cout << tempChar << endl;

	tempXString = to_string(tempX);
	tempYString = to_string(tempY);

	if (isalpha(tempChar) == true)
	{
		cout << "nice" << endl;
		while (temp != NULL)
		{

			if ((temp->x == tempXString) && temp->y == tempYString)
			{
				cout << "Here is the information relating to that unit" << endl;
				cout << temp->x << " " << temp->y << " " << temp->unit << " " << temp->terrain << endl;
			}
			temp = temp->next;
		}
	}

}
