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