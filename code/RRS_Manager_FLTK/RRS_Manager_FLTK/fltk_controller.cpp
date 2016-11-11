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
#include "window_properties.h"
using namespace std;

int FLTKController::GUI()
{
	fl_register_images();

	//Create Part Subwindow
	create_part_sw = new CreatePartSubWindow(shop);
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

	Fl_Window* win = new Fl_Window{WIDTH+3*BORDER, HEIGHT+3*BORDER, "Robbie Robot Shop v0.15"};
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
void FLTKController::s_displayCreatePartSubWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayCreatePartSubWindow_CB();
}

void FLTKController::displayCreatePartSubWindow_CB()
{
	hideAllSubWindows();
	create_part_sw->show();
}