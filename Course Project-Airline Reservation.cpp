/* Brittney Jackson Course Project.cpp : Airplane Reservation.

Program prompts user with airline reservation menu.
User can reserve seats, see total sales, see row and total seat availability, 
and view seating chart.
*/

#include "stdafx.h"
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

const int row = 15, aisle = 10, price_size = 3; //number of seat rows, columns, and prices

char Seats[row][aisle]; //array holds # and * to indicate available and reserved seats
double prices[price_size]; //array holds seat prices

void displayMenu();//reservation menu
void getUserChoice();
void startingSeats(char Seats[][aisle]);//seating chart before seats booked
void displaySeats(char Seats[][aisle]);
void reserveSeat(char Seats[][aisle], int &, double price[]);
void rowAvail(char Seats[][aisle]);//check seat availability in row
void QuitProgram();

int seats_sold(int); //returns number of remaining seats available

double salesTotal = 0;

int userChoice,
	numAvail,
	seatsSold = 0,
	seatsAvail = 0;

int main()
{
	//open seat prices file
	//store seat prices in array
	ifstream inFile;
	int count = 0;
	inFile.open("C:\\Users\\Brittney\\Desktop\\CISS241\\SeatPrices.txt");
	while (count < price_size && inFile >> prices[count])
		count++;
	inFile.close();

	//display seating chart
	startingSeats(Seats);

	//continue to prompt user with reservation menu 
	do
	{
		//prompt user to make menu selection
		displayMenu();
		getUserChoice();

		switch (userChoice)
		{
		case 1: //reserve seat(s)
			displaySeats(Seats);
			reserveSeat(Seats, seatsSold, prices);
			break;
		case 2: displaySeats(Seats); //show seating chart
			break;
		case 3: rowAvail(Seats);
			break;
		case 4: cout << "\n\nNumber of seats sold: " << seatsSold << endl;//show seats sold
			break;
		case 5:
			cout << "Available seats remaining: " << seats_sold(numAvail); //number of seats remaining on plane
			cout << "\n";
			break;
		case 6:
			cout << fixed << showpoint << setprecision(2);
			cout << "\n\nSales Total: $" << salesTotal << endl;
			break;
		case 7:
			QuitProgram();
			break;
		}
	} while (userChoice != 8);
	return 0;
}
void displayMenu()
{
	cout << "\n\tAirline Reservation Menu\n"
		<< "*****************************************\n"
		<< " Choose From the Following Options (1-7):\n\n"
		<< " 1. Reserve Seat\n"
		<< " 2. Display Seating Chart\n"
		<< " 3. Display Number of Seats Available in Row\n"
		<< " 4. Display Total Number of Seats Sold\n"
		<< " 5. Display Number of Seats Available\n"
		<< " 6. Display Total Sales\n"
		<< " 7. Quit Program\n\n"
		<< "****************************************\n";
}

void getUserChoice()
{
	cout << "Enter choice: ";
	cin >> userChoice;

	//validate user input
	while (userChoice < 1 || userChoice > 7)
	{
		cin.clear();
		cin.ignore();
		cout << "Error. Please choose from the following options (1-7): \n" << endl;
		displayMenu();
		cout << "\n";
		cout << "Enter choice: ";
		cin >> userChoice;
	}
}

void startingSeats(char Seats[][aisle])
{
	//available seats marked with #
	//reserved seats marked with *
	for (int x = 0; x < row; x++)
		for (int y = 0; y < aisle; y++)
			Seats[x][y] = '#';
}

//seating chart
void displaySeats(char Seats[][aisle])
{
	//loop counters
	int x, y;

	cout << "\n";
	cout << "\tFirst Class\n\n"
		<< "\t  Aisle\n   "
		<< "     1|2    3|4";
	for (x = 0; x < 5; x++)
	{
		cout << "\t\t " << endl;
		cout << "Row " << (x + 1);
		cout << "\t";
		for (y = 0; y < 2; y++)
		{
			cout << Seats[x][y];
		}
		cout << "     ";
		for (y = 2; y < 4; y++)
		{
			cout << Seats[x][y];
		}
	}
	cout << "\n\n";
	cout << "\t  Coach\n";
	cout << "\n       5|6|7 8|9|10";
	for (x = 5; x < 15; x++)
	{
		cout << "\t\t" << endl;
		cout << "Row " << (x + 1);
		cout << "\t";
		for (y = 0; y < 3; y++)
		{
			cout << Seats[x][y];
		}
		cout << "   ";
		for (y = 3; y < 6; y++)
		{
			cout << Seats[x][y];
		}
	}
	cout << endl;
}

//check number of seats available in a row
void rowAvail(char Seats[][aisle])
{
	int counter = 0;
	int rowCount;
	cout << "Enter row to see availability (1-15): ";
	cin >> rowCount;
	cout << "\n";

	while (rowCount < 0 || rowCount > 15 || !cin)
	{
		cin.clear();
		cin.ignore();
		cout << "Error. Enter row to see availability (1-15):  ";
		cin >> rowCount;
	}

	if (rowCount >= 1 && rowCount <= 5)
	{
		for (int y = 0; y < 4; y++)
		{
			if (Seats[rowCount - 1][y] == '#')
			{
				counter++;
			}
		}
		cout << "Row " << rowCount << " in First Class has " << counter << " seats available.\n";
	}
	else if (rowCount > 5 && rowCount <= 15)
	{
		for (int y = 0; y < 6; y++)
		{
			if (Seats[rowCount - 1][y] == '#')
			{
				counter++;
			}
		}
		cout << "Row " << rowCount << " in Coach has " << counter << " seats available.\n";
	}
}

//calculate number of seats available
int seats_sold(int numAvail)
{
	numAvail = (80 - seatsSold);
	return numAvail;
}

//function reserves seats, calculates total purchase and total sales
void reserveSeat(char Seats[][aisle], int &numSeats, double prices[])
{
	int row, aisle;
	int seat = 0;
	double purchaseTotal = 0;

	bool reserved; //determine seat availability
	char reply;

	//book seat if it is not reserved and total purchase
	do
	{
		reserved = false;
		while (!reserved)
		{
			cout << "\nSelect seat row (1-15): ";
			cin >> row;
			//validate user input
			while (row < 1 || row > 15 || !cin)
			{
				cin.clear();
				cin.ignore();
				cout << "Error. Select a row (1-15): ";
				cin >> row;
			}

			cout << "\nSelect seat aisle: ";
			cin >> aisle;

			//validate user input
			while (aisle < 1 || aisle > 10 || !cin)
			{
				cin.clear();
				cin.ignore();
				cout << "Error. Select seat aisle: ";
				cin >> aisle;
			}

			//validate only up to 4th aisle can be reserved in first class
			while (row < 6 && aisle > 4)
			{
				cin.clear();
				cin.ignore();
				cout << "Error. Select seat aisle: ";
				cin >> aisle;
			}

			//determine seat availability
			for (int x = 0; x < row; x++)
			{
				for (int y = 0; y < aisle; y++)
				{
					if (Seats[row - 1][aisle - 1] == '*')
					{
						reserved = true;
						break;
					}
				}
			}

			if (!reserved)
			{
				Seats[row - 1][aisle - 1] = '*';
				numSeats++;
				seat++;

				//check seat location to determine price
				if (row <= 5)
				{
					purchaseTotal += prices[0];
				}

				else if (row > 5 && row < 11)
				{
					purchaseTotal += prices[1];
				}

				else if (row > 10)
				{
					purchaseTotal += prices[2];
				}
				break;
			}

			else
			{
				cout << "\nSeat is reserved. Please select another seat.";
				reserved = false;
			}
		}

		cout << "\nWould you like to reserve another seat (y/n)? ";
		cin >> reply;

	} while (reply == 'y' || reply == 'Y');

	//display sales total of all seats purchased
	salesTotal += purchaseTotal;
	cout << fixed << showpoint << setprecision(2);
	
	//display total price for that sales transaction
	cout << "\nTotal: $" << purchaseTotal;
	cout << "\n";
}

void QuitProgram()
{
	cout << "Program ending.\n"
		<< "Goodbye...\n";
	exit(0);
}


