#include "sales_associate.h"

using namespace std;

const vector<Order>& SalesAssociate::getOrders()
{
	return orders;
}

void SalesAssociate::addOrder(Order p_order)
{
	orders.push_back(p_order);
}

string SalesAssociate::saveData() const
{
	

	string ordernums = to_string(orders[0].getOrderNumber());
	for (int i = 1; i < orders.size(); i++)
	{
		ordernums += "," + to_string(orders[i].getOrderNumber());
	}


	return name + "," + to_string(employee_number) + "," + ordernums;
}


string SalesAssociate::outputFormattedString() const
{
	return (name + " ~ Sales Associate #: " + to_string(employee_number) + "\n");
}

//GETTERS
int SalesAssociate::getSalesAssociateNumber()
{
	return employee_number;
}