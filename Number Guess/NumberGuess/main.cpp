#include<iostream>
#include<stdio.h>
#include<cstring>
#include<windows.h>
#include<ctime>
#include<cmath>

using namespace std;

int main()
{
	char choose;
	int num = 0, numrand = 0;
	string name = "";
	printf("Enter your Name: \n");
	cin >> name;
	while (true)
	{
		printf("Do you wanna play a game? (y/n) \n");
		cin >> choose;

		if (choose == 'n' || choose == 'N')
		{
			return 0;
		}
		if (choose == 'y' || choose == 'Y')
		{
			break;
		}
	}

	printf("To exit the game type '-1', ENJOY \n");
	srand(time(NULL));	//makes random sequence of numbers everytime (real random numbers)
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("Computer will Generate Random Numbers from 0 to 5, You have to guess the number \n");
	
	while (true)
	{
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		printf("Your Guess: ");
		cin >> num;
		numrand = rand() % 6;	//starts from 0 to 6, displays 0, 1, 2, 3, 4, 5

		if (num == -1)
		{
			break;
		}
		if (numrand == num)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("You Win!! \n");
			printf("Computer guessed %d and you guessed %d \n", numrand, num);
		}
		else
		{
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			printf("You Lose \n");
			printf("Computer guessed %d and you guessed %d \n", numrand, num);
		}
	}

	printf("Thanks for playing \n");

	return 0;
}