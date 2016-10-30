#include "customer.h"
#include "easy_input.h"

using namespace std;

const vector<Order>& Customer::getOrders()
{
	return orders;
}

void Customer::addOrder(Order p_order)
{
	orders.push_back(p_order);
}

string Customer::outputFormattedString() const
{
	return (name + " ~ Customer #: " + to_string(customer_number) + " ~ Total Bill: $" + doubleToString(Order::calculateTotalPrice(orders)) + "\n");
}

// SAVE METHOD FOR LOAD/SAVE

string Customer::saveData() const 
{
	return  name + "," + to_string(customer_number);
}



//GETTERS

int Customer::getCustomerNumber()
{
	return customer_number;
}

