#include "order.h"
#include "easy_input.h"

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

string Order::outputFormattedString(string offset, bool show_details) const
{
	string result;
	result += "Order #: " + to_string(order_number);
	if (show_details)
	{
		result += "\n" + offset + "Date: " + date.formatString() + "\n";
		result += offset + "Price: $" + doubleToString(price) + "\n";
		result += offset + "Customer #: " + to_string(customer_number) + "\n";
		result += offset + "Sales Associate #: " + to_string(sales_associate_number) + "\n";
	}

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

double Order::calculateTotalPrice(std::vector<Order> orders)
{
	double result = 0;
	for (Order o : orders)
	{
		result +=o.getPrice();
	}

	return result;
}

double Order::getPrice() const
{
	return price;
}