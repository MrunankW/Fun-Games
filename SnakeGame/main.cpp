#include<iostream>		//basic lib for c++
#include<stdio.h>		//enables c-style writing
#include<windows.h>		//console window
#include<ctime>		//helps to make rand() really random
#include<cmath>		//provides random function
#include<conio.h>	//console input output

using namespace std;

bool gameover;
int height = 20;
int width = 40;
int score, x, y, fruitx, fruity;
enum Direction {STOP = 0, LEFT, RIGHT, UP, DOWN};	//used this because we dont want to smash buttons to move, it should move automatically
Direction dir;	//enum creates a customise datatype (class), here 'dir' is an object of the class 'Direction'
int tailx[100], taily[100];
int tailn = 0;

void setup()
{
	gameover = false;
	dir = STOP;
	score = 0;
	x = width / 2;
	y = height / 2;
	srand(time(NULL));
	fruitx = rand() % (width-2);
	fruity = rand() % height;
}

void draw()
{
	system("cls");
	for (int i = 0; i < width+1; i++)
	{
		printf("#");
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
			{
				printf("#");
			}
			
			if (i == y && j == x)
			{
				printf("O");
			}
			else if (i == fruity && j == fruitx)
			{
				printf("F");
			}
			else
			{
				bool print = false;
				for (int k = 0; k < tailn; k++)
				{
					if (tailx[k] == j && taily[k] == i)
					{
						printf("o");
						print = true;
					}
				}
				if (!print)
				{
					printf(" ");
				}
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width+1; i++)
	{
		printf("#");
	}
	cout << endl;

	printf("Score: %d", score);
}

void input()
{
	if (_kbhit())		// tells that a key is pressed or not from console window
	{
		switch (_getch())		// _getch...gets (ASCII Value) the character which has been pressed
		{
		case 'w':
		{
			dir = UP;
			break;
		}
		case 'a':
		{
			dir = LEFT;
			break;
		}
		case 's':
		{
			dir = DOWN;
			break;
		}
		case 'd':
		{
			dir = RIGHT;
			break;
		}
		case 'e':
		{
			gameover = true;
		}
		}
	}
}

void show()
{
	
}

void logic()
{
	int prevx = tailx[0];
	int prevy = taily[0];
	int tempx, tempy;
	tailx[0] = x;
	taily[0] = y;

	for (int i = 1; i < tailn; i++)
	{
		tempx = tailx[i];
		tempy = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = tempx;
		prevy = tempy;
	}

	switch (dir)
	{
	case UP:
	{
		y--;
		break;
	}
	case LEFT:
	{
		x--;
		break;
	}
	case DOWN:
	{
		y++;
		break;
	}
	case RIGHT:
	{
		x++;
		break;
	}
	default:
		break;
	}

	if (x > width-2 || x < 0 || y > height-1 || y < 0)
	{
		gameover = true;
	}

	for (int i = 0; i < tailn; i++)
	{
		if (tailx[i] == x && taily[i] == y)
		{
			gameover = true;
			break;
		}
	}

	if (x == fruitx && y == fruity)
	{
		tailn++;
		score++;
		fruitx = rand() % (width-2);
		fruity = rand() % height;
	}
}

int main()
{
	setup();
	while (!gameover)
	{
		draw();
		input();
		logic();
		Sleep(50);
	}
	return 0;
}