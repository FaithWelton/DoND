/*
* FILE : cA1a.c
* PROJECT : SENG1000 - Assignment cA1a
* PROGRAMMER : Faith Madore
* FIRST VERSION : 2019-09-18
* DESCRIPTION :
* The functions in this file are used to
* simulate Deal or No Deal as a text
* console-based program
*/

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string>
#include <conio.h>
#include "cA1a.h"
#include <iomanip>
#pragma warning(disable: 4996)

using namespace std;

int getNum(void)
{
	/* function limitation: only accepts 120 characters of input */
	char record[121] = { 0 };
	int number = 0;

	/* use fgets() to get a string from the keyboard */
	fgets(record, 121, stdin);

	/* extract the number from the string; sscanf() returns a number
	*corresponding with the number of items it found in the string */
	if (sscanf(record, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		*the system, set number to -1 */
		number = -1;
	}
	return number;
}


int main()
{
	double suit[26] = { .01,1,5,10,25,50,75,100,200,300,400,500,750,1000,5000,10000,25000,50000,75000,100000,200000,300000,400000,500000,750000,1000000 };

	bool caseChoices[26] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };

	string answer = "";

	int number = 0;
	int remaining = 26;
	int turn = 6;
	int turnInterval = 6;
	int playerCase = -1;
	
	/*
	*Introduction
	*/

	cout << "LET'S PLAY. . .\n";
	cout << "\n**********************";
	cout << "\n*****    DEAL    *****";
	cout << "\n*****     OR     *****";
	cout << "\n*****   NO DEAL  *****";
	cout << "\n**********************\n\n";

	cout << "Press any key to continue...\n";
	_getch();

	system("CLS"); /*Clears screen*/

	/*
	*Ask player for their name
	*/

	string name;
	cout << "\n What's your name? ";
	getline(cin, name);
	cout << "\nHello " << name << "! \n Welcome to the game!" << "\n";

	cout << "\n Press any key to continue...\n";
	_getch();

	system("CLS"); /*Clears screen*/

	/*
	*Intstructions for how to play
	*/

	cout << "\n**********************\n\n";

	cout << "There are 26 suitcases each containing an amount of money. \n \n";
	cout << "The contents vary from $0.01 to $1,000,000. \n \n";
	cout << "No two suitcases contain the same amount. \n \n";
	cout << "You, " << name << " will choose a suitcase to be yours \n \n";
	cout << "After you choose a suitcase, you will pick six more to reveal, one at a time. \n \n";
	cout << "Once six cases have been revealed, the banker will appear with an offer to buy your case. \n \n";
	cout << "If you, " << name << " choose to accept the offer, the game is over and the remaining cases are revealed! \n \n";
	cout << "The game goes on until you accept an offer or there are no more cases. \n \n";
	cout << "Good luck! \n \n";

	cout << "\n**********************\n\n";

 	cout << "\n Press any key to continue...\n";
	_getch();
	
	system("CLS"); /*Clears screen*/

	/*
	*For loop to randomize suitcase contents
	*/

	for (int c = 0; c < 26; c = c + 1)
	{
		int randomNum = rand();
		randomNum = randomNum % 26;
		double saveNum = suit[c];
		suit[c] = suit[randomNum];
		suit[randomNum] = saveNum;
	}

	/*
	*While loop to ask user to input suitcase choices
	*/

	cout << "\nPlease choose your suitcase! [1-26]: ";
	number = getNum();
	cout << "\n";

	while (number > 26 || number < 1 || caseChoices[number - 1] == true)
	{
		cout << "Invalid Input. Enter [1-26] only. Please choose a suitcase!" << endl;
		number = getNum();
	}

	remaining = remaining - 1;

	cout << "There are still " << remaining << " remaining suitcases to be opened." << endl;

	caseChoices[number - 1] = true;
	playerCase = number - 1;

	while (remaining != 0)
	{
		while (turn != 0)
		{
			cout << "\nPlease choose a suitcase to reveal! [1-26]: ";
			number = getNum();
			cout << "\n";
			if (number > 26 || number < 1 || caseChoices[number -1] == true)
			{
				cout << "Invalid Input. Enter [1-26] only. Do not enter a previously entered number" << endl;
				continue;
			}

			remaining = remaining - 1;


			cout << "Suitcase " << number << " is $" << fixed << setprecision(2) << suit[ number - 1 ] << endl;
			cout << "There are still " << remaining << " remaining suitcases to be opened." << endl;

			caseChoices[number - 1] = true;

			for (int s = 0; s < 26; s = s + 1)
			{
				if (caseChoices[s] == false)
				{
					cout << " [ " << s + 1 << " ] ";
				}
			}

			turn = turn - 1;
		}
		
		if (turn == 0 && remaining == 1)
		{
			cout << "\n Would you like to switch your case? [y/n] " << endl;
			getline(cin, answer);

			while (answer != "n" && answer != "y");
			{
				cout << "Invalid Input. Enter [y/n] only. Please try again!" << endl;
				getline(cin, answer);
			}

			int finalCase;

			for (int s = 0; s < 26; s = s + 1)
			{
				if (caseChoices[s] == false)
				{
					finalCase = s;
				}
			}

			if (answer == "y")
			{
				int oldFinalCase = finalCase;
				finalCase = playerCase;
				playerCase = oldFinalCase;
			}
			cout << "\n Your chosen suitcase contained: S" << suit[playerCase] << endl;
			cout << "\n Case #: " << finalCase + 1 << " value: " << suit[finalCase] << endl;

			break;
		}

		/*
		*Random offers from the banker after 6 cases are opened, 
		*then 5 more and so on until player chooses to accept offer
		*or player runs out of suitcases to open
		*/

		double sum = 0;

		for (int s = 0; s < 26; s = s + 1)
		{
			if (caseChoices[s] == false)
			{
				sum = sum + suit[s];
			}
		}

		double avg = sum / remaining;
		double randomOffer;

		randomOffer = rand() % 110 + 75.0;

		randomOffer = (randomOffer / 100) * avg;

		cout << "\n Banker offers you: $" << randomOffer << endl; 
		cout << "\n Deal or No Deal? [y/n] : ";
		getline(cin, answer);

		while (answer != "n" && answer != "y")
		{
			cout << "Invalid Input. Enter [y/n] only. Please try again!" << endl;
			getline(cin, answer);
		}
		if (answer == "n")
		{
			if (turnInterval > 1 || remaining == 1)
			{
				turnInterval = turnInterval - 1;
			}
			turn = turnInterval;
		}
		else if (answer == "y")
		{
			cout << "\n Congratulations! You have accepted the bankers offer of: S" << randomOffer << endl;
			cout << "\n Your chosen suitcase contained: S" << suit[playerCase] << endl;
			cout << "\n The remaining cases are:" << endl;

			for (int s = 0; s < 26; s = s + 1)
			{
				if (caseChoices[s] == false)
				{
					cout << "\n Case #: " << s + 1 << " value: " << suit[s] << endl;
				}
			}

			break;
		}
	}
	system("pause");
	return 0;
}