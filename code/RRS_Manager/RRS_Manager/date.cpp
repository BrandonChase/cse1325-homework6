#include "date.h"

using namespace std;

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.month << "/" << date.day << "/" << date.year;
	return os;
}

string Date::saveDate() const
{
	return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}