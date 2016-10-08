#include "shop.h"
#include "controller.h"
#include <iostream>

#include "easy_input.h"

using namespace std;

int main()
{
	Shop shop;
	Controller controller(shop);
	controller.CLI();
}