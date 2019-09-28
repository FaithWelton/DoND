/*
* FILE : cA1a.c
* PROJECT : SENG1000 - Assignment cA1a
* PROGRAMMER : Faith Madore
* FIRST VERSION : 2019-09-18
* DESCRIPTION :
* The functions in this file are used to
simulate Deal or No Deal as a text
console-based program
*/

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string>
#include <conio.h>

using namespace std;

int main()
{
	double suit[26] = { .01,1,5,10,25,50,75,100,200,300,400,500,750,1000,5000,10000,25000,50000,75000,100000,200000,300000,400000,500000,750000,1000000 };
	double banker;

	int number;
	int remaining = 25;
	int counter = 0;
	int turn = 2;
	int sentinel = 0;
	int x = 25;
	int randomSuit;
	int randomOffer;
	int answer = 1;
	int i;
	srand((unsigned)time(NULL));

	printf("LET'S PLAY. . .\n");
	printf("\n**********************");
	printf("\n*****    DEAL    *****");
	printf("\n*****     OR     *****");
	printf("\n*****   NO DEAL  *****");
	printf("\n**********************\n\n");

	printf("Press any key to continue...\n");
	_getch();

	string mystr;
	cout << "\n What's your name? ";
	getline(cin, mystr);
	cout << "\nHello " << mystr << "! \n Welcome to the game!" << "\n";

	printf("\n Press any key to continue...\n");
	_getch();

	printf("\n**********************\n\n");

	cout << "There are 26 suitcases each containing an amount of money. \n \n";
	cout << "The contents vary from $0.01 to $1,000,000. \n \n";
	cout << "No two suitcases contain the same amount. \n \n";
	cout << "You, " << mystr << " will choose a suitcase to be yours \n \n";
	cout << "After you choose a suitcase, you will pick six more to reveal, one at a time. \n \n";
	cout << "Once six cases have been revealed, the banker will appear with an offer to buy your case. \n \n";
	cout << "If you, " << mystr << " choose to accept the offer, the game is over and the remaining cases are revealed! \n \n";
	cout << "The game goes on until you accept an offer or there are no more cases. \n \n";
	cout << "Good luck! \n \n";

	printf("**********************\n\n");

	printf("\n Press any key to continue...\n");
	_getch();

	while (counter <= 26 && remaining != -1)
	{
		while (counter <= 3 && turn != -1)
		{
			cout << "\nPlease choose your suitcase! [1-26]: ";
			cin >> number;
			cout << "\n";
			if (number > 26 || number < 1)
			{
				cout << "Invalid Input. Enter [1-26] only. Do not enter a previously entered number" << endl;
				continue;
			}
			randomSuit = rand() % 26 + 1;

			cout << "Suitcase " << number << " is $" << suit[ randomSuit - 1 ] << endl;
			cout << "There are still " << remaining << " remaining suitcases to be opened." << endl;

			sentinel = sentinel + 1;
			turn = 2 - sentinel;
			counter = counter + 1;
			remaining = x - counter;

		}
		randomOffer = (rand() % 100 + 15) * 1000;
		counter = counter + 1;
		remaining = remaining - counter;
		cout << "Banker offers you: $" << randomOffer << endl;
		cout << "Deal or No Deal? input[0/1] : ";
		cin >> answer;
		if (answer == 0)
		{
			continue;
		}
		else if (answer == 1)
		{
			cout << "THANKS FOR PLAYING!" << endl;
			break;
		}
	}
	cout << "CONGRATULATIONS!" << endl;
	system("pause");
	return 0;
}