#include "easy_input.h"

#include <string>
#include <iostream>
#include <exception>

using namespace std;

string inputString(string prompt)
{
	string result;
	cout << prompt;
	getline(cin >> ws, result);
	return result;
}

double inputDouble(string prompt)
{
	string temp;
	temp = inputString(prompt);
	try
	{
		double result = stod(temp.c_str());
		return result;
	}

	catch (const exception& e)
	{
		cerr << "\t***Error: Entered invalid numeric value.  Try again.\n";
		return inputDouble(prompt);
	}
}


int inputInt(string prompt)
{
	double input = inputDouble(prompt);
	int result = (int)input;
	if (result != input)
	{
		cerr << "\t***Error: Entered floating-point number when prompted for integer.  Try again.\n";
		return inputInt(prompt);
	}
	return result;
}