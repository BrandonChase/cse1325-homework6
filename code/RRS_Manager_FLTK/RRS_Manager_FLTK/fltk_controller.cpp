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
#include "window_properties.h"
#include "subw_create_part.h"
#include "subw_create_customer_sa.h"

using namespace std;

int FLTKController::GUI()
{
	fl_register_images();

	//Initialize Subwindows
	create_part_sw = new CreatePartSubWindow(shop);
	subwindows.push_back(create_part_sw);

	create_customer_sw = new CreateCustomerSubWindow(shop);
	subwindows.push_back(create_customer_sw);

	create_sa_sw = new CreateSASubWindow(shop);
	subwindows.push_back(create_sa_sw);

	report_parts_sw = new ReportPartsSubWindow(shop);
	subwindows.push_back(report_parts_sw);
	
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
			{"Robot Parts", 0, 0, 0},
			{0},
		{"&Help", 0, 0, 0, FL_SUBMENU },
			{"&Manual", 0, 0, 0},
			{"&About", 0, 0, 0},
			{"Populate Shop", 0, 0, 0},
			{0},
		{0}
	};

	//Manual Menu Callbacks
	menuitems[18].callback(s_displayCreatePartSubWindow_CB, this);
	menuitems[16].callback(s_displayCreateCustomerSubWindow_CB, this);
	menuitems[17].callback(s_displayCreateSASubWindow_CB, this);
	menuitems[34].callback(s_populateShop_CB, this);
	menuitems[29].callback(s_displayReportPartsSubWindow_CB, this);

	Fl_Window* win = new Fl_Window{WIDTH+3*BORDER, HEIGHT+3*BORDER, "Robbie Robot Shop v0.15"};
	Fl_Menu_Bar *menubar;

	menubar = new Fl_Menu_Bar(0,0,WIDTH+3*BORDER, MENUHEIGHT);
	menubar->menu(menuitems);

	//SUBWINDOW SETUP
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

void FLTKController::s_displayCreateCustomerSubWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayCreateCustomerSubWindow_CB();
}

void FLTKController::displayCreateCustomerSubWindow_CB()
{
	hideAllSubWindows();
	create_customer_sw->show();
}

void FLTKController::s_displayCreateSASubWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayCreateSASubWindow_CB();
}

void FLTKController::displayCreateSASubWindow_CB()
{
	hideAllSubWindows();
	create_sa_sw->show();
}

void FLTKController::s_populateShop_CB(Fl_Widget*, void* p)
{
	((FLTKController*)p)->populateShop_CB();
}

void FLTKController::populateShop_CB()
{
	shop.populateShopForTesting();
}

void FLTKController::s_displayReportPartsSubWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayReportPartsSubWindow_CB();
}
void FLTKController::displayReportPartsSubWindow_CB()
{
	hideAllSubWindows();
	report_parts_sw->show();
}