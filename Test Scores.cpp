/* Week 6 Assignment 1.cpp : Program drops the lowest of 6 test scores 
and averages the remaining 5 scores together.*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

//function gets test scores from user
void getScore(int &);
//function calculates test score average
void calcAverage(int &, int &, int &, int &, int &, int &, int &);

//function finds lowest test score
int findLowest(int &, int &, int &, int &, int &, int&);

//global variables to be accessed by all functions
int test_score1,
test_score2,
test_score3,
test_score4,
test_score5,
test_score6,
user_score,
discard_score;


int main()
{
	//call function for user's test scores
	getScore(test_score1);
	getScore(test_score2);
	getScore(test_score3); 
	getScore(test_score4);
	getScore(test_score5);
	getScore(test_score6);
	
	//call function to get test score average
	calcAverage(discard_score, test_score1, test_score2, test_score3, test_score4,
		test_score5, test_score6);

	return 0;
}

//function for user's test scores
void getScore(int &user_score)
{
	//get test scores
	cout << "Enter your test score: ";
	cin >> user_score;	

	//validate user input
	while (user_score < 1 || user_score > 100)
	{
		cout << "\n";
		cout << "Invalid. Only test scores between 1 and 100 can be entered.\n"
			<< "Enter your test score: ";
		cin >> user_score;
	}
	cout << "\n";
}

//function drops lowest grade and calculates average
void calcAverage(int &discard_score, int &test_score1, int &test_score2, int &test_score3, int &test_score4, 
	int &test_score5, int &test_score6)
{
	//drop lowest score
	discard_score = findLowest(test_score1, test_score2, test_score3, test_score4, test_score5, test_score6);
	
	//add five highest scores and average them
	int sum = (test_score1 + test_score2 + test_score3 + test_score4 + test_score5 + test_score6)-discard_score;
	double average = sum / 5;
	
	cout << "Test score average is: " << average << endl;
}

//function finds the lowest of the six grades
int findLowest(int &test_score1, int &test_score2, int &test_score3, int &test_score4, int &test_score5, int &test_score6)
{
	int lowest_score;
	//size of the array
	const int SIZE = 6;
	
	//test score values as an array
	int test_score[SIZE] = {test_score1, test_score2,test_score3,
		test_score4, test_score5, test_score6 };
	
	//determine lowest test score
	lowest_score = test_score[1];
	for (int count = 1; count<SIZE; count++)
	{
		if (test_score[count]<lowest_score)
			lowest_score = test_score[count];
	}
	return lowest_score;

}


