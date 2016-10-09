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
	const vector<Head>& heads_x = shop.getHeads();
	const vector<Locomotor>& locomotors_x = shop.getLocomotors();
	const vector<Torso>& torsos_x = shop.getTorsos();
	const vector<Battery>& batteries_x = shop.getBatteries();
	const vector<Arm>& arms_x = shop.getArms();

	cout << "Creating a Robot Model: \n";
	string model_name = inputString(" Model Name: ");
	int model_number = inputIntGreaterThan("Model Number: ",0,"Model numbers must be positive!");
	double model_cost;
	
	view.listRobotParts(0); // Choose head
	int head_choice = inputIntInRange("Head choice: ", 1, heads_x.size(), "Invalid head choice!");
	
	view.listRobotParts(1); // Choose locomoter
	int locometer_choice = inputIntInRange("Locomoter choice: ", 1, locomoters_x.size(), "Invalid locomoter choice!");
	
	view.listRobotParts(2); // Choose torsos
	int torso_choice = inputIntInRange("Torso choice: ", 1, torsos_x.size(), "Invalid locomoter choice!");
	
	view.listRobotParts(3); // Choose batteries
	int battery_choice = inputIntInRange("Battery choice: ", 1, batteries_x.size(), "Invalid locomoter choice!");
	num_batteries = inputIntInRange("Number of batteries: ", 1, torsos_x.numbatteries(), "Invalid number of batteries!"); // New getter for number of batteries
	
	view.listRobotParts(4); // Choose arms
	int arm_choice = inputIntInRange("Arm choice: ", 1, arms_x.size(), "Invalid locomoter choice!");
	int num_arms = inputIntInRange("Number of arms: ", 1, 2, "Invalid number of arms!");

	model_cost=;
	double model_price = inputDoubleGreaterThan("Model Price [$]: ",model_cost,"Price must be greater than cost!"); // May run into an issue with double casting?
	shop.addRobotModel(RobotModel(model_name,model_number,model_price,));
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
		break;
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
		view.listRobotParts(-1); // outputs all 
		break;

	default: //Unkown
	cerr << "\t***Error: " << command << " is an invalid Report option.\n";
}
}