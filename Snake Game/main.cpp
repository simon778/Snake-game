// Snake Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include "Point.h";
#include "Snake.h"
#include <time.h>
#include <windows.h>

using namespace std;

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}


int main()
{
	srand((unsigned)time(NULL));
	ShowConsoleCursor(false);

	Snake snake;
	char op = 'l';

	


	do {
		if(_kbhit())
			op = _getch();

	system("cls");
	cout << "\t\n";
	cout << "--------------------SNAKE GAME--------------------\n";
	cout << " Press 's' to START the game\n";
	cout << " Press 'w' 's' 'a' 's' to change the direction of the snake\n";
	cout << "--------------------------------------------------\n";
	Sleep(1000);
	}
	while (op != 's');

	op = ' ';

	do {
		if (_kbhit())
			op = _getch();
	
	switch (op) {
	case 'w':
	case 'W':
		snake.TurnUp();
		break;
	case 's':
	case 'S':
		snake.TurnDown();
		break;
	case 'a':
	case 'A':
		snake.TurnLeft();
		break;
	case 'd':
	case 'D':
		snake.TurnRight();
		break;
		}
	snake.Move();
	} while (op != 'e');


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
