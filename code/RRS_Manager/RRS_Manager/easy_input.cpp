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

int inputIntLessThan(string prompt, int upper_bound, string reminder)
{
	int result = inputInt(prompt);
	while (result >= upper_bound)
	{
		cout << "\t***Error: " << reminder << endl;
		result = inputInt(prompt);
	}

	return result;
}

int inputIntGreaterThan(string prompt, int lower_bound, string reminder)
{
	int result = inputInt(prompt);
	while (result <= lower_bound)
	{
		cout << "\t***Error: " << reminder << endl;
		result = inputInt(prompt);
	}

	return result;
}

int inputIntInRange(string prompt, int lower_bound, int upper_bound, string reminder)
{
	int result = inputInt(prompt);
	while (result < lower_bound || result > upper_bound || upper_bound == lower_bound)
	{
		cout << "\t***Error: " << reminder << endl;
		result = inputInt(prompt);
	}

	return result;
}

int inputDoubleLessThan(string prompt, double upper_bound, string reminder)
{
	double result = inputDouble(prompt);
	while (result >= upper_bound)
	{
		cout << "\t***Error: " << reminder << endl;
		result = inputDouble(prompt);
	}

	return result;
}

int inputDoubleGreaterThan(string prompt, double lower_bound, string reminder)
{
	double result = inputDouble(prompt);
	while (result <= lower_bound)
	{
		cout << "\t***Error: " << reminder << endl;
		result = inputDouble(prompt);
	}

	return result;
}

int inputDoubleInRange(string prompt, double lower_bound, double upper_bound, string reminder)
{
	double result = inputDouble(prompt);
	while (result < lower_bound || result > upper_bound)
	{
		cout << "\t***Error: " << reminder << endl;
		result = inputDouble(prompt);
	}

	return result;
}

Date inputDate(std::string prompt)
{
	cout << prompt;
	int month, day, year;
	try
	{
		string temp;
		getline(cin >> ws, temp, '/');
		month = stoi(temp);
		getline(cin >> ws, temp, '/');
		day = stoi(temp);
		getline(cin >> ws, temp);
		year = stoi(temp);
	}

	catch (...)
	{
		cerr << "\t***Error: Entered invalid numeric value for either month, day, or year. Try again.\n";
		cin.ignore();//ignore possible extra characters left in buffer from crash
		inputDate(prompt);
	}

	if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1950)
	{
		cerr << "\t***Error: Entered invalid date format. Year must be greater than 1949. Try again.\n";
		inputDate(prompt);
	}

	Date result(month, day, year);
	return result;
}