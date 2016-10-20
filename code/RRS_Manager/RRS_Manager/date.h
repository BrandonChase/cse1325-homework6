#ifndef DATE_H
#define DATE_H 2016

#include <ostream>

class Date
{
public:
	Date(int p_month, int p_day, int p_year) : month(p_month), day(p_day), year(p_year) {};
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	std::string saveDate() const;
	std::string formatString() const;
private:
	int day;
	int month;
	int year;
};

#endif