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