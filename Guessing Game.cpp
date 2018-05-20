/* Week5 Assignment1.cpp : Random Number Generator Guessing Game

Generate a random number between 1 and 100 and 
asks the user to guess what the number is. 

If the user’s guess is too high, display “Too high, try again.” 
If the user’s guess is too low, display “Too low, try again.” 

The user gets up to 10 guesses and the program tracks number of guesses.

The program must validate the user’s guess by making sure the 
value entered is between 1 and 100. 

If the value is not between 1 and 100, the user should be 
told to make another guess. 

The invalid input should not count as one of the 10 guesses 
the user is allowed.
 */

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const int max_guesses = 10; //max number of guesses
	int num, //random number generated
		user_guess,
		guesses; //number of guesses made

	srand((int)time(0)); //seed for random number generator
	guesses = 1;
	num = (rand() % 100) + 1; //random number range 1-100

	//Prompt user to guess number
	cout << "Guess a number between 1 and 100: ";
	cin >> user_guess;

	while (guesses < max_guesses) //user gets no more than 10 guesses
	{
		while (user_guess < 1 || user_guess > 100) //validate user input
		{
			cout << "Invalid entry. Please enter a number between 1 and 100: ";
			cin >> user_guess;
		}
		if (user_guess >= 1 && user_guess <= 100) //user guess between 1 and 100
		{
			guesses++;
			if (user_guess > num) //user guesses too high
			{
				cout << "Too high, try again." << endl;
				cin >> user_guess;
			}

			else if (user_guess < num) //user guesses too low
			{
				cout << "Too low, try again." << endl;
				cin >> user_guess;
			}

			else if (user_guess == num) //user guessed correctly
			{
				if (guesses < 5)  //less than 5 guesses
				{
					cout << "Either you know the secret or you got lucky!" << endl;
				}
				else if (guesses >= 5 && guesses <= 7) //user makes between 5 and 7 guesses
				{
					cout << "You're pretty good at this!" << endl;
				}
				else if (guesses >= 8 && guesses <= 10)//user makes between 8 and 10 guesses
				{
					cout << "You'll do better next time." << endl;
				}
				break; //keep statements from repeating
			}
			if (guesses == max_guesses && user_guess != num) //user guesses 10 times incorrectly
			{
				cout << "Sorry- You have taken too many guesses." << endl;
			}
		}
	}

	return 0;
}





