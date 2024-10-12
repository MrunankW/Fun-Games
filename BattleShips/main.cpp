#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cmath>
#include <ctime>
#include <cstring>

using namespace std;

const int rows = 10;
const int cols = 10;
int max_ships = 10;
int map[rows][cols];

void clear()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			map[i][j] == 0;
		}
	}
}

void show()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ",map[i][j]);
		}
		cout << endl;
	}
}

void set_ships()
{
	srand(time(NULL));
	int s = 0, r = 0, c = 0;
	while (s < max_ships)
	{
		r = rand() % 10;
		c = rand() % 10;
		if (map[r][c] != 1)
		{
			s++;
			map[r][c] = 1;
		}
	}
}

bool attack(int r, int c)
{
	if (map[r][c] == 1)
	{
		map[r][c] = 2;
		return true;
	}
	return false;
}

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	int x = 0, y = 0;
	char ans;
	clear();
	show();
	set_ships();
	int no_ships = 10;
	printf("Welcome to the battle ships, you have to guess coordinates to destroy the 10 ships \n");
	while (true)
	{
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		printf("Do you want to Surrender? (y/n) \n");
		cin >> ans;
		if (ans == 'y' || ans == 'Y')
		{
			break;
		}

		if (no_ships == 0)
		{
			printf("We Won The BATTLE!!!\n");
			return 0;
		}

		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		printf("Enter the cordinates \n");
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		if (attack(x, y))
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("Good Work Soldier, Enemy Ship Destroyed!!\n");
			no_ships--;
		}
		else
		{
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			printf("You missed it Soldier\n");
		}
		printf("Enemies left: %d \n", no_ships);
	}
	show();
	return 0;
}