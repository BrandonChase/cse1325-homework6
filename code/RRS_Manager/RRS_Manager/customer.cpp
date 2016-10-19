#include "customer.h"

using namespace std;

ostream& operator<<(ostream& os, const Customer& customer)
{
	os << customer.name << customer.customer_number;
	return os;
}

const vector<Order>& Customer::getOrders()
{
	return orders;
}

void Customer::addOrder(Order p_order)
{
	orders.push_back(p_order);
}

string Customer::saveData() const 
{
	return  name + "," + to_string(customer_number);
}



//GETTERS

int Customer::getCustomerNumber()
{
	return customer_number;
}

