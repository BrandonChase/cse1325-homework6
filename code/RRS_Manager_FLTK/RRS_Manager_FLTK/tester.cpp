#include "tester.h"
#include "part_type.h"
#include <iostream>

using namespace std;

void Tester::testOutputingRobotParts()
{
}

void Tester::testOutputingRobotModels()
{
}

void Tester::testFileSavingLoading()
{
	shop.savefile("testing");
	Shop shop2;
	shop2.loadfile("testing");

	if (shop.getCustomers().size() != shop2.getCustomers().size())
	{
		cerr << "failed"; return;
	}
	if (shop.getOrders().size() != shop2.getOrders().size())
	{
		cerr << "failed"; return;
	}
	if (shop.getModels().size() != shop2.getModels().size())
	{
		cerr << "failed"; return;
	}

	if (shop.getSalesAssociates().size() != shop2.getSalesAssociates().size())
	{
		cerr << "failed"; return;
	}

	cout << "passed";
}