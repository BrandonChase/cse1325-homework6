/* 
know something like this will be needed // can be modified/deleted as needed 

wondering best method for inputing menu? number or text?
also need to figure out menu process- text is really just placeholder

FOR SPRINT 1: 
Menu is needed for creating parts, then creating robot models.

*/ 

#include <cstdio>
#include <iostream>

using namespace std;

void welcome()
{
	cout 
	<<
	"--------------------------------------------------\n"
	<<
	"|        welcome to robbie robot shop 1.0        |\n"
	<<
	"--------------------------------------------------\n"
	<<
	"|     written by: brandon chase // joe cloud     |\n"
	<<
	"--------------------------------------------------\n"
	<<
	"--------------------------------------------------\n";


}

void mainf()
{
	cout 
	<<"\n"<<
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

void create()
{
	cout 
	<<"\n"<<
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

void report()
{
	cout 
	<<"\n"<<
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

void save()
{
cout 
	<<"\n"<<
	"--------------------------------------------------\n"
	<<
	"|                 saving progress                |\n"
	<<
	"--------------------------------------------------\n";
}

int notmain()
{
/* function used for testing print format */
	welcome();
	mainf();
	create();
	report();
	save();
	char c;
	cin >> c;
	return 0;
}
