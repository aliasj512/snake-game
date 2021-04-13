#include "Snake.h"

int dir = -1;
int score = 0;
int snakeHeadPositionX = 10;
int snakeHeadPositionY = 10;

int fruitPositionX = 7;
int fruitPositionY = 15;
int x, y;
int tailX[100], tailY[100];
int ntail;


bool gameOver = false;


void Logic() {
	
	/*
			  w(0)
		a(1)  s(2)  d(3)
	*/
	switch (dir) {
	case 0:
		snakeHeadPositionY--;
		break;
	case 1:
		snakeHeadPositionX--;
		break;
	case 2:
		snakeHeadPositionY++;
		break;
	case 3:
		snakeHeadPositionX++;
		break;
	}
	if (snakeHeadPositionX <= 0 || snakeHeadPositionX >= width - 1 || snakeHeadPositionY < 0 || snakeHeadPositionY >= height)
		gameOver = true;
	else if (snakeHeadPositionX == fruitPositionX && snakeHeadPositionY == fruitPositionY) {
		score++;
		fruitPositionX = rand() % width;
		fruitPositionY = rand() % height;
	}
	//dir = -1;
}
void Input() {
	/*
			w
		a   s   d
	*/

	if (_kbhit()) {
		switch (_getch()) {
		case 'w': // only integer value representation is allowed for the case
			dir = (dir == 2) ? dir : 0;
			break;
		case 'a':
			dir = (dir == 3) ? dir : 1;
			break;
		case 's':
			dir = (dir == 0) ? dir : 2;
			break;
		case 'd':
			dir = (dir == 1) ? dir : 3;
			break;
		case 'x':
			gameOver = true;
			break;
		}
		//end of switch
	}
}
void DisplaySnakeBoard() {
	system("cls");// this is for what
	//system("Color 0B");
	//natural counting loop
	for (int i = 0; i < width; i++) //Initialization, loop condition and update all "built into" the for - loop structure!
		cout << "*";	// Loop Body
	cout << endl;

	for (int i = 0; i < height; i++) // row
	{
		//ANY valid C++ statements can be inside body of loop
		//nested for loop 
		for (int j = 0; j < width; j++) //col
		{
			if (j == 0 || j == width - 1)
				cout << '*';
			else if (snakeHeadPositionX == j && snakeHeadPositionY == i) {
				cout << 'S';
			}
			else if (fruitPositionX == j && fruitPositionY == i)
				cout << 'o';
			else
				cout << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++) //Initialization, loop condition and update all "built into" the for - loop structure!
		cout << "*";	// Loop Body
	cout << endl;
	cout << "Score: " << score << endl;

}


extern bool gameOver;

int main() {
	//----------Snake Game------------------

	/*

	  ##############   <- width (num of columns)
	  #            #
	...            ...
			 O
	  #   $        #
	  ##############
	  ^
	  |
	  height (num of rows)

	*/
	system("Color 0B");
	while (!gameOver) {
		DisplaySnakeBoard();
		Input();
		Logic();
	}

	return 0;
}