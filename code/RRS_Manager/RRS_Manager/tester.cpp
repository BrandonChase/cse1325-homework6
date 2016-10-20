#include "tester.h"

#include "shop.h"
#include "view.h"
#include "part_type.h"
#include <iostream>

using namespace std;

void Tester::testOutputingRobotParts()
{
	Shop shop;
	View view(shop);
	
	shop.populateShopForTesting();
	view.listRobotModels(shop.getModels(), "");
}