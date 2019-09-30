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

#include"cA1a.h"
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string>
#include<conio.h>
#include<iomanip>
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
	/* FUNCTION : double/array
	* DESCRIPTION :
	* This holds the values of each suitcase in an array with an index of 26
	*/

	double suit[26] = { .01,1,5,10,25,50,75,100,200,300,400,500,750,1000,5000,10000,25000,50000,75000,100000,200000,300000,400000,500000,750000,1000000 };

	/* FUNCTION : boolean/array
	* DESCRIPTION :
	* This is an array that holds an index of the cases that can still be chosen by the player
	*/

	bool caseChoices[26] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };

	string answer = "";

	int number = 0;
	int remaining = 26;
	int turn = 6;
	int turnInterval = 6;
	int playerCase = -1;
	
	/* DESCRIPTION :
	* Introduction to print a welcome message
	* and asks user to press any key to continue
	*/

	cout << "WELCOME! LET'S PLAY. . .\n";
	cout << "\n********************************";
	cout << "\n**********    DEAL    **********";
	cout << "\n**********     OR     **********";
	cout << "\n**********   NO DEAL  **********";
	cout << "\n********************************\n\n";

	cout << "Press any key to play \n";
	_getch();

	system("CLS"); /*Clears screen*/

	/* DESCRIPTION
	* Ask player for their name
	* Print hello player, welcome to the game
	* and asks user to press any key to continue
	*/
	cout << "\n********************************";

	string name;
	cout << "\n What's your name? ";
	getline(cin, name);
	cout << "\nHello " << name << "! \n Welcome to the game!" << "\n";

	cout << "\n********************************";


	cout << "\n Press any key to continue...\n";
	_getch();

	system("CLS"); /*Clears screen*/

	/*
	*Intstructions for how to play
	*/

	cout << "\n******************************** \n";

	cout << "There are 26 suitcases each containing an amount of money. \n \n";
	cout << "The contents vary from $0.01 to $1,000,000. \n \n";
	cout << "No two suitcases contain the same amount. \n \n";
	cout << "You, " << name << " will choose a suitcase to be yours \n \n";
	cout << "After you choose a suitcase, you will pick six more to reveal, one at a time. \n \n";
	cout << "Once six cases have been revealed, the banker will appear with an offer to buy your case. \n \n";
	cout << "If you, " << name << " choose to accept the offer, the game is over and the remaining cases are revealed! \n \n";
	cout << "The game goes on until you accept an offer or there are no more cases. \n \n";
	cout << "Good luck! \n";

	cout << "\n********************************";

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

	cout << "\n******************************** \n";


	cout << "\nPlease choose your suitcase! [1-26]: ";
	number = getNum();
	cout << "\n";

	cout << "\n******************************** \n";


	while (number > 26 || number < 1 || caseChoices[number - 1] == true)
	{
		cout << "Invalid Input. Enter [1-26] only. Please choose a suitcase!" << endl;
		number = getNum();
	}

	remaining = remaining - 1;



	cout << "\n There are still " << remaining << " remaining suitcases to be opened." << endl;

	caseChoices[number - 1] = true;
	playerCase = number - 1;

	/* FUNCTION : nested while loops
	* DESCRIPTION :
	* First while loop is used to ensure the loop runs while the remaining cases do not equal 0
	* Second while loop is used to ensure the loop runs while the turns do not equal 0
	* As long as the conditions of the while loop are met the console will ask the user
	* to choose a suitcase then wait for input
	* after the inner if statement has run to ensure player chooses an available case
	* the remaining suitcases go down by 1
	* then the console will print the value of the chosen suitcase
	* The console will then ask the user to press any key to continue
	*/


	while (remaining != 0)
	{
		while (turn != 0)
		{
			cout << "\n \n Please choose a suitcase to reveal! [1-26]: ";
			number = getNum();
			cout << "\n";

			/* FUNCTION : if statement
			* DESCRIPTION :
			* This function is used to ensure the player chooses suitcase 1-26 only and
			* will print an error and ask player to try again if the conditions are true
			*/


			if (number > 26 || number < 1 || caseChoices[number -1] == true)
			{
				cout << "Invalid Input. Enter [1-26] only. Do not enter a previously entered number" << endl;
				continue;
			}

			remaining = remaining - 1;

			cout << "Suitcase " << number << " is $" << fixed << setprecision(2) << suit[ number - 1 ] << endl;

			cout << "\n Press any key to continue...\n";
			_getch();

			system("CLS"); /*Clears screen*/


			cout << "\n There are still " << remaining << " remaining suitcases to be opened: \n" << endl;

			caseChoices[number - 1] = true;

			/* FUNCTION : for loop with if statement
			* DESCRIPTION :
			* This function is used to display the suitcases that
			* have not been chosen yet
			*/

			for (int s = 0; s < 26; s = s + 1)
			{
				if (caseChoices[s] == false)
				{
					cout << " [ " << s + 1 << " ] ";
				}
			}

			turn = turn - 1;
		}
		
		/* FUNCTION : if statement
		* DESCRIPTION : 
		* This function is used to ask the player if they would like to switch their chosen suitcase
		* to the last remaining suitcase available before the game is done
		*/

		if (turn == 0 && remaining == 1)
		{
			cout << "\n Would you like to switch your case? [y/n] " << endl;
			getline(cin, answer); 

			/* FUNCTION : while loop
			* DESCRIPTION :
			* This function is used to ensure player cannot choose something other than "y" or "n"
			* if the player does not choose "y" or "n"
			* The console will display "Invalid input" and ask the user to try again
			* Then it will wait for the player input
			*/

			while (answer != "n" && answer != "y")
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

			/* FUNCTION : if statement
			* DESCRIPTION :
			* This function is accessed when the player chooses "y" to the 
			* offer to switch their suitcase
			* If the player inputs "y" the players original case will
			* be switched with the last remaining suitcase
			* Then the console will display the players suitcase value
			* and finally the console will display the final unopened cases value
			*/


			if (answer == "y")
			{
				int oldFinalCase = finalCase;
				finalCase = playerCase;
				playerCase = oldFinalCase;
			}
			cout << "\n Congratulations " << name << "! Your chosen suitcase contained: $" << suit[playerCase] << endl;
			cout << "\n The remaining cases are:" << endl;
			cout << "\n Case #: " << finalCase + 1 << " | value: " << suit[finalCase] << endl;
			cout << "\n Press any key to continue...\n";
			_getch();

			system("CLS"); /*Clears screen*/

			break;
		}

		/* FUNCTION : double, for statement
		* DESCRIPTION :
		* This function is created to determine what cases are still remaining
		* then add the sum of the values inside of those cases
		* to then divide by the number of remaining cases to find the average
		* of the values inside the remaining cases
		* to create a random offer for the banker to offer the player
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

		/* FUNCTION : for loop
		* DESCRIPTION :
		*console will display the cases that the player has chosen so far in the game
		*as well as the $ value inside of the cases
		*Banker will begin to give random offers to the player for their chosen case : randomOffer for playerCase
		*console will prompt player to input "y" to accept the offer
		*or "n" to decline the offer
		*/

		cout << "\n******************************** \n";

		cout << "\n \n Your previously opened cases are: \n";

		for (int s = 0; s < 26; s = s + 1)
		{
			if (caseChoices[s] == true && s != playerCase)
			{
				cout << "\n Case #: " << s + 1 << " | value: $" << suit[s] << endl;
			}
		}

		cout << "\n******************************** \n";

		cout << "\n Banker offers you: $" << randomOffer << endl; 

		cout << "\n Deal or No Deal? [y/n] : ";
		getline(cin, answer);

		cout << "\n******************************** \n";

		/* FUNCTION : while loop
		* DESCRIPTION :
		* This function determines if the player input y or n
		* If player does not choose "y" or "n" the console will 
		* ask them to try again
		*/

		while (answer != "n" && answer != "y")
		{
			cout << "Invalid Input. Enter [y/n] only. Please try again!" << endl;
			getline(cin, answer);
		}

		/* FUNCTION : nested if statement
		* DESCRIPTION :
		* If player chooses "n" we go into another if statement 
		* turnInterval is assigned to turn so when turnInterval goes down by 1
		* turn also goes down by 1
		*/

		if (answer == "n")
		{
			if (turnInterval > 1 || remaining == 1)
			{
				turnInterval = turnInterval - 1;
			}
			turn = turnInterval;
		}

		/* FUNCTION : else if statement
		* DESCRIPTION :
		* If the player chooses "y" they accept the bankers offer
		* If the offer is accepted the console will print congratulations message
		* The console will then also print the value inside of the players original case
		* Then the console will display the remaining suitcases
		*/

		else if (answer == "y")
		{
			system("CLS"); /*Clears screen*/

			cout << "\n Congratulations " << name << "! You have accepted the bankers offer of: $" << randomOffer << endl;
			cout << "\n Your chosen suitcase contained: $" << suit[playerCase] << endl;
			cout << "\n The remaining cases are:" << endl;

			/* FUNCTION : for loop with if statement
			* DESCRIPTION :
			* This function will display the cases that still remain after
			* the player accepts the banker offer 
			* as well as their values
			*/

			for (int s = 0; s < 26; s = s + 1)
			{
				if (caseChoices[s] == false)
				{
					cout << "\n Case #: " << s + 1 << " | value: " << suit[s] << endl;
				}
			}

			cout << "\n Press any key to continue...\n";
			_getch();

			system("CLS"); /*Clears screen*/

			break;
		}
	}
	return 0;
}