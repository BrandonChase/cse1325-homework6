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
		Controller::executecommand(command);

	}
}

void Controller::executecommand(int command)
{
	switch (command){
		case 1:
		Controller::createmenu();
		break;
		case 2:
		Controller::reportmenu();
		break;
		case 3:
		view.showSaveMenu();
		break;
		default:
		cout << "Not a valid option.\n"
		view.showMainMenu();
	}
}

void createmenu(int command)
{

}

void reportmenu(int command)
{
	
}