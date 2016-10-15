#include "order.h"

using namespace std;

ostream& operator<<(ostream& os, const Order& order)
{
	os << order.order_number;
	return os;
}