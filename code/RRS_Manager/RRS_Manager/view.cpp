#include "view.h"
#include <iostream>

using namespace std;

void View::showWelcome()
{
	cout
		<<
		"--------------------------------------------------\n"
		<<
		"|        welcome to robbie robot shop 1.0        |\n"
		<<
		"--------------------------------------------------\n"
		<<
		"|     written by: brandon chase and joe cloud     |\n"
		<<
		"--------------------------------------------------\n"
		<<
		"--------------------------------------------------\n";
}

void View::showMainMenu()
{
	cout
		<< "\n" <<
		"--------------------------------------------------\n"
		<<
		"|                   main menu                    |\n"
		<<
		"--------------------------------------------------\n"
		<<
		"|  1. create            |  3. save               |\n"
		<<
		"|  2. report            |  4. quit               |\n"
		<<
		"--------------------------------------------------\n";
}

void View::showCreateMenu()
{
	cout
		<< "\n" <<
		"--------------------------------------------------\n"
		<<
		"|                    create                      |\n"
		<<
		"--------------------------------------------------\n"
		<<
		"|  1. order            |  4. robot model         |\n"
		<<
		"|  2. customer         |  5. robot component     |\n"
		<<
		"|  3. sales associate  |  6. back to main        |\n"
		<<
		"--------------------------------------------------\n";
}

void View::showReportMenu()
{
	cout
		<< "\n" <<
		"--------------------------------------------------\n"
		<<
		"|                    report                      |\n"
		<<
		"--------------------------------------------------\n"
		<<
		"|  1. orders           |  4. robot models        |\n"
		<<
		"|  2. customers        |  5. robot components    |\n"
		<<
		"|  3. sales associates |  6. back to main        |\n"
		<<
		"--------------------------------------------------\n";
}

void View::showSaveMenu() //I don't know if this will be necessary (or at least not a menu)
{
	cout
	<< "\n" <<
	"--------------------------------------------------\n"
	<<
	"|                 saving progress                |\n"
	<<
	"--------------------------------------------------\n";
}