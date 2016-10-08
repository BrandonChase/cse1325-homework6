#include "view.h"
#include <iostream>

using namespace std;

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