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
		view.listPartTypes();
		int type_int = inputIntInRange("Part Type: ", 0, 4, "Invalid part type number!");
		PartType type(type_int);

		string name = inputString("Part Name: ");
		int part_number = inputIntGreaterThan("Part Number: ", 0, "Part numbers must be positive!");
		double weight = inputDoubleGreaterThan("Part Weight [lb]: ", 0, "Part weight must be positive!");
		double price = inputDoubleGreaterThan("Part Price [$]: ", 0, "Price must be positive!");
		string description = inputString("Part Description: ");

		if (type_int == 0) //Torso
		{
			int battery_compartments = inputIntInRange("# of Battery Compartments: ", 1, 3, "Torsos can only have 1, 2, or 3 battery compartments!");
			shop.addTorso(Torso(name, part_number, weight, price, type, description, battery_compartments));
		} 
		else if (type_int == 1) //Head
		{
			shop.addHead(Head(name, part_number, weight, price, type, description));
		}

		else if (type_int == 2) //Arm
		{
			double power_consumed = inputDoubleGreaterThan("Power consumed by arm [W]: ", 0, "Power consumed must be positive!");
			shop.addArm(Arm(name, part_number, weight, price, type, description, power_consumed));
		}

		else if(type_int == 3) //Locomotor
		{
			double max_speed = inputDoubleGreaterThan("Max speed of locomotor [MPH]: ", 0, "Max speed must be positive!");
			double power_consumed = inputDoubleGreaterThan("Power consumed by arm [W]: ", 0, "Power consumed must be positive!");
			shop.addLocomotor(Locomotor(name, part_number, weight, price, type, description, max_speed, power_consumed));
		}

		else //Unkown
		{
			cerr << "\t***Error: " << command << " is an invalid Create option.\n";
		}
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
		view.listRobotParts();
		break;

	default: //Unkown
		cerr << "\t***Error: " << command << " is an invalid Report option.\n";
		break;
	}
}