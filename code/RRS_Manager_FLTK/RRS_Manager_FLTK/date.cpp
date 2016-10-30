#include "date.h"
#include <string>

using namespace std;

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.month << "/" << date.day << "/" << date.year;
	return os;
}

std::string Date::formatString() const
{
	return (to_string(month) + "/" + to_string(day) + "/" + to_string(year));
}

// SAVE METHOD FOR LOAD/SAVE

string Date::saveDate() const
{
	return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}