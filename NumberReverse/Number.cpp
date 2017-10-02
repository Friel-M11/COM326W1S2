/*
* Number.cpp
*
* Version information
* Author: Dr. Shane Wilson
* Date:25/09/2017
* Description: Solution to week 1 number reverse challenge
*
* Copyright notice
*/


#include <iostream> // allows program to perform input and output
using namespace std; // program uses names from the std namespace

int main()
{
	int number{ 0 }; // integer read from user
	int num1, num2, num3, num4, num5;

	cout << "Enter a five-digit integer: "; // prompt
	cin >> number; // read integer from user

	num1 = number/10000;
	cout << number / 10000 << "   ";
	//Use the '%' modulus operator to get the remainder afer dividing by 10000
	number = number % 10000; 
	
	num2 = number/1000;
	cout << number / 1000 << "   ";
	number = number % 1000;
	
	num3 = number/100;
	cout << number / 100 << "   ";
	number = number % 100;
	
	num4 = number/10;
	cout << number / 10 << "   ";
	number = number % 10;
	num5 = number;

	cout << number << endl;

	cout << num5 << "   " << num4 << "   " << num3 << "   " << num2 << "   " << num1 << endl;
}
