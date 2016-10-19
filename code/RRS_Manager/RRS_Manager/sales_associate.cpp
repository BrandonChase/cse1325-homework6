#include "sales_associate.h"

using namespace std;

ostream& operator<<(ostream& os, const SalesAssociate& sales_associate)
{
	os << sales_associate.name << sales_associate.employee_number;
	return os;
}

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


//GETTERS
int SalesAssociate::getSalesAssociateNumber()
{
	return employee_number;
}