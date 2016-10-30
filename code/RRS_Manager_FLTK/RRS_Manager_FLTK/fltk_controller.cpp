#include "fltk_controller.h"
#include <FL/Fl_Menu_Bar.H>

#include "shop.h"
#include "view.h"
#include "easy_input.h"
#include <iostream>

using namespace std;

int Controller::GUI()
{
	Fl_Menu_Item menuitems[] = {
		{"&File", 0, 0, 0, FL_SUBMENU },
			{"&New", FL_ALT + 'n', 0},
			{"&Open", FL_ALT + 'o', 0},
			{"&Save", FL_ALT + 's', 0},
			{"Save As", FL_ALT + FL_SHIFT + 's', 0},
			{"Save Default", FL_ALT + FL_SHIFT + 'd', 0},
			{"&Quit", FL_ALT + 'q', 0},
			{0},
		{"&Edit", 0, 0, 0, FL_SUBMENU },
			{"&Undo", 0, 0},
			{"Cu&t", 0, 0},
			{"&Copy", 0, 0},
			{"&Paste", 0, 0},
			{0},
		{"&Create", 0, 0, 0, FL_SUBMENU },
			{"Order", 0, 0, 0},
			{"Customer", 0, 0, 0},
			{"Sales Associate", 0, 0, 0},
			{"Robot Part", 0, 0, 0},
			{"Robot Model", 0, 0, 0},
			{0},
		{"&Report", 0, 0, 0, FL_SUBMENU },
			{"Invoice", 0, 0, 0},
			{"All Orders", 0, 0, 0},
			{"Orders by Customer", 0, 0, 0},
			{"Orders by Sales Associate", 0, 0, 0},
			{"All Customers", 0, 0, 0},
			{"All Sales Associates", 0, 0, 0},
			{"All Robot Models", 0, 0, 0},
			{"All Robot Parts", 0, 0, 0},
			{0},
		{"&Help", 0, 0, 0, FL_SUBMENU },
			{"&Manual", 0, 0, 0},
			{"&About", 0, 0, 0},
			{0},
		{0}
	};
	const int x =640;
	const int y = 480;
	const int border =10;
	//fl_register_images();
	Fl_Window *win= new Fl_Window{x+3*border, y+3*border, "Robbie Robot Shop v0.15"};
	Fl_Box *box = new Fl_Box{border, border, x+border, y+border};
	Fl_Menu_Bar *menubar;
	//View *view;


	menubar = new Fl_Menu_Bar(0,0,x+3*border,30);
	menubar->menu(menuitems);

	//win->resizable(box);
	win->end();
	win->show();
	return(Fl::run());
}












void Controller::executeMainMenuCommand(int command)
{
	switch (command)
	{
	case 1: // Create
	break;

	case 2: // Report
	break;

	case 3: // Save
	break;
	
	case 9999: // Auto populates shop for testing
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
	createRobotModel(); 
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
	cout << "Total Price of All Orders = $" << doubleToString(Order::calculateTotalPrice(shop.getOrders())) << endl;
	reportOrders(shop.getOrders(), "");
	break;

	case 2: // Customers
	reportCustomers(shop.getCustomers());
	break;

	case 3: // Sales Associates
	reportSalesAssociates(shop.getSalesAssociates());
	break;

	case 4: // Robot Models
	reportRobotModels(shop.getModels(), "");
	break;

	case 5: // Robot Parts
	view.listRobotParts(PartType::ALL, "");
	break;

	case 9:
	break;

	default: //Unkown
	cerr << "\t***Error: " << command << " is an invalid Report Menu option.\n";
}
}

void Controller::executeLoadSaveMenuCommand(int command)
{
	string filepath;

	switch(command)
	{
		case 1:
		try
		{
			filepath = inputString("Name of file to read from: ");
			shop.loadfile(filepath + ".shop");
		}

		catch (...)
		{
			cerr << "\t***Error: Failed to load file.\n";
		}
		break;

		case 2:
		try
		{
			filepath = inputString("Name of file to write to: ");
			shop.savefile(filepath + ".shop");
		}

		catch (...)
		{
			cerr << "\t***Error: Failed to save file.\n";
		}
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
	while (!shop.isModelNumberUnique(model_number))
	{
		cout << "\t***Error: That model number is already taken! Try again!\n";
		model_number = inputIntGreaterThan("Model Number: ", 0, "Model numbers must be positive!");
	}

	double model_cost;

	view.listRobotParts(PartType::HEAD, ""); // Choose head
	int head_choice = inputIntInRange("Head choice: ", 0, heads_x.size(), "Invalid head choice!");

	view.listRobotParts(PartType::LOCOMOTOR, ""); // Choose locomotor
	int locomotor_choice = inputIntInRange("locomotor choice: ", 0, locomotors_x.size(), "Invalid locomotor choice!");

	view.listRobotParts(PartType::TORSO, ""); // Choose torsos
	int torso_choice = inputIntInRange("Torso choice: ", 0, torsos_x.size(), "Invalid torso choice!");

	view.listRobotParts(PartType::BATTERY, ""); // Choose batteries
	int battery_choice = inputIntInRange("Battery choice: ", 0, batteries_x.size(), "Invalid battery choice!");
	int num_batteries = inputIntInRange("Number of batteries: ", 1, torsos_x[torso_choice].getNumBatteries(), "Invalid number of batteries!"); // New getter for number of batteries

	view.listRobotParts(PartType::ARM, ""); // Choose arms
	int arm_choice = inputIntInRange("Arm choice: ", 0, arms_x.size(), "Invalid arm choice!");
	int num_arms = inputIntInRange("Number of arms: ", 1, 2, "Invalid number of arms!");

	model_cost = heads_x[head_choice].getPrice() + locomotors_x[locomotor_choice].getPrice() + torsos_x[torso_choice].getPrice() + batteries_x[battery_choice].getPrice()*num_batteries + arms_x[arm_choice].getPrice()*num_arms;
	double model_price = inputDoubleGreaterThan("Model Price [$]: ", model_cost, "Price must be greater than cost!"); // May run into an issue with double casting?
	shop.addRobotModel(RobotModel(model_name, model_number, model_price, heads_x[head_choice], torsos_x[torso_choice], locomotors_x[locomotor_choice], batteries_x[battery_choice], arms_x[arm_choice],num_batteries,num_arms));
}

void Controller::createRobotPart()
{
	view.listPartTypes();
	int type_int = inputIntInRange("Part Type: ", 0, 4, "Invalid part type number!");
	PartType type(type_int);

	string name = inputString("Part Name: ");
	int part_number = inputIntGreaterThan("Part Number: ", 0, "Part numbers must be positive!");

	while (!shop.isPartNumberUnique(part_number))
	{
		cout << "\t***Error: That part number is already taken! Try again!\n";
		part_number = inputIntGreaterThan("Part Number: ", 0, "Part numbers must be positive!");
	}

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

	view.listSalesAssociates(shop.getSalesAssociates(), "");
	int sales_associate_index = inputIntInRange("Sales Associate Index: ", 0, associates.size() - 1, "Invalid Sales Associate Index!");

	view.listCustomers(shop.getCustomers(), "");
	int customer_index = inputIntInRange("Customer Index: ", 0, customers.size() - 1, "Invalid Customer Index!");

	int order_number = inputIntGreaterThan("Order Number: ", 0, "Order Number must be positive!");

	while (!shop.isOrderNumberUnique(order_number))
	{
		cout << "\t***Error: That order number is already taken! Try again!\n";
		order_number = inputIntGreaterThan("Order Number: ", 0, "Order Number must be positive!");
	}
	
	vector<RobotModel> order_models;
	int add_another_model = 1;
	while (add_another_model)
	{
		view.listRobotModels(shop.getModels(), "");
		int model_index = inputIntInRange("Desired Robot Model Index: ", 0, models.size() - 1, "Invalid Robot Model Index!");
		RobotModel current_model = models[model_index];
		order_models.push_back(current_model);
		add_another_model = inputIntInRange("Add another model for this order? [0 = No, 1 = Yes]: ", 0, 1, "Answer must be 0 or 1!");
	}
	
	double order_price = Order::calculatePrice(order_models);
	int customer_num = customers[customer_index].getCustomerNumber();
	int sales_Associate_number = associates[sales_associate_index].getSalesAssociateNumber();
	shop.addOrder(Order(order_number, customer_num, sales_Associate_number, models, order_price, order_date), sales_Associate_number, customer_num);
	
}

void Controller::createCustomer()
{
	string name = inputString("Customer Name: ");
	int customer_number = inputIntGreaterThan("Customer Number: ", 0, "Customer number must be positive!");

	while (!shop.isCustomerNumberUnique(customer_number))
	{
		cout << "\t***Error: That customer number is already taken! Try again!\n";
		customer_number = inputIntGreaterThan("Customer Number: ", 0, "Customer number must be positive!");
	}

	shop.addCustomer(Customer(name, customer_number));
}

void Controller::createSalesAssociate()
{
	string name = inputString("Sales Associate Name: ");
	int sa_number = inputIntGreaterThan("Sales Associate Number: ", 0, "Customer number must be positive!");

	while (!shop.isSANumberUnique(sa_number))
	{
		cout << "\t***Error: That sales associate number is already taken! Try again!\n";
		sa_number = inputIntGreaterThan("Sales Associate Number: ", 0, "Customer number must be positive!");
	}

	shop.addSalesAssociate(SalesAssociate(name, sa_number));
}

//REPORT FUNCTIONS

void Controller::reportRobotModels(vector<RobotModel> models, string offset)
{
	int model_choice = 0;
	while (model_choice != -1)
	{
		view.listRobotModels(models, offset);
		if (models.size() == 0) { break; }
		model_choice = inputIntInRange(offset + "\tEnter robot model index to view details [-1 to exit]: ", -1, models.size() - 1, "Invalid robot model index!");
		if (model_choice != -1)
		{
			cout << offset + "\t" << models[model_choice].outputFormattedString(offset + "\t\t", 1);
		}
	}
}

void Controller::reportOrders(vector<Order> orders, string offset)
{
	int order_choice = 0;
	while (order_choice != -1)
	{
		view.listOrders(orders, offset);
		if (orders.size() == 0) { break; }
		order_choice = inputIntInRange("\n" + offset + "\tEnter order index to view details [-1 to exit]: ", -1, orders.size() - 1, "Invalid order index!");
		if (order_choice != -1)
		{
			cout << endl << offset + "\t" << orders[order_choice].outputFormattedString(offset + "\t\t", 1);
			reportRobotModels(orders[order_choice].getRobotModels(), offset + "\t\t");
		}
	}
}

void Controller::reportCustomers(vector<Customer> customers)
{
	int customer_choice = 0;
	while (customer_choice != -1)
	{
		view.listCustomers(customers, "");
		if (customers.size() == 0) { break; }
		customer_choice = inputIntInRange("\tEnter customer index to view details [-1 to exit]: ", -1, customers.size() - 1, "Invalid customer index!");
		if (customer_choice != -1)
		{
			cout << endl << "\t" << customers[customer_choice].outputFormattedString();
			reportOrders(customers[customer_choice].getOrders(), "\t\t");
		}
	}
}

void Controller::reportSalesAssociates(vector<SalesAssociate> sales_associates)
{
	int sa_choice = 0;
	while (sa_choice != -1)
	{
		view.listSalesAssociates(sales_associates, "");
		if (sales_associates.size() == 0) { break; }
		sa_choice = inputIntInRange("\tEnter customer index to view details [-1 to exit]: ", -1, sales_associates.size() - 1, "Invalid customer index!");
		if (sa_choice != -1)
		{
			cout << endl << "\t" << sales_associates[sa_choice].outputFormattedString() << endl;
			reportOrders(sales_associates[sa_choice].getOrders(), "\t\t");
		}
	}
}