#include "order.h"

using namespace std;

ostream& operator<<(ostream& os, const Order& order)
{
	os << order.order_number;
	return os;
}
int Order::getOrderNumber() const
{
	return order_number;
}



string Order::getOrderRobotModels() const
{
	string modelparts = to_string(models[0].getModelNumber());
	for (int i = 1; i < models.size(); i++)
	{
		modelparts += "," + to_string(models[i].getModelNumber());
	}
	return modelparts;
}


// SAVE METHOD FOR LOAD/SAVE

string Order::saveData() const 
{
	return  to_string(order_number) + "," + to_string(customer_number) + "," + to_string(sales_associate_number) + "," + getOrderRobotModels() + "," + to_string(price) + "," + date.saveDate();
}