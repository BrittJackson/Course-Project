/* Week7 Assignment2.cpp : Program calculates quarterly sales totals, division sales totals,
annual sales total, lowest and highest sales, and sales average.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int DIV = 4, //sales quarters and totals in column
QTR = 4;//sales divisions and totals in row

		//array holds sales figures
double salesFig[DIV][QTR] = { 0 };

double divTotal,
qtrTotal,
salesTotal = 0,
salesAvg = 0,
lowest_sale = 0,
highest_sale = 0;

int row, col; //loop counters

void displaySales(double[][QTR]);

double getTotal(double[][QTR]),
getAverage(double[][QTR]),
getHighest(double[][QTR], int&, int&),
getLowest(double[][QTR], int&, int&);

string Division[DIV] = { "North", "South" , "East","West" };
string Quarter[QTR] = { "Quarter 1", "Quarter 2","Quarter 3","Quarter 4" };

//quarters and divisions with lowest/highest sales
string highest_div,
highest_qtr,
lowest_qtr,
lowest_div;

int main()
{
	//display each row in division except division total
	for (row = 0; row < DIV; row++)
	{
		//display each column in quarters except quarter totals
		for (col = 0; col < QTR; col++)
		{
			cout << Division[row] << " Division" << "\t" << Quarter[col] << ": ";
			cin >> salesFig[row][col];

			//validate user input
			while (!cin)
			{
				cout << "Invalid input\n" << endl;
				cin.clear();
				cin.ignore();
				cout << "Enter sales figures for:\n" << endl;
				cout << Division[row] << " Division\n";
				cout << Quarter[col] << ": ";
				cin >> salesFig[row][col];
				cout << "\n";
			}
		}
	}
	//display sales table, total sales, and average sales
	displaySales(salesFig);
	cout << endl;

	getTotal(salesFig);
	cout << endl;
	cout << "Total Sales: $" << salesTotal << endl;

	getAverage(salesFig);
	cout << endl;
	cout << "Sales Average: $" << salesAvg / 2 << endl;

	//display lowest and highest sales with corresponding division and quarter
	getLowest(salesFig, row, col);
	cout << endl;
	cout << "Lowest sale was $" << lowest_sale << " in the " << lowest_div << " Division in " << lowest_qtr << "." << endl;

	getHighest(salesFig, row, col);
	cout << endl;
	cout << "Highest sale was $" << highest_sale << " in the " << highest_div << " Division in " << highest_qtr << "." << endl;
	cout << endl;

	return 0;
}

//calculate sales total for all sales figures, not including division and quarter totals
double getTotal(double salesFig[][QTR])
{
	for (row = 0; row < DIV; row++)
	{
		for (col = 0; col < QTR; col++)
		{
			salesTotal += salesFig[row][col];
		}
	}
	return salesTotal;
}

//calculate sales average for all sales figures
double getAverage(double salesFig[][QTR])
{
	for (row = 0; row < DIV; row++)
	{
		for (col = 0; col < QTR; col++)
		{
			salesTotal += salesFig[row][col];
		}
	}
	salesAvg = salesTotal / (row*col);

	return salesAvg;
}

//find lowest sale
double getLowest(double salesFig[][QTR], int &row, int &col)
{
	lowest_sale = salesFig[0][0];
	for (row = 0; row < DIV; row++)
	{
		for (col = 0; col < QTR; col++)
		{
			if ((salesFig[row][col]) <= lowest_sale)
			{
				lowest_sale = salesFig[row][col];
				lowest_div = Division[row];
				lowest_qtr = Quarter[col];
			}
		}
	}
	return lowest_sale;
	return lowest_div[DIV];
	return lowest_qtr[QTR];
}

//find highest sale
double getHighest(double salesFig[][QTR], int &row, int &col)
{
	highest_sale = salesFig[0][0];
	for (row = 0; row < DIV; row++)
	{
		for (col = 0; col < QTR; col++)
		{
			if ((salesFig[row][col]) >= highest_sale)
			{
				highest_sale = salesFig[row][col];
				highest_div = Division[row];
				highest_qtr = Quarter[col];
			}
		}
	}
	return highest_sale;
	return highest_div[DIV];
	return highest_qtr[QTR];
}

//function displays sales figures table
void displaySales(double salesFig[][QTR])
{
	cout << fixed << showpoint << setprecision(2);
	cout << "\nAnnual Sales Figures" << endl;
	cout << "-------------------------" << endl;

	//setup table header for Sales Quarters
	cout << "\t";
	for (row = 0; row < DIV; row++)
	{
		cout << setw(12) << Quarter[row];

	}
	cout << "  " << setw(2) << "Division Total";
	cout << endl;

	//output sales and totals
	for (row = 0;row < DIV; row++)
	{
		cout << left << setw(10) << Division[row];

		//calculate division (row) totals
		for (col = 0; col < QTR; col++)
		{
			double sales = salesFig[row][col];
			cout << right << setw(10) << sales;
			divTotal += sales;
		}
		cout << right << setw(16) << divTotal << endl;

		divTotal = 0.0;
	}
	cout << "\n" << left << setw(14) << "Quarter Total $";

	//calculate quarter (column) totals
	for (col = 0; col < QTR; col++)
	{
		for (row = 0; row < DIV; row++)
		{
			qtrTotal += salesFig[row][col];
		}
		cout << setw(10) << qtrTotal;
		qtrTotal = 0.0;
	}
}

