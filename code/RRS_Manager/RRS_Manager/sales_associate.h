#ifndef SALES_ASSOCIATE_H
#define SALES_ASSOCIATE_H 2016

#include "order.h"
#include <string>
#include <iostream>
#include <vector>
#include <ostream>
#include <sstream>

class SalesAssociate
{
public:
	SalesAssociate(std::string p_name, int p_employee_number) : name(p_name), employee_number(p_employee_number) {};

	friend std::ostream& operator<<(std::ostream& os, const SalesAssociate& sales_associate);
	const std::vector<Order>& getOrders();
	void addOrder(Order p_order);
	int getSalesAssociateNumber();
	std::string saveData() const;
private:
	std::string name;
	int employee_number;
	std::vector<Order> orders;

};

#endif
