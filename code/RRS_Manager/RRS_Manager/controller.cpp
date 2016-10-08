#include "controller.h"

#include "shop.h"
#include "view.h"
#include "easy_input.h"
#include <iostream>

using namespace std;

void Controller::CLI()
{
	view.showWelcome();
	mainMenuCLI();
}

void Controller::mainMenuCLI()
{
	int command = -1;
	while (command != 9) // 9) Quit program
	{
		view.showMainMenu();
		command = inputInt("Command: ");
		executeMainMenuCommand(command);
	}
}

void Controller::createCLI()
{
	int command = -1;
	while (command != 9) // 9) Quit to main menu
	{
		view.showCreateMenu();
		command = inputInt("Command: ");
		executeCreateMenuCommand(command);
	}
}

void Controller::reportCLI()
{
	int command = -1;
	while (command != 9) // 9) Quit to main menu
	{
		view.showReportMenu();
		command = inputInt("Command: ");
		executeReportMenuCommand(command);
	}
}

void Controller::executeMainMenuCommand(int command)
{
	switch (command)
	{
		case 1: // Create
			createCLI();
			break;

		case 2: // Report
			reportCLI();
			break;

		case 3: // Save
			view.showSaveMenu();
			break;

		default: // Unknown
			cerr << "\t***Error: " << command << " is an invalid Main Menu option.\n";
			break;
	}
}

void Controller::executeCreateMenuCommand(int command)
{
	switch(command)
	{
		case 1: // Order
			break;

		case 2: // Customer
			break;

		case 3: // Sales Associate
			break;

		case 4: // Robot Model
			break;

		case 5: // Robot Part
			break;

		default: //Unkown
			cerr << "\t***Error: " << command << " is an invalid Create option.\n";
			break;
	}
}

void Controller::executeReportMenuCommand(int command)
{
	switch (command)
	{
		case 1: // Orders
			break;

		case 2: // Customers
			break;

		case 3: // Sales Associates
			break;

		case 4: // Robot Models
			break;

		case 5: // Robot Parts
			break;

		default: //Unkown
			cerr << "\t***Error: " << command << " is an invalid Report option.\n";
			break;
	}
}