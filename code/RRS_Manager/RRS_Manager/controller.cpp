#include "controller.h"

#include "shop.h"
#include "view.h"
#include <iostream>

using namespace std;

void Controller::cli()
{
	view.showWelcome();
	int command = -1;
	while (command != 0)
	{
		view.showMainMenu();

	}
}