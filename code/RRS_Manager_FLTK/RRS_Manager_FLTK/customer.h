#ifndef CUSTOMER_H
#define CUSTOMER_H 2016

#include <string>
#include "order.h"
#include <vector>
#include <ostream>

class Customer
{
public:
	Customer(std::string p_name, int p_customer_number) : name(p_name), customer_number(p_customer_number) {}
	std::string outputFormattedString() const;
	const std::vector<Order>& getOrders();
	void addOrder(Order p_order);
	int getCustomerNumber();
	std::string saveData() const;
private:
	std::string name;
	int customer_number;
	std::vector<Order> orders;
};


#endif
