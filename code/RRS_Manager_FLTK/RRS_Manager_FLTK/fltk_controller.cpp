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
#include "subw_create_model.h"
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
	
	create_model_sw = new CreateModelSubWindow(shop);  // JC
	subwindows.push_back(create_model_sw);

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

	menuitems[01].callback(s_resetShop_CB, this);
	menuitems[02].callback(s_displayFileOpenWindow_CB, this);
	menuitems[03].callback(s_displayFileSaveWindow_CB, this);
	menuitems[04].callback(s_displayFileSaveAsWindow_CB, this);
	menuitems[15].callback(s_displayCreateCustomerSubWindow_CB, this);
	menuitems[16].callback(s_displayCreateSASubWindow_CB, this);
	menuitems[17].callback(s_displayCreatePartSubWindow_CB, this);
	menuitems[18].callback(s_displayCreateModelSubWindow_CB, this);
	menuitems[28].callback(s_displayReportPartsSubWindow_CB, this);
	menuitems[33].callback(s_populateShop_CB, this);

	Fl_Window* win = new Fl_Window{WIDTH+3*BORDER, HEIGHT+3*BORDER, "Robbie Robot Shop v0.18"};
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

void FLTKController::s_resetShop_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->resetShop_CB();
}

void FLTKController::resetShop_CB()
{
	hideAllSubWindows();
	shop.resetShop();
	create_model_sw->reset();
	//create_model_sw->update_dd();
}

//saving loading functionality

void FLTKController::s_displayFileSaveWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayFileSaveWindow_CB();
}

void FLTKController::displayFileSaveWindow_CB() 
{
	string directory = "./Saves/";
	string extension = ".shop";
	try
	{
		if (savedfile == "")
		{
			//savedfile = fl_file_chooser("Save File As?", "*", directory.c_str());
			savedfile = fl_input("Enter filename to save to: ");
			savedfile = directory + savedfile + extension;
		}
		shop.savefile(savedfile);
	}
	catch (...)
	{
		cerr << "Save was unsuccessful\n";
	}
}



void FLTKController::s_displayFileSaveAsWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayFileSaveAsWindow_CB();
}

void FLTKController::displayFileSaveAsWindow_CB() // potential bugs - needs more testing
{
	string newfile;
	string directory = "./Saves/";
	string extension = ".shop";
	try 
	{
		newfile = fl_input("Enter filename to save to: ");
		//newfile = fl_file_chooser("Save File As?", "*", directory.c_str());
		savedfile = directory + newfile + extension;
		cerr << savedfile;
		if (newfile.c_str() != NULL) 
		{
			if (savedfile.find(".")) { extension = "";}
			shop.savefile(savedfile);
		}
	}
	catch (...)
	{
		cerr << "Save as was unsuccessful\n";
	}

}




void FLTKController::s_displayFileOpenWindow_CB(Fl_Widget* w, void* p) //seg faults - still testing
{
	((FLTKController*)p)->displayFileOpenWindow_CB();
}

void FLTKController::displayFileOpenWindow_CB() 
{
	try
	{
		char *newfile;
		string directory = "./Saves";
		newfile = fl_file_chooser("Load File?", "*.shop", directory.c_str());


		if (newfile != NULL) 
		{
			savedfile = newfile;
			resetShop_CB();
			shop.loadfile(newfile);
		}
	}
	catch(...)
	{
		cerr << "Load was unsuccessful\n";
	}
}
