#ifndef SALES_ASSOCIATE_H
#define SALES_ASSOCIATE_H 2016

#include "order.h"
#include <string>
#include <ostream>
#include <vector>

class SalesAssociate
{
public:
	SalesAssociate(std::string p_name, int p_employee_number, std::vector<Order> p_orders) :
		name(p_name), employee_number(p_employee_number), orders(p_orders) {};

	friend std::ostream& operator<<(std::ostream& os, const SalesAssociate& sales_associate);
	const std::vector<Order>& getOrders();

private:
	std::string name;
	int employee_number;
	std::vector<Order> orders;

};

#endif
