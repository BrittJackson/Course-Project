/* Week 6 Assignment 2.cpp : 
Rock, Paper, Scissors, Lizard, Spock Game.

User plays against the computer.
A menu prompts the user to make their choice.
Program keeps going until there is a winner.
The computer's choice is displayed and the winner declared.

*/

#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

int getUserChoice(int &);
int getComputerChoice(int &);
void determineWinner(int &, int &);
void displayChoice(int &);
void gameMenu();

int user_choice;
int comp_choice;

//game choices
const int Rock = 1,
          Paper = 2,
          Scissors = 3,
          Lizard = 4,
          Spock = 5;

int main()
{
	//display game menu
	gameMenu();

	cout << "\n";

	//get user's choice
	getUserChoice(user_choice);

	//get computer's choice
	getComputerChoice(comp_choice);

	//get game winer
	determineWinner(user_choice, comp_choice);
	
	cout << "\n\n";

	//exit program when there's a winner
	exit(0);
    return 0;
}

//function for user's choice
int getUserChoice(int &user_choice)
{
	cout << "Enter your choice (1-5): ";
	cin >> user_choice;
	
	//validate user input
	while (user_choice < 1 || user_choice > 5)
	{
		cout << "\nError. Choice must be a valid number.\nChoose from the following menu (1-5):"
			<< "\n\n";
		
		//display menu again
		gameMenu();
		cout << "\n"
			<< "Enter your choice: ";
		cin >> user_choice;
		getComputerChoice(comp_choice);
	}
	return 0;
}

//function for computer's choice
int getComputerChoice(int &comp_choice)
{
	//seed for random number generator
	srand((int)time(0));
	
	//random number between 1 and 5
	comp_choice = (rand() % (5)) + 1;
	
	return comp_choice;
}

//function to determine game winner
void determineWinner(int &user_choice, int &comp_choice)
{
	cout << endl;
	
	//display computer's choice
	displayChoice(comp_choice);
	cout << "\n";

	//keep playing if it's a tie
	while (user_choice == comp_choice)
	{
		cout << "Tie! Play again:"
			 << "\n\n";
		//display game menu again and get user input
		gameMenu();
		cout << "\n";
		getUserChoice(user_choice);
		displayChoice(comp_choice);
		cout << "\n";
	}

	if (user_choice == Rock)
	{
		if (comp_choice == Paper)
		{
			cout << "You lose! Paper covers rock.";
		}

		else if (comp_choice == Scissors)
		{
			cout << "You win! Rock breaks scissors.";
		}

		else if (comp_choice == Lizard)
		{
			cout << "You win! Rock crushes lizard.";
		}

		else if (comp_choice == Spock)
		{
			cout << "You lose! Spock vaporizes rock.";
		}
	}

	if (user_choice == Paper)
	{
		if (comp_choice == Rock)
		{
			cout << "You win! Paper covers rock.";
		}
		else if (comp_choice == Scissors)
		{
			cout << "You lose! Scissors cuts paper.";
		}

		else if (comp_choice == Lizard)
		{
			cout << "You lose! Lizard eats paper.";
		}

		else if (comp_choice == Spock)
		{
			cout << "You win! Paper disproves Spock.";
		}
	}

	if (user_choice == Scissors)
	{
		if (comp_choice == Paper)
		{
			cout << "You win! Scissors cuts paper.";
		}

		else if (comp_choice == Rock)
		{
			cout << "You lose! Rock breaks scissors.";
		}

		else if (comp_choice == Lizard)
		{
			cout << "You win! Scissors decapitates lizard.";
		}

		else if (comp_choice == Spock)
		{
			cout << "You lose! Spock smashes scissors.";
		}
	}

	if (user_choice == Lizard)
	{
		if (comp_choice == Rock)
		{
			cout << "You lose! Rock crushes lizard";
		}

		else if (comp_choice == Paper)
		{
			cout << "You win! Lizard eats paper.";
		}

		else if (comp_choice == Scissors)
		{
			cout << "You lose! Scissors decapitates lizard.";
		}

		else if (comp_choice == Spock)
		{
			cout << "You win! Lizard poisons Spock.";
		}
	}

	if (user_choice == Spock)
	{
		if (comp_choice == Rock)
		{
			cout << "You win! Spock vaporizes rock.";
		}

		else if (comp_choice == Paper)
		{
			cout << "You lose! Paper disproves Spock.";
		}

		else if (comp_choice == Scissors)
		{
			cout << "You win! Spock smashes scissors.";
		}

		else if (comp_choice == Lizard)
		{
			cout << "You lose! Lizard poisons Spock.";
		}
	}	
}

//display computer's choice
void displayChoice(int &comp_choice)
{
	cout << "The computer chose " << comp_choice << "."
		 << "\n";
}

//display choices in game menu
void gameMenu()
{
	cout<<"***Rock, Paper, Scissors, Lizard, Spock Game***\n"
		<<"-----------------------------------------------\n"
		<<"\n1. Rock\n"
		<< "2. Paper\n"
		<< "3. Scissors\n"
		<< "4. Lizard\n"
		<< "5. Spock\n";
}
