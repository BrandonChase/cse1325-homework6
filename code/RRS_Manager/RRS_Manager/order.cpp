#include "order.h"

using namespace std;

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

string Order::outputFormattedString() const
{
	string result;
	result += "Order #: " + to_string(order_number);

	return result;
}

const vector<RobotModel>&  Order::getRobotModels()
{
	return models;
}
// SAVE METHOD FOR LOAD/SAVE

string Order::saveData() const 
{
	return  to_string(order_number) + "," + to_string(customer_number) + "," + to_string(sales_associate_number) + "," + getOrderRobotModels() + "," + to_string(price) + "," + date.saveDate();
}