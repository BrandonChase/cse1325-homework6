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
		int type_int = inputInt("Part Type: ");
		PartType type(type_int);

		string name = inputString("Part Name: ");
		int part_number = inputInt("Part Number: ");
		while (part_number <= 0)
		{
			cout << "\t***Error: Part numbers can't be nonpositive!\n";
			part_number = inputInt("Part Number: ");
		}
		double weight = inputDouble("Part Weight [lb]: ");
		while (weight <= 0)
		{
			cout << "\t***Error: Part weight can't be nonpositive!\n";
			weight = inputDouble("Part Weight [lb]: ");
		}
		double price = inputDouble("Part Price [$]: ");
		while (price <= 0)
		{
			cout << "\t***Error: Price can't be nonpositive!\n";
			price = inputDouble("Part Price [$]: ");
		}
		string description = inputString("Part Description: ");

		if (type_int == 0) //Torso
		{
			int battery_compartments = inputInt("# of Battery Compartments: ");;
			while (battery_compartments < 1 && battery_compartments > 3)
			{
				cout << "\t***Error: Torsos can only have 1, 2, or 3 battery compartments!\n";
				battery_compartments = inputInt("# of Battery Compartments: ");
			}
			shop.addTorso(Torso(name, part_number, weight, price, type, description, battery_compartments));
		} 
		else if (type_int == 1) //Head
		{
			shop.addHead(Head(name, part_number, weight, price, type, description));
		}

		else if (type_int == 2) //Arm
		{
			double power_consumed = inputDouble("Power consumed by arm [W]: ");
			while (power_consumed <= 0)
			{
				cout << "\t***Error: Power consumed can't be nonpositive!\n";
				power_consumed = inputDouble("Power consumed by arm [W]: ");
			}
			shop.addArm(Arm(name, part_number, weight, price, type, description, power_consumed));
		}

		else if(type_int == 3) //Locomotor
		{
			double max_speed = inputDouble("Max speed of locomotor [MPH]: ");
			while (max_speed <= 0)
			{
				cout << "\t***Error: Max speed can't be nonpositive!\n";
				max_speed = inputDouble("Max speed of locomotor [MPH]: ");
			}

			double power_consumed = inputDouble("Power consumed by locomotor [W]: ");
			while (power_consumed <= 0)
			{
				cout << "\t***Error: Power consumed can't be nonpositive!\n";
				power_consumed = inputDouble("Power consumed by locomotor [W]: ");
			}

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