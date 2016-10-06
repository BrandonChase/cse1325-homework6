#include "controller.h"

#include "shop.h"
#include "view.h"
#include "easy_input.h"
#include <iostream>

using namespace std;

void Controller::cli()
{
	view.showWelcome();
	int command = -1;
	while (command != 0)
	{
		view.showMainMenu();
		command=inputselect();
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
		cout << "Not a valid option.\n";
		view.showMainMenu();
	}
}

void Controller::createmenu(int command)
{
	view.showCreateMenu();
	switch(inputselect()){
		case 1:
		// order
		break;
		case 2:
		// customer
		break;
		case 3:
		// sales associate
		break;
		case 4:
		// robot model
		break;
		case 5:
		// robot component
		break;
		case 6:
		// sales associate
		break;
		default:
		cout << "Not a valid option.\n";
		view.showCreateMenu();
	}
}

void Controller::reportmenu(int command)
{

}

int Controller::inputselect(){
	int input_n;
	cin >> input_n;
	return input_n;
}