/* Wk5 Assignment 2.cpp : Reads text file and counts 
numbers in file. Also calculates sum, average, smallest 
and largest numbers in file*/

#include "stdafx.h"
#include "limits.h" //for int_max and int_min
#include <fstream> //to open file
#include <iostream>
using namespace std;


int main()
{
	ifstream inFile; //Read file
	inFile.open("C:\\Users\\Brittney\\Desktop\\CISS241\\Random.txt");

	double num,//numbers in file
		min_num= INT_MAX, //smallest number in file
		max_num=INT_MIN,//biggest number in file
		avg, //average of all numbers in file
		sum = 0;//sum of all numbers in file

	int count = 0;//count numbers in file

	if (inFile) //if file opened successfully
	{
		cout << "File opened\n" << endl; //validate file opened

		while (inFile >> num)
		{
			if (num < min_num) //determine smallest number
			
				min_num = num;
			
			if (num > max_num) //determine biggest number
			
				max_num = num;

			sum += num; //adding numbers
			count++; //incrementing counter
			avg = sum / count; //calculate average
		}


		//output count, sum, average, highest and lowest numbers
		cout << "I counted " << count << " numbers in the file.\n" << endl;
		cout << "The sum of all the numbers in the file is: " << sum << "\n" << endl;
		cout << "The average of all the numbers in the file is: " << avg << "\n" << endl;
		cout << "The smallest number in the file is: " << min_num << "\n" << endl;
		cout << "The biggest number in the file is: " << max_num << "\n" << endl;

		inFile.close();
	}
	else if (inFile.fail()) //file error
	{
		cout << "Error opening file. End program." << endl;
	}

	return 0;
}

