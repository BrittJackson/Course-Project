// Week 3 Assignment 1.cpp : Compound Interest Calculator
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;


int main()
{
	double t_comp, ppal, end_bal, int_rate, int_amt, amt;

	cout << "Enter the principal amount: " << endl; //get principal balance
	cin >> ppal;
	cout << "Enter interest rate percentage: " << endl; //get interest rate
	cin >> int_rate;
	cout << "Number of times per year interest is compounded: " << endl; //get times interest is compounded
	cin >> t_comp;

	amt = 1 + (int_rate / 100) / t_comp;
	end_bal = ppal * pow(amt, t_comp);
	int_amt = end_bal - ppal;

	cout << endl;
	cout << "Interest Rate: " << setw(15) << int_rate << "%" << endl << "Times Compounded: " << setw(12) << t_comp << endl;
	cout << "Principal: " << setw(11) << "$" << setw(9) << setprecision(2) << fixed << ppal << endl;
	cout << "Interest: " << setw(12) << "$" << setw(9) << int_amt << endl;
	cout << "Amount in Savings: " << setw(3) << "$" << setw(9) << end_bal << endl;
	return 0;
}

