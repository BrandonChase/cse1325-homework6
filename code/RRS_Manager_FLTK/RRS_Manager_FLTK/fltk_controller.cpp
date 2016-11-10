#include "fltk_controller.h"

#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Button.H>

#include <iostream>

#include "shop.h"
#include "view.h"
#include "easy_input.h"
#include "subwindows.h"
using namespace std;

int FLTKController::GUI()
{
	fl_register_images();

	//Create Part Subwindow
	create_part_sw = new CreatePartSubWindow();
	create_part_sw->create_button()->callback(createPart_CB);
	subwindows.push_back(create_part_sw);
	
	//
	//MENU
	//
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
			{"Robot Part", 0, 0},
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

	//Manual Menu Callbacks
	menuitems[18].callback(displayCreatePartSubWindow_CB, this);

	Fl_Window* win = new Fl_Window{WIDTH+3*BORDER, HEIGHT+3*BORDER, "Robbie Robot Shop v0.15"};
	Fl_Box *box = new Fl_Box{BORDER, BORDER, WIDTH+BORDER, HEIGHT+BORDER};
	Fl_Menu_Bar *menubar;

	menubar = new Fl_Menu_Bar(0,0,WIDTH+3*BORDER, MENUHEIGHT);
	menubar->menu(menuitems);

	//Add all subwindows
	for (Fl_Window* subwindow : subwindows)
	{
		win->add(subwindow);
	}
	hideAllSubWindows();

	win->end();
	win->show();

	return(Fl::run());
}

//HELPER FUNCTIONS
void FLTKController::hideAllSubWindows()
{
	for (Fl_Window* subwindow : subwindows)
	{
		subwindow->hide();
	}
}

//Menu Callbacks
void FLTKController::displayCreatePartSubWindow_CB(Fl_Widget* w, void* p)
{
	//Hide other subwindows
	((FLTKController*)p)->displayCreatePartWindow();
}

void FLTKController::displayCreatePartWindow()
{
	hideAllSubWindows();
	create_part_sw->show();
}

//Subwindow return button callbacks
void FLTKController::createPart_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->createPart();
}

void FLTKController::createPart()
{
	//check all required fields valid ~ will be function in subwindow
	PartType part_type(create_part_sw->partType());

	string name = create_part_sw->name();
	int part_number = create_part_sw->partNumber();

	if (part_number < 0)
	{
		Fl::error("Part number must be positive!");
		return;
	}

	if (!shop.isPartNumberUnique(part_number))
	{
		Fl::error("That part number is already taken! Try again!");
		return;
	}

	double weight = create_part_sw->weight();
	if (weight <= 0)
	{
		Fl::error("Part weight must be positive!");
		return;
	}

	double price = create_part_sw->price();
	if (price <= 0)
	{
		Fl::error("Part weight must be positive!");
		return;
	}

	string image_filename = create_part_sw->imageFileName();

	string description = create_part_sw->description();

	if (part_type == PartType::HEAD)
	{
		shop.addHead(Head(name, part_number, weight, price, part_type, description, image_filename));
	}

	else if (part_type == PartType::TORSO)
	{
		int battery_compartments = create_part_sw->batteryCompartments();
		if (battery_compartments < 1 || battery_compartments > 3)
		{
			Fl::error("Torsos can only have 1, 2, or 3 battery compartments!");
			return;
		}
		shop.addTorso(Torso(name, part_number, weight, price, part_type, description, battery_compartments, image_filename));
	}

	else if (part_type == PartType::BATTERY)
	{
		double contained_energy = create_part_sw->containedEnergy();
		if (contained_energy <= 0)
		{
			Fl::error("Energy contained must be positive!");
			return;
		}
		shop.addBattery(Battery(name, part_number, weight, price, part_type, description, contained_energy, image_filename));
	}

	else if (part_type == PartType::ARM)
	{
		double power_consumed = create_part_sw->powerConsumed();
		if (power_consumed <= 0)
		{
			Fl::error("Power consumed must be positive!");
			return;
		}
		shop.addArm(Arm(name, part_number, weight, price, part_type, description, power_consumed,  image_filename));
	}

	else if (part_type == PartType::LOCOMOTOR) 
	{
		double max_speed = create_part_sw->maxSpeed();
		if (max_speed <= 0)
		{
			Fl::error("Max speed must be positive!");
			return;
		}

		double power_consumed = create_part_sw->powerConsumed();
		if (power_consumed <= 0)
		{
			Fl::error("Power consumed must be positive!");
			return;
		}
		
		shop.addLocomotor(Locomotor(name, part_number, weight, price, part_type, description, max_speed, power_consumed, image_filename));
	}

	else //Unkown
	{
		Fl::error("Unknown Part Type. This shouldn't be possible. ABORT NOW WHILE YOU STILL CAN!");
	}

	//reset feild values for subwindow
	create_part_sw->hide();
}