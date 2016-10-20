#include "view.h"
#include "part_type.h"
#include "robot_parts.h"
#include "sales_associate.h"

#include <iostream>

using namespace std;

//SHOWS

void View::showWelcome()
{
	cout
	<< "===================================" << endl
	<< "      Robbie Robot Shop v0.13      " << endl
	<< "            Secret: 9999           " << endl
	<< "Creators: Brandon Chase & Joe Cloud" << endl
	<< "===================================" << endl
	<< endl
	<< endl
	<< endl;
}

void View::showMainMenu()
{
	cout
	<< endl
	<< "-------------------------" << endl
	<< "|        Main Menu      |" << endl
	<< "-------------------------" << endl
	<< "| (1) Create            |" << endl
	<< "| (2) Report            |" << endl
	<< "| (3) Load/Save         |" << endl
	<< "| (9) Quit              |" << endl 
	<< "-------------------------" << endl 
	<< endl;
}

void View::showCreateMenu()
{
	cout
	<< endl
	<< "-------------------------" << endl
	<< "|        Create         |" << endl
	<< "-------------------------" << endl
	<< "| (1) Order             |" << endl
	<< "| (2) Customer          |" << endl
	<< "| (3) Sales Associate   |" << endl
	<< "| (4) Robot Model       |" << endl
	<< "| (5) Robot Part        |" << endl
	<< "| (9) Quit to Main Menu |" << endl
	<< "-------------------------" << endl
	<< endl;
}

void View::showReportMenu()
{
	cout
	<< endl
	<< "-------------------------" << endl
	<< "|        Report         |" << endl
	<< "-------------------------" << endl
	<< "| (1) Orders            |" << endl
	<< "| (2) Customers         |" << endl
	<< "| (3) Sales Associates  |" << endl
	<< "| (4) Robot Models      |" << endl
	<< "| (5) Robot Parts       |" << endl
	<< "| (9) Quit to Main Menu |" << endl
	<< "-------------------------" << endl
	<< endl;
}

void View::showLoadSaveMenu() //I don't know if this will be necessary (or at least not a menu) -- now it is.
{
	cout
	<< endl 
	<<"--------------------------" << endl
	<<"|       Load/Save        |" << endl
	<<"--------------------------" << endl
	<<"| (1) Load a session     |" << endl
	<<"| (2) Save a session     |" << endl
	<<"| (9) Quit to Main Menu  |" << endl
	<< "-------------------------" << endl
	<< endl;
}

//LISTS

void View::listPartTypes()
{
	cout
	<< endl
	<< "Robot Part Types" << endl
	<< "----------------" << endl;

	for (int i = 0; i < PartType::NUM_OF_PART_TYPES; i++)
	{
		cout << "(" << i << ") " << PartType(i) << endl;
	}

	cout << endl;
}

void View::listRobotParts(int selection, std::string offset) // selection allows a specific part type to be outputted, {0...4} = {Head...Arms}, -1 = All
{
	if (shop.areAllPartListsEmpty())
	{
		cout << offset << "\t***There are no robot parts in the shop.\n";
		return;
	}

	const vector<Head>& heads_ref = shop.getHeads();
	const vector<Locomotor>& locomotors_ref = shop.getLocomotors();
	const vector<Torso>& torsos_ref = shop.getTorsos();
	const vector<Battery>& batteries_ref = shop.getBatteries();
	const vector<Arm>& arms_ref = shop.getArms();
	
	if (selection == PartType::ALL)
	{
		cout
			<< endl
			<< offset << "Robot Parts" << endl
			<< offset << "-----------" << endl;
	}

	if ((selection == PartType::HEAD || selection == PartType::ALL) & heads_ref.size() != 0)
	{
		//list heads
		cout
			<< offset << "\tHeads" << endl
			<< offset << "\t-----" << endl;

		for (int i = 0; i < heads_ref.size(); i++)
		{
			cout
				<< offset << "\t\t(" << i << ") " << heads_ref[i].outputFormattedString("\t\t", 1) << endl;
		}
	}

	if ((selection == PartType::TORSO || selection == PartType::ALL) & torsos_ref.size() != 0)
	{
	//list torsos
		cout
			<< offset << "\tTorsos" << endl
			<< offset << "\t------" << endl;

		for (int i = 0; i < torsos_ref.size(); i++)
		{
			cout
			<< offset << "\t\t(" << i << ") " << torsos_ref[i].outputFormattedString("\t\t", 1) << endl;
		}
	}

	if ((selection == PartType::BATTERY || selection == PartType::ALL) & batteries_ref.size() != 0)
	{
		//list batteries
		cout
			<< offset << "\tBatteries" << endl
			<< offset << "\t---------" << endl;

		for (int i = 0; i < batteries_ref.size(); i++)
		{
			cout
				<< offset << "\t\t(" << i << ") " << batteries_ref[i].outputFormattedString("\t\t", 1) << endl;
		}
	}

	if ((selection == PartType::ARM || selection == PartType::ALL) & arms_ref.size() != 0)
	{
	//list arms
		cout
			<< offset << "\tArms" << endl
			<< offset << "\t----" << endl;

		for (int i = 0; i < arms_ref.size(); i++)
		{
			cout
			<< offset << "\t\t(" << i << ") " << arms_ref[i].outputFormattedString("\t\t", 1) << endl;
		}
	}

	if ((selection == PartType::LOCOMOTOR || selection == PartType::ALL) & locomotors_ref.size() != 0)
	{

	//list locomotors
		cout
		<< offset << "\tLocomotors" << endl
		<< offset << "\t----------" << endl
		<< endl;

		for (int i = 0; i < locomotors_ref.size(); i++)
		{
			cout
			<< offset << "\t\t(" << i << ") " << locomotors_ref[i].outputFormattedString("\t\t", 1) << endl;
		}
	}
}

void View::listRobotModels(const vector<RobotModel>& models, std::string offset)
{
	if (models.size() == 0)
	{
		cout << offset << "\t***There are no robot models to report.\n";
		return;
	}

	cout
		<< endl
		<< offset << "Robot Models" << endl
		<< offset << "------------" << endl;

	for (int i = 0; i < models.size(); i++)
	{
		cout << offset << "\t(" << i << ") " << models[i].outputFormattedString("\t\t", 0) << endl;
	}
}

void View::listSalesAssociates(const std::vector<SalesAssociate>& sales_associates, std::string offset)
{
	if (sales_associates.size() == 0)
	{
		cout << offset << "\t***There are no sales associates to report.\n";
		return;
	}

	cout
		<< offset << "Sales Associates" << endl
		<< offset << "----------------" << endl;

	for (int i = 0; i < sales_associates.size(); i++)
	{
		cout << offset << "\t(" << i << ") " << sales_associates[i].outputFormattedString() << endl;
	}
}

void View::listCustomers(const std::vector<Customer>& customers, std::string offset)
{
	if (customers.size() == 0)
	{
		cout << offset << "\t***There are no customers to report.\n";
		return;
	}

	cout
		<< offset << "Customers" << endl
		<< offset << "---------" << endl;

	for (int i = 0; i < customers.size(); i++)
	{
		cout << offset << "\t(" << i << ") " << customers[i].outputFormattedString() << endl;
	}
}

void View::listOrders(const vector<Order>& orders, std::string offset)
{
	if (orders.size() == 0)
	{
		cout << offset << "\t***There are no orders to report.\n";
		return;
	}

	cout
		<< offset << "Orders" << endl
		<< offset << "------" << endl;

	for (int i = 0; i < orders.size(); i++)
	{
		cout << offset << "\t(" << i << ") " << orders[i].outputFormattedString("",0) << endl;
	}
}
