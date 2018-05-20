// Week 3 Assignment 2.cpp : Defines the entry point for the console application.
//Calculate num of slices pizza can be divided into
//Calculate num of pizzas needed

#include "stdafx.h"
#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;


int main()
{
	double persons, sl_area, slices, pizza, total_slices, p_area, diameter, r;
	const double PI = 3.14159;

	cout << "What is the diameter of the pizza? " << endl; //Ask user for pizza diameter
	cin >> diameter;
	cout << "How many people at the party? " << endl; //Ask user for num of people at party
	cin >> persons;

	r = diameter / 2; //Calculate pizza radius
	
	//Slices per person and area of a slice
	slices = 3;		
	sl_area = 14.125; 
	
	//Calculate pizza area, total num of slices, num of pizzas
	p_area = PI * pow(r, 2.0); 
	total_slices = p_area / sl_area;
	pizza = (slices*persons) / total_slices;

	cout << endl;

	cout << "Number of slices per pizza: " << setprecision(0) << fixed << total_slices << endl;
	cout << "Number of pizzas needed: "  << setprecision(0) << ceil(pizza) << endl; //can't buy fraction of pizza so round up num of pizzas to whole num

    return 0;
}

