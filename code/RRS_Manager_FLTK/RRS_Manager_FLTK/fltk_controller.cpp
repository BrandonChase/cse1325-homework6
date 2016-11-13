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
#include "subwindows.h"
#include "subw_create_model.h"
#include "window_properties.h"
using namespace std;

int FLTKController::GUI()
{
	fl_register_images();


	//Create Part Subwindow
	create_part_sw = new CreatePartSubWindow(shop);
	subwindows.push_back(create_part_sw);
	
	//Create Model Subwindow
	create_model_sw = new CreateModelSubWindow(shop);  // JC
	subwindows.push_back(create_model_sw);


	shop.addHead(Head("Destroyer Head", 111, 1, 5, PartType::HEAD, "This is destroyer head no. 1","Images/Heads/head_antennae.png"));
	shop.addHead(Head("Servant Head", 123, 2, 10, PartType::HEAD, "This is servant head no. 1","Images/Heads/head_orange.png"));
	shop.addHead(Head("War Head", 135, 4, 11, PartType::HEAD, "This is war head no. 1","Images/Heads/head_asymmetric_antenna.png"));
	shop.addTorso(Torso("Destroyer Torso", 112, 2, 6, PartType::TORSO, "This is destroyer torso no. 1", 2,"Images/Torsos/torso_button.png"));
	shop.addTorso(Torso("Servant Torso", 134, 23, 12, PartType::TORSO, "This is servant torso no. 1", 2,"Images/Torsos/torso_button.png"));
	shop.addTorso(Torso("War Torso", 54, 24, 97, PartType::TORSO, "This is war torso no. 1", 2,"Images/Torsos/torso_button.png"));
	shop.addArm(Arm("Destroyer Arm", 113, 3, 7, PartType::ARM, "This is destroyer arm no. 1", 125,"Images/Arms/arm_left_orange.png"));
	shop.addArm(Arm("Servant Arm", 153, 7, 98, PartType::ARM, "This is servant arm no. 1", 125,"Images/Arms/arm_left_orange.png"));
	shop.addArm(Arm("War Arm", 131, 10, 43, PartType::ARM, "This is war arm no. 1", 125,"Images/Arms/arm_left_orange.png"));
	shop.addBattery(Battery("Destroyer Battery", 114, 4, 8, PartType::BATTERY, "This is destroyer battery no. 1", 500,"Images/Batteries/battery_blue.png"));
	shop.addBattery(Battery("Servant Battery", 123, 8, 9, PartType::BATTERY, "This is servant battery no. 1", 500,"Images/Batteries/battery_blue.png"));
	shop.addBattery(Battery("War Battery", 321, 6, 18, PartType::BATTERY, "This is war battery no. 1", 500,"Images/Batteries/battery_blue.png"));
	shop.addLocomotor(Locomotor("Destroyer Locomotor", 423, 5, 9, PartType::LOCOMOTOR, "This is destroyer locomotor no. 1", 20, 750,"Images/Locomotors/locomotor_orange.png"));
	shop.addLocomotor(Locomotor("Servant Locomotor", 543, 2, 19, PartType::LOCOMOTOR, "This is servant locomotor no. 1", 20, 750,"Images/Locomotors/locomotor_orange.png"));
	shop.addLocomotor(Locomotor("War Locomotor", 234, 8, 91, PartType::LOCOMOTOR, "This is war locomotor no. 1", 20, 750,"Images/Locomotors/locomotor_orange.png"));
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

	//Manual Menu Callbacks


	menuitems[18].callback(s_displayCreatePartSubWindow_CB, this);
	menuitems[19].callback(s_displayCreateModelSubWindow_CB, this);


	Fl_Window* win = new Fl_Window{WIDTH+3*BORDER, HEIGHT+3*BORDER, "Robbie Robot Shop v0.16"};
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



//CREATE SUB MENU CALLBACKS:

//CREATE: PART
void FLTKController::s_displayCreatePartSubWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayCreatePartSubWindow_CB();
}

void FLTKController::displayCreatePartSubWindow_CB()
{
	hideAllSubWindows();
	create_part_sw->show();
}

//CREATE: MODEL
void FLTKController::s_displayCreateModelSubWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayCreateModelSubWindow_CB();
}

void FLTKController::displayCreateModelSubWindow_CB()
{
	hideAllSubWindows();
	create_model_sw->update_dd();
	create_model_sw->show();
}