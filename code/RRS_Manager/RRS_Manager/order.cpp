#include "order.h"

using namespace std;

ostream& operator<<(ostream& os, const Order& order)
{
	os << order.order_number;
	return os;
}

string Order::saveData() const 
{
	return  to_string(order_number) + "," + to_string(customer_number) + "," + to_string(sales_associate_number) + "," + "ROBOT MODEL" + "," + to_string(price) + "," + "DATE";
}
