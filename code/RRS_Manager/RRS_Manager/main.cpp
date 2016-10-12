#include "shop.h"
#include "controller.h"
#include "tester.h"
#include <iostream>

#include "easy_input.h"

using namespace std;

int main()
{
	Tester::testOutputingRobotParts();

	Shop shop;
	Controller controller(shop);
	controller.CLI();
}