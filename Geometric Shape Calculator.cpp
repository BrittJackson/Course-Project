/* Week 4 Assignment 1.cpp : Geometry Calculator.
Using a menu of geometric shape options, program calculates area of user
chosen shape based on measurements input by user.
*/
#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	//Declare variables for area calculator
	int choice;
	double circ, //circle
		rect, //rectangle
		tri, //triangle
		trap, //trapezoid
		sphere, 
		r, //radius
		length, 
		width, 
		base1, 
		base2, 
		height;
	
	const double PI = 3.14159;
	
	//Values for menu choices of shapes
	const int circ_choice = 1, //circle
		rect_choice = 2, //rectangle
		tri_choice = 3, //triangle
		trap_choice = 4, //trapezoid
		sphere_choice = 5, //sphere
		exit_choice = 6; //quit

	//Get shape choice from user
	cout << "Area Calculator Menu\n";
	cout << "1. Calculate the area of a circle\n";
	cout << "2. Calculate the area of a rectangle\n";
	cout << "3. Calculate the area of a triangle\n";
	cout << "4. Calculate the area of a trapezoid\n";
	cout << "5. Calculate the area of a sphere\n";
	cout << "6. Exit\n";
	cout << "Please enter your choice (1-6): ";
	cin >> choice;

	switch (choice)
	{
	//Get radius of circle
	case circ_choice:
		cout << "Radius:\n";
		cin >> r;
		while (r < 0)//if user enters negative number, enter again
		{
			cout << "Invalid. Enter radius again: " << endl;
			cin >> r;

		}
		//calculate area of a circle= PI times radius squared
		circ = PI * pow(r, 2.0);
		cout << "Area= " << circ << endl;
		break;

	//Get length and width of rectangle
	case rect_choice:

		cout << "Length:\n";
		cin >> length;
		while (length < 0) //check if input is negative
		{
			cout << "Invalid. Enter length again: " << endl;
			cin >> length;

		}
		cout << "Width:\n";
		cin >> width;
		while (width < 0) //check if input is negative
		{
			cout << "Invalid. Enter width again: " << endl;
			cin >> width;

		}
		//calculate area of a rectangle = length times width
		rect = length * width;
		cout << "Area= " << rect << endl;
		break;

	//Get base length and height of triangle
	case tri_choice:
		cout << "Base length:\n";
		cin >> base1;
		while (base1 < 0) //check if input is negative
		{
			cout << "Invalid. Enter base length again: " << endl;
			cin >> base1;
		}

		cout << "Height:\n";
		cin >> height;
		while (height < 0) //check if input is negative
		{
			cout << "Invalid. Enter height again: " << endl;
			cin >> height;

		}
		//calculate area of a triangle = base times height times 1/2
		tri = (base1*height)*0.5;
		cout << "Area= " << tri << endl;
		break;

	//Get height and length of both sides of trapezoid
	case trap_choice:
		cout << "Height:\n";
		cin >> height;
		while (height < 0)//validate user input is not negative
		{
			cout << "Invalid. Enter height again: " << endl;
			cin >> height;

		}
		cout << "Length of 1st base:\n";
		cin >> base1;
		//validate user input is not negative
		while (base1 < 0)
		{
			cout << "Invalid. Enter length of 1st base again: " << endl;
			cin >> base1;

		}
		cout << "Length of 2nd base:\n";
		cin >> base2;
		while (base2 < 0)//check if input is negative
		{
			cout << "Invalid. Enter length of 2nd base again: " << endl;
			cin >> base2;

		}
		//calculate area of a trapezoid, side 1+side2 times height times 1/2
		trap = 0.5*height*(base1 + base2);
		cout << "Area= " << trap << endl;
		break;

	//Get radius of sphere
	case sphere_choice:
		cout << "Radius:\n";
		cin >> r;
		while (r < 0) //check if input is negative
		{
			cout << "Invalid. Enter radius again: " << endl;
			cin >> r;

		}
		//calculate area of sphere= 4 times PI times radius squared
		sphere = 4 * PI*pow(r, 2.0);
		cout << "Area= " << sphere << endl;
		break;

	//exit program option
	case exit_choice: 
		cout << "End program" << endl;
		break;

	//user entered invalid input
	default:
		cout << "Invalid choice. Please select a number 1-6\n"
			"and run program again.\n";
	}
	return 0;
}


