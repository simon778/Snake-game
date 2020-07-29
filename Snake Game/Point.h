#pragma once
#include <iostream>
#include <conio.h>
#include "windows.h"
#include <dos.h>;

using namespace std;


class Point
{
private:
	int x;
	int y;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD CursorPosition;

	void gotoxy(int x, int y) {
		CursorPosition.X = x;
		CursorPosition.Y = y;
		SetConsoleCursorPosition(console, CursorPosition);
	}
public:

	Point() {
		x = y = 10;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void SetPoint(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}
	void MoveUp(){
		y--;
	}
	void MoveDown() {
		y++;
	}
	void MoveLeft() {
		x--;
	}
	void MoveRight() {
		x++;
	}
	void Draw() {
		gotoxy(x,y);
		cout << "*";
	}
	void Erase() {
		gotoxy(x, y);
		cout << " ";
	}
	void CopyPos(Point * p) {
		p->x = x;
		p->y = y;
	}
	void Debug() {
		cout << "("<<x<<", "<<y<<") ";
	}
};

