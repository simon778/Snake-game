#pragma once
#include "Point.h"
#include <Dos.h>

#define MAXSNAKESIZE 100

class Snake
{
private:
	Point * cell[MAXSNAKESIZE];
	int size;
	char dir;
	Point fruit;
	int frame_height;
	int frame_width;

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD CursorPosition;

	void gotoxy(int x, int y) {
		CursorPosition.X = x;
		CursorPosition.Y = y;
		SetConsoleCursorPosition(console, CursorPosition);
	}

public:
		Snake() {
			frame_height = 25;
			frame_width = 50;
			size = 1;
			cell[0] = new Point(20, 20);
			for (int i = 1;i < MAXSNAKESIZE; i++) {
				cell[i] = NULL;
			}
			fruit.SetPoint(rand()%50, rand()%25);
		}
		void AddCell(int x, int y) {
			cell[size++] = new Point(x, y);
		}
		void TurnUp() {
			if(dir!='s' && dir!='S')
			dir = 'w';
		}
		void TurnDown() {
			if (dir != 'w' && dir != 'W')
			dir = 's';
		}
		void TurnLeft() {
			if (dir != 'd' && dir != 'D')
			dir = 'a';
		}
		void TurnRight() {
			if (dir != 'a' && dir != 'A')
			dir = 'd';
		}
		void Move() {
			system("cls");

			for (int i = size - 1; i > 0; i--) {
				cell[i-1]->CopyPos(cell[i]);
			}
			switch (dir) {
			case 'w':
				cell[0]->MoveUp();
				break;
			case 's':
				cell[0]->MoveDown();
				break;
			case 'a':
				cell[0]->MoveLeft();
				break;
			case 'd':
				cell[0]->MoveRight();
				break;

			}

			if (fruit.GetX()==cell[0]->GetX() && fruit.GetY()==cell[0]->GetY()) {
				AddCell(0,0);
				int x = rand() % 49 + 1;
				int y = rand() % 24 + 1;
				fruit.SetPoint(x, y);
			}
			DrawFrame();
			for (int i = 0;i < size;i++) {
				cell[i]->Draw();
			}
			fruit.Draw();
			DebugFruit();
			if (CheckCollision()) {
				
				system("cls");
				gotoxy(frame_width/2, frame_height/2);
				cout << "Game over";
				Sleep(5000);
				system("cls");
				exit(3);
			}			
			Sleep(100);
		}

		boolean CheckCollision() {
			
			for (int i = 1;i < size;i++) {
				if (cell[i]->GetX() == cell[0]->GetX() && cell[i]->GetY() == cell[0]->GetY())
					return true;
			}
			if (cell[0]->GetX() == 0 || cell[0]->GetX() == frame_width || cell[0]->GetY() == 0 || cell[0]->GetY() == frame_height) 
				return true;
		 
			return false;
		}

		void DrawFrame() {
			for (int i = 0;i <= frame_height; i++) {
				for (int j = 0;j <= frame_width; j++) {
					if (j == 0 || j == frame_width || (i == 0 && j != frame_width) || (i == frame_height && j != frame_width))
					{
						gotoxy(j, i);
						cout << "\xB2";
					}
				
				}
			}

		}
		void Debug() {
			for (int i = 0;i < size; i++)
				cell[i]->Debug();
		}
		void DebugFruit() {			
				fruit.Debug();
		}
};

