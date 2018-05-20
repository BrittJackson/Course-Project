/*Week 4 Assignment 2.cpp : Calculate cost of long distance phone call
Write a program that prompts the user for
the starting time and the number of minutes of the call and
display the charges. The charges are based on the start time
of the call and use the correct rate for the time range it falls into.
The start time will be entered as a floating point number (decimal) in the form HH.MM.
*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double start_time, minutes, time, rate;

	const double min = .60, //for validating minutes user input is not > .59 minutes
		hour = 24.00, //for validating start time user input is not > 23.59
		morning = 00.00, //rate $0.12 per minute
		mid_morning = 07.00, //rate $0.23 per minute
		mid_day = 13.00, //rate $0.55 per minute
		night = 19.01, //rate $0.35 per minute

		morning_rate = 0.12, // start time 00.00-06.59
		midmorning_rate = 0.23, //start time 07.00-12.59
		midday_rate = 0.55,   //start time 13.00-19.00
		night_rate = 0.35;  //start time 19.01-23.59

							//Get start time
	cout << "Enter start time of call in HH.MM: " << endl;
	cin >> start_time;


	//get minutes part of call start time
	time = start_time - static_cast<int>(start_time);

	//Validate user input starting time
	//Validate minutes part of start time
	if (start_time >= hour || time > min)
	{
		cout << "Invalid." << endl;

		cout << "Enter start time of call in HH.MM: " << endl;
		cin >> start_time;
	}

	//get call length in minutes
	if (start_time < hour || time <= min)
	{
		cout << "Enter length of call in minutes: " << endl;
		cin >> minutes;
		if (minutes < 0) //validate minutes user input is not negative
		{
			cout << "Invalid. Number of minutes cannot be less than zero.\n"
				"Please enter a valid number of minutes: " << endl;
			cin >> minutes;

		}
	}

	//Calculate charges for phone call based on start time
	if (start_time >= morning && start_time < mid_morning)
	{
		rate = minutes * morning_rate;
		cout << "Charges for call: $" << setprecision(2) << fixed << rate << endl;
	}

	if (start_time >= mid_morning && start_time < mid_day)
	{
		rate = minutes * midmorning_rate;
		cout << "Charges for call: $" << setprecision(2) << fixed << rate << endl;
	}

	if (start_time >= mid_day && start_time < night)
	{
		rate = minutes * midday_rate;
		cout << "Charges for call: $" << setprecision(2) << fixed << rate << endl;
	}

	if (start_time >= night && start_time <= 23.59)
	{
		rate = minutes * night_rate;
		cout << "Charges for call: $" << setprecision(2) << fixed << rate << endl;
	}

	return 0;
}
