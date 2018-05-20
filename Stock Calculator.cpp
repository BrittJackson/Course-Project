/* Assignment 2.cpp : Calculate stock price, commission, stock plus commission, and minimum selling price for profit.
input price per stock
input number of shares bought
calculate total cost of stock
calculate commission
calculate stock total plus commission
calculate minimum price per share to make profit
*/

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	double stock;
	double shares;
	double stock_cost;
	double comm;
	double total;
	double min_price;
	double profit;
	double result;
	
	stock = 21.77;
	shares = 600;
	stock_cost = shares * stock;
	comm = stock_cost*0.02;
	total = stock_cost + comm;
	profit = total / shares;
	min_price = int(profit*100+0.5);
	result = min_price / 100;


	cout << "Amount paid for stock: $" << stock_cost << endl;
	cout << "Amount paid for commission: $" << comm << endl;
	cout << "Total paid for stock and commission: $" << total << endl;
	cout << "Minimum selling price per share to make profit: $"<< result << endl;

    return 0;
}

