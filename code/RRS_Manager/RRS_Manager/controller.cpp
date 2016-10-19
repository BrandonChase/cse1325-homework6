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

void Controller::loadsaveCLI()
{
	int command = -1;
	while(command != 9)
	{
		view.showLoadSaveMenu();
		command = inputInt("Command: ");
		executeLoadSaveMenuCommand(command);
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
	loadsaveCLI();
	break;
	
	case 9999:
	shop.populateShopForTesting();
	cout << "Populated shop for testing ...\n";
	break;

	case 9:
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
	createOrder();
	break;

	case 2: // Customer
	createCustomer();
	break;

	case 3: // Sales Associate
	createSalesAssociate();
	break;

	case 4: // Robot Model
		createRobotModel(); // Seperate method due to declarations within switch/case is no go.
		break;

	case 5: // Robot Part
	createRobotPart();
	break;

	case 9:
	break;

	default:
	cerr << "\t***Error: " << command << " is an invalid Create Menu option!\n";
	break;
}
}

void Controller::executeReportMenuCommand(int command)
{
	switch (command)
	{
	case 1: // Orders
	view.listOrders(shop.getOrders());
	break;

	case 2: // Customers
	view.listCustomers();
	break;

	case 3: // Sales Associates
	view.listSalesAssociates();
	break;

	case 4: // Robot Models
	view.listRobotModels();
	break;

	case 5: // Robot Parts
	view.listRobotParts(PartType::ALL);
	break;

	case 9:
	break;

	default: //Unkown
	cerr << "\t***Error: " << command << " is an invalid Report Menu option.\n";
}
}

void Controller::executeLoadSaveMenuCommand(int command)
{
	switch(command)
	{
		case 1:
		loadfile();
		break;

		case 2:
		savefile();
		break;

		case 9:
		break;
		
		default:
		cerr << "\t***Error: " << command << " is an invalid Load/Save Menu option.\n";
	}
}

//CREATE FUNCTIONS

void Controller::createRobotModel()
{
	if (shop.isAnyPartListEmpty())
	{
		cout << "\t***Alert: The shop doesn't have an adequate supply of robot part types to create an entire model.\n";
		cout << "\t***Suggestion: Ensure you've created at least one robot part of each necessary type.\n";
		return;
	}

	const vector<Head>& heads_x = shop.getHeads();
	const vector<Locomotor>& locomotors_x = shop.getLocomotors();
	const vector<Torso>& torsos_x = shop.getTorsos();
	const vector<Battery>& batteries_x = shop.getBatteries();
	const vector<Arm>& arms_x = shop.getArms();

	cout << "Creating a Robot Model... \n";
	string model_name = inputString("Model Name: ");
	int model_number = inputIntGreaterThan("Model Number: ", 0, "Model numbers must be positive!");
	double model_cost;

	view.listRobotParts(PartType::HEAD); // Choose head
	int head_choice = inputIntInRange("Head choice: ", 0, heads_x.size(), "Invalid head choice!");

	view.listRobotParts(PartType::LOCOMOTOR); // Choose locomotor
	int locomotor_choice = inputIntInRange("locomotor choice: ", 0, locomotors_x.size(), "Invalid locomotor choice!");

	view.listRobotParts(PartType::TORSO); // Choose torsos
	int torso_choice = inputIntInRange("Torso choice: ", 0, torsos_x.size(), "Invalid torso choice!");

	view.listRobotParts(PartType::BATTERY); // Choose batteries
	int battery_choice = inputIntInRange("Battery choice: ", 0, batteries_x.size(), "Invalid battery choice!");
	int num_batteries = inputIntInRange("Number of batteries: ", 1, torsos_x[torso_choice].getNumBatteries(), "Invalid number of batteries!"); // New getter for number of batteries

	view.listRobotParts(PartType::ARM); // Choose arms
	int arm_choice = inputIntInRange("Arm choice: ", 0, arms_x.size(), "Invalid arm choice!");
	int num_arms = inputIntInRange("Number of arms: ", 1, 2, "Invalid number of arms!");

	model_cost = heads_x[head_choice].getPrice() + locomotors_x[locomotor_choice].getPrice() + torsos_x[torso_choice].getPrice() + batteries_x[battery_choice].getPrice()*num_batteries + arms_x[arm_choice].getPrice()*num_arms;
	double model_price = inputDoubleGreaterThan("Model Price [$]: ", model_cost, "Price must be greater than cost!"); // May run into an issue with double casting?
	shop.addRobotModel(RobotModel(model_name, model_number, model_price, heads_x[head_choice], torsos_x[torso_choice], locomotors_x[locomotor_choice], batteries_x[battery_choice], arms_x[arm_choice]));
}

void Controller::createRobotPart()
{
	view.listPartTypes();
	int type_int = inputIntInRange("Part Type: ", 0, 4, "Invalid part type number!");
	PartType type(type_int);

	string name = inputString("Part Name: ");
	int part_number = inputIntGreaterThan("Part Number: ", 0, "Part numbers must be positive!");
	double weight = inputDoubleGreaterThan("Part Weight [lb]: ", 0, "Part weight must be positive!");
	double price = inputDoubleGreaterThan("Part Price [$]: ", 0, "Price must be positive!");
	string description = inputString("Part Description: ");

	if (type_int == PartType::TORSO) //Torso
	{
		int battery_compartments = inputIntInRange("# of Battery Compartments: ", 1, 3, "Torsos can only have 1, 2, or 3 battery compartments!");
		shop.addTorso(Torso(name, part_number, weight, price, type, description, battery_compartments));
	}
	else if (type_int == PartType::HEAD) //Head
	{
		shop.addHead(Head(name, part_number, weight, price, type, description));
	}

	else if (type_int == PartType::ARM) //Arm
	{
		double power_consumed = inputDoubleGreaterThan("Power consumed by arm [W]: ", 0, "Power consumed must be positive!");
		shop.addArm(Arm(name, part_number, weight, price, type, description, power_consumed));
	}

	else if (type_int == PartType::LOCOMOTOR) //Locomotor
	{
		double max_speed = inputDoubleGreaterThan("Max speed of locomotor [MPH]: ", 0, "Max speed must be positive!");
		double power_consumed = inputDoubleGreaterThan("Power consumed by arm [W]: ", 0, "Power consumed must be positive!");
		shop.addLocomotor(Locomotor(name, part_number, weight, price, type, description, max_speed, power_consumed));
	}

	else if (type_int == PartType::BATTERY) //Battery
	{
		double contained_energy = inputDoubleGreaterThan("Energy contained by battery [kWh]", 0, "Energy contained must be positive!");
		shop.addBattery(Battery(name, part_number, weight, price, type, description, contained_energy));
	}

	else //Unkown
	{
		cerr << "\t***Error: Invalid Create option.\n";
	}
}

void Controller::createOrder()
{
	vector<SalesAssociate> associates = shop.getSalesAssociates();
	vector<Customer> customers = shop.getCustomers();
	vector<RobotModel> models = shop.getModels();
	if (associates.size() == 0)
	{
		cout << "\t***Alert: The shop doesn't have any sales associates to create the order.\n";
		return;
	}

	if (customers.size() == 0)
	{
		cout << "\t***Alert: The shop doesn't have any customers for which to create an order.\n";
		return;
	}

	if (models.size() == 0)
	{
		cout << "\t***Alert: The shop doesn't have any robot models with which to create an order.\n";
		return;
	}

	Date order_date = inputDate("Date of Order [m/d/yr] [12/31/1950]: ");

	view.listSalesAssociates();
	int sales_associate_index = inputIntInRange("Sales Associate Index: ", 0, associates.size() - 1, "Invalid Sales Associate Index!");

	view.listCustomers();
	int customer_index = inputIntInRange("Customer Index: ", 0, customers.size() - 1, "Invalid Customer Index!");

	int order_number = inputIntGreaterThan("Order Number: ", 0, "Order Number must be positive!");
	
	vector<RobotModel> order_models;
	int add_another_model = 1;
	while (add_another_model)
	{
		view.listRobotModels();
		int model_index = inputIntInRange("Desired Robot Model Index: ", 0, models.size() - 1, "Invalid Robot Model Index!");
		RobotModel current_model = models[model_index];
		order_models.push_back(current_model);
		add_another_model = inputIntInRange("Add another model for this order? [0 = No, 1 = Yes]: ", 0, 1, "Answer must be 0 or 1!");
	}
	
	double order_price = Order::calculatePrice(order_models);
	int customer_num = customers[customer_index].getCustomerNumber();
	int sales_Associate_number = associates[sales_associate_index].getSalesAssociateNumber();
	shop.addOrder(Order(order_number, customer_num, sales_Associate_number, models, order_price, order_date));
	
}

void Controller::createCustomer()
{
	string name = inputString("Customer Name: ");
	int customer_number = inputIntGreaterThan("Customer Number: ", 0, "Customer number must be positive!");
	shop.addCustomer(Customer(name, customer_number));
}

void Controller::createSalesAssociate()
{
	string name = inputString("Sales Associate Name: ");
	int sa_number = inputIntGreaterThan("Sales Associate Number: ", 0, "Customer number must be positive!");
	shop.addSalesAssociate(SalesAssociate(name, sa_number));
}



vector<string> Controller::splitter(const string &s, char delim) 
{
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}






void Controller::loadfile()
{
	cout << "Name of file to read from: ";
	string infile;
	cin >> infile;
	string line, s; 
	vector<string> spline, load_tags = {"/Head/","/Torso/","/Battery/","/Arm/","/Locomotor/","/RobotModel/","/Customers/","/SalesAssociates/","/Orders/","/Blank/"};

	ifstream loadfile(infile);
	if(!loadfile) throw runtime_error("Unable to load specified file " + infile);
	if (loadfile.good())  
	{
		bool is_changing = false; 
		int cur_tagtype = 0;
		while (getline(loadfile, line)) 
		{
			int i = 0, j = 0;
			is_changing = false;
			spline = splitter(line, ',');

			for (j = 0; j < load_tags.size(); j++)
			{
				if(load_tags[j] == spline[0])
				{
					is_changing = true;
					cur_tagtype = j;
				}
			}
			if(!is_changing)
			{
				switch(cur_tagtype)
				{
					case 0:
					shop.addHead(Head(spline[0], stoi(spline[1]), stod(spline[2]), stod(spline[3]), PartType::HEAD, spline[4]));
					break;
					
					case 1:
					shop.addTorso(Torso(spline[0], stoi(spline[1]), stod(spline[2]), stod(spline[3]), PartType::TORSO, spline[4], stoi(spline[5])));
					break;

					case 2:
					shop.addBattery(Battery(spline[0], stoi(spline[1]), stod(spline[2]), stod(spline[3]), PartType::BATTERY, spline[4], stod(spline[5])));
					break;

					case 3:
					shop.addArm(Arm(spline[0], stoi(spline[1]), stod(spline[2]), stod(spline[3]), PartType::ARM, spline[4], stod(spline[5])));
					break;

					case 4:
					shop.addLocomotor(Locomotor(spline[0], stoi(spline[1]), stod(spline[2]), stod(spline[3]), PartType::LOCOMOTOR, spline[4], stod(spline[5]), stod(spline[6])));
					break;

					case 5:
					shop.LoadRobotModel(spline[0], stoi(spline[1]), stod(spline[2]), stoi(spline[3]), stoi(spline[4]), stoi(spline[5]), stoi(spline[6]), stoi(spline[7])); // 3-n are IDs for parts
					break;

					case 6:
					shop.addCustomer(Customer(spline[0],  stoi(spline[1])));
					break;

					case 7:
					shop.addSalesAssociate(SalesAssociate(spline[0], stoi(spline[1])));
					break;

					case 8:
					//LoadOrder(spline[0])
					//shop.addOrder(Order(order_number, customer_num, sales_Associate_number, models, order_price, order_date));
					break;
				}
			}

		}

		loadfile.close();
	}

}



void Controller::savefile()
{
	cout << "Name of file to write to: ";
	string outfile;
	cin >> outfile;
	ofstream ofs;
	ofs.open(outfile.c_str());
	if(!ofs) throw runtime_error("Unable to open output file " + outfile);


	const vector<Head>& heads = shop.getHeads();
	const vector<Locomotor>& locomotors = shop.getLocomotors();
	const vector<Torso>& torsos = shop.getTorsos();
	const vector<Battery>& batteries = shop.getBatteries();
	const vector<Arm>& arms = shop.getArms();
	const vector<SalesAssociate>& associates = shop.getSalesAssociates();
	const vector<Customer>& customers = shop.getCustomers();
	const vector<Order>& orders = shop.getOrders();
	vector<RobotModel> models = shop.getModels();

	for (int i = 0; i < PartType::NUM_OF_PART_TYPES; i++)
	{
		ofs << "/" << PartType(i) << "/\n";

		if (i==PartType::HEAD)
		{
			for (int j = 0; j < heads.size(); j++)
			{
				ofs <<  heads[j].saveData() << "\n";
			}
		}
		if (i==PartType::TORSO)
		{
			for (int j = 0; j < torsos.size(); j++)
			{
				ofs <<  torsos[j].saveData() << "\n";
			}
		}
		if (i==PartType::BATTERY)
		{
			for (int j = 0; j < batteries.size(); j++)
			{
				ofs <<  batteries[j].saveData() << "\n";
			}
		}
		if (i==PartType::ARM)
		{
			for (int j = 0; j < arms.size(); j++)
			{
				ofs <<  arms[j].saveData() << "\n";
			}
		}
		if (i==PartType::LOCOMOTOR)
		{
			for (int j = 0; j < locomotors.size(); j++)
			{
				ofs <<  locomotors[j].saveData() << "\n";
			}
		}		
	}

	ofs << "/RobotModel/\n";
	for (int i = 0; i < models.size(); i++)
	{
		ofs << models[i].saveData() << "\n";
	}



	ofs << "/Customers/\n";
	for (int i = 0; i < customers.size(); i++)
	{
		ofs << customers[i].saveData() << "\n";
	}



	ofs << "/SalesAssociates/\n";
	for (int i = 0; i < associates.size(); i++)
	{
		ofs << associates[i].saveData() << "\n";
	}



	ofs << "/Orders/\n";
	for (int i = 0; i < orders.size(); i++)
	{
		ofs << orders[i].saveData() << "\n";
	}


	ofs.close();
}