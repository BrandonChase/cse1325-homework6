#include "view.h"
#include "part_type.h"
#include "robot_parts.h"
#include <iostream>

using namespace std;

//SHOWS

void View::showWelcome()
{
	cout
	<< "===================================" << endl
	<< "      Robbie Robot Shop v0.10      " << endl
	<< "                                   " << endl
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
	<< "--------------" << endl
	<< "| Main Menu  |" << endl
	<< "--------------" << endl
	<< "| (1) Create |" << endl
	<< "| (2) Report |" << endl
	<< "| (3) Save   |" << endl
	<< "| (9) Quit   |" << endl 
	<< "--------------" << endl 
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

void View::showSaveMenu() //I don't know if this will be necessary (or at least not a menu)
{
	cout
	<< endl 
	<<"-----------------------------" << endl
	<<"|          Saving           |" << endl
	<<"-----------------------------" << endl
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

void View::listRobotParts(int selection) // selection allows a specific part type to be outputted, {0...4} = {Head...Arms}, -1 = All
{
	const vector<Head>& heads_ref = shop.getHeads();
	const vector<Locomotor>& locomotors_ref = shop.getLocomotors();
	const vector<Torso>& torsos_ref = shop.getTorsos();
	const vector<Battery>& batteries_ref = shop.getBatteries();
	const vector<Arm>& arms_ref = shop.getArms();

	cout
	<< endl
	<< "Robot Parts" << endl
	<< "-----------" << endl;

	if (selection == 0 || selection == -1)
	{
	//list heads
		cout
		<< endl
		<< "Heads" << endl
		<< "-----" << endl
		<< endl;

		for (int i = 0; i < heads_ref.size(); i++)
		{
			cout
			<< "(" << i << ") " << heads_ref[i] << endl;
		}
	}
	//list locomotors
	cout
	<< endl
	<< "Locomotors" << endl
	<< "----------" << endl
	<< endl;
	if (selection == 1 || selection == -1)
	{
		for (int i = 0; i < locomotors_ref.size(); i++)
		{
			cout
			<< "(" << i << ") " << locomotors_ref[i] << endl;
		}
	}
	if (selection == 2 || selection == -1)
	{
	//list torsos
		cout
		<< endl
		<< "Torsos" << endl
		<< "------" << endl
		<< endl;

		for (int i = 0; i < torsos_ref.size(); i++)
		{
			cout
			<< "(" << i << ") " << torsos_ref[i] << endl;
		}
	}
	if (selection == 3 || selection == -1)
	{
	//list batteries
		cout
		<< endl
		<< "Batteries" << endl
		<< "---------" << endl
		<< endl;

		for (int i = 0; i < batteries_ref.size(); i++)
		{
			cout
			<< "(" << i << ") " << batteries_ref[i] << endl;
		}
	}
	if (selection == 4 || selection == -1)
	{
	//list arms
		cout
		<< endl
		<< "Arms" << endl
		<< "----" << endl
		<< endl;

		for (int i = 0; i < arms_ref.size(); i++)
		{
			cout
			<< "(" << i << ") " << arms_ref[i] << endl;
		}

		cout << endl;
	}
}

/*

void View::ListRobotModels()
{
	const vector<RobotModel>& models_ref = shop.getModels();
}



*/