#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

char field[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char player = 'X';
int chances = 0;

void show()
{
	//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	system("cls");
	printf("Welcome to Tic Tac Toe!! \n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c ", field[i][j]);
		}
		cout << endl;
	}
}

void input()
{
	int l = 0;
	printf("Player %c's turn, ", player);
	printf("Enter your location: ");
	cin >> l;

	if (l == 1)
	{
		if (field[0][0] == '1')
		{
			field[0][0] = player;
		}
		else
		{
			printf("The location has been used \n");
			input();
		}
	}
	else if (l == 2)
	{
		if (field[0][1] == '2')
		{
			field[0][1] = player;
		}
		else
		{
			printf("The location has been used \n");
			input();
		}
	}
	else if (l == 3)
	{
		if (field[0][2] == '3')
		{
			field[0][2] = player;
		}
		else
		{
			printf("The location has been used \n");
			input();
		}
	}
	else if (l == 4)
	{
		if (field[1][0] == '4')
		{
			field[1][0] = player;
		}
		else
		{
			printf("The location has been used \n");
			input();
		}
	}
	else if (l == 5)
	{
		if (field[1][1] == '5')
		{
			field[1][1] = player;
		}
		else
		{
			printf("The location has been used \n");
			input();
		}
	}
	else if (l == 6)
	{
		if (field[1][2] == '6')
		{
			field[1][2] = player;
		}
		else
		{
			printf("The location has been used \n");
			input();
		}
	}
	else if (l == 7)
	{
		if (field[2][0] == '7')
		{
			field[2][0] = player;
		}
		else
		{
			printf("The location has been used \n");
			input();
		}
	}
	else if (l == 8)
	{
		if (field[2][1] == '8')
		{
			field[2][1] = player;
		}
		else
		{
			printf("The location has been used \n");
			input();
		}
	}
	else if (l == 9)
	{
		if (field[2][2] == '9')
		{
			field[2][2] = player;
		}
		else
		{
			printf("The location has been used \n");
			input();
		}
	}
}

char win()
{
	if (field[0][0] == 'X' && field[0][1] == 'X' && field[0][2] == 'X')
		return 'X';
	if (field[1][0] == 'X' && field[1][1] == 'X' && field[1][2] == 'X')
		return 'X';
	if (field[2][0] == 'X' && field[2][1] == 'X' && field[2][2] == 'X')
		return 'X';
	if (field[0][0] == 'X' && field[1][0] == 'X' && field[2][0] == 'X')
		return 'X';
	if (field[0][1] == 'X' && field[1][1] == 'X' && field[2][1] == 'X')
		return 'X';
	if (field[0][2] == 'X' && field[1][2] == 'X' && field[2][2] == 'X')
		return 'X';
	if (field[0][0] == 'X' && field[1][1] == 'X' && field[2][2] == 'X')
		return 'X';
	if (field[0][2] == 'X' && field[1][1] == 'X' && field[2][0] == 'X')
		return 'X';

	if (field[0][0] == 'O' && field[0][1] == 'O' && field[0][2] == 'O')
		return 'O';
	if (field[1][0] == 'O' && field[1][1] == 'O' && field[1][2] == 'O')
		return 'O';
	if (field[2][0] == 'O' && field[2][1] == 'O' && field[2][2] == 'O')
		return 'O';
	if (field[0][0] == 'O' && field[1][0] == 'O' && field[2][0] == 'O')
		return 'O';
	if (field[0][1] == 'O' && field[1][1] == 'O' && field[2][1] == 'O')
		return 'O';
	if (field[0][2] == 'O' && field[1][2] == 'O' && field[2][2] == 'O')
		return 'O';
	if (field[0][0] == 'O' && field[1][1] == 'O' && field[2][2] == 'O')
		return 'O';
	if (field[0][2] == 'O' && field[1][1] == 'O' && field[2][0] == 'O')
		return 'O';

	return '/';
}

void toggle_player()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}

void rematch()
{
	field[0][0] = '1';
	field[0][1] = '2';
	field[0][2] = '3';
	field[1][0] = '4';
	field[1][1] = '5';
	field[1][2] = '6';
	field[2][0] = '7';
	field[2][1] = '8';
	field[2][2] = '9';
}

int main()
{
	//printf("Welcome to Tic Tac Toe!! \n");
	show();
	int l = 0;
	while (1)
	{
		chances++;
		input();
		show();
		if (win() == 'X')
		{
			printf("Player X is Winner \n");
			break;
		}
		else if(win() == 'O')
		{
			printf("Player O is Winner \n");
			break;
		}
		else if (win() == '/' && chances == 9)
		{
			chances = 0;
			printf("Its a Draw!! \n");
			char ans;
			printf("Want to Play Again? (y/n) \n");
			cin >> ans;
			if (ans == 'y')
			{
				rematch();
			}
			else
			{
				break;
			}

		}
		toggle_player();
	}
	return 0;
}