/* Assignment 1.cpp : Calculates city and highway MPG.
input gas tank capacity
input total miles in city for one tank
input total miles on highway for one tank
calculate miles per gallon--city and hwy
*/
#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	
	double car_tank;
	double city;
	double hwy;

	car_tank = 16;
	city = 345;
	hwy = 460;
	
	cout << "City MPG is " << city / car_tank << endl;
	cout << "Highway MPG is " << hwy / car_tank << endl;
	
    return 0;
}

