/* Week 7 Assignment 1.cpp : Program calculates annual rainfall, average monthly rainfall, 
and the months with the most and least amounts of rain.*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//function prototypes for total rainfall, average rainfall, 
//and months with lowest/highest rainfall
double getTotal(const double[], int);
double getAverage(const double[], int);
double getLowest(const double[], int, double&);
double getHighest(const double[], int, double&);

//size of months array
const int SIZE = 12;

//array holds months
string Months[SIZE] = { "January","February","March",
"April","May","June","July","August","September","October","November","December" };

//array holds rainfall amounts
double rainFall[12],
	   total, //total annual rainfall
	   average, //average annual rainfall
       lowest,
       highest;

string lowest_month;
string highest_month;

int main()
{
	cout << "Annual Rainfall" << endl;
	cout << "***************" << endl;
	
	//prompt user for rainfall amount for each month and store in two arrays, one with months and other with rainfall amount
	for (int count = 0; count < SIZE; count++)
	{
		cout << "Enter the total amount of rainfall (in inches) for " << Months[count] << ": ";
		cin >> rainFall[count];
		
		//validate user input
		//check if zero or greater
		while (!cin || rainFall[count] < 0)
		{
			cout << "Error. Rainfall amount can only be 0 or greater." << endl;
			cin.clear(); //clear error so program doesn't keep repeating error message
			cin.ignore();
			cout << "Enter the amount of rainfall (in inches): ";
			cin >> rainFall[count];
		}
		cout << "\n";
	}
	

	//get and display total annual rainfall
	total = getTotal(rainFall, SIZE);
	cout << "Total annual rainfall " << total << " inches" << endl;
	cout << "\n";
	
	//get average monthly rainfall amounts
	average = getAverage(rainFall, SIZE);

	//display average annual rainfall
	cout << showpoint << fixed << setprecision(1);
	cout << "Average annual rainfall " << average << " inches" << endl;


	//find the month with the lowest amount of rainfall
	lowest = getLowest(rainFall, SIZE, lowest);
	cout << "The month with the least amount of rain is " << lowest_month << " with " << lowest << " inches of rain." << endl;

	
	//find the month with the highest amount of rainfall
	highest = getHighest(rainFall, SIZE, highest);
	cout << "The month with the most amount of rain is " << highest_month << " with " << highest << " inches of rain." << endl;
	
    return 0;
}

//function to determine annual rainfall
double getTotal(const double rainFall[], int arr_size)
{
	int count;
	double total = 0;

	//increment counter to add monthly rainfall
	for (count = 0; count < arr_size; count++)
	{
		total += rainFall[count];
	}
	return total;
}

//function calculates average annual rainfall
double getAverage(const double rainFall[], int arr_size)
{
	//get total annual rainfall
	total=getTotal(rainFall, SIZE);

	double average = total/arr_size;
	return average;
}

//function finds the month with the lowest amount of rainfall
double getLowest(const double rainFall[], int arr_size, double &lowest)
{
	lowest = rainFall[0];

	for (int count = 1;count < arr_size;count++)
	{
		if (rainFall[count] < lowest)
		{
			lowest = rainFall[count];
			lowest_month = Months[count];
		}
	}
	return lowest;
	return lowest_month[SIZE];
}

//function finds the month with the highest amount of rainfall
double getHighest(const double rainFall[], int arr_size, double &highest)
{
	highest = rainFall[0];

	for (int count = 1;count < arr_size;count++)
	{
		if (rainFall[count] > highest)
		{
			highest = rainFall[count];
			highest_month = Months[count];
		}
	}
	return highest;
	return highest_month[SIZE];
}
