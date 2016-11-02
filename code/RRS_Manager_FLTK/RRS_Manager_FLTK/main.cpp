#include "shop.h"
#include "fltk_controller.h"

#include "tester.h"
#include <iostream>

#include "easy_input.h"

using namespace std;

int main()
{
	Shop shop;
	//Tester t(shop);
	FLTKController controller(shop);
	controller.GUI();
}