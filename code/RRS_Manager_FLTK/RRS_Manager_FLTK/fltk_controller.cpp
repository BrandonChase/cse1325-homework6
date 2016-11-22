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
	{
		create_part_sw = new CreatePartSubWindow(shop);
		subwindows.push_back(create_part_sw);

		create_model_sw = new CreateModelSubWindow(shop);  // JC
		subwindows.push_back(create_model_sw);

		create_customer_sw = new CreateCustomerSubWindow(shop);
		subwindows.push_back(create_customer_sw);

		create_sa_sw = new CreateSASubWindow(shop);
		subwindows.push_back(create_sa_sw);

		create_order_sw = new CreateOrderSubWindow(shop);
		subwindows.push_back(create_order_sw);

		report_parts_sw = new ReportPartsSubWindow(shop);
		subwindows.push_back(report_parts_sw);

		report_sa_sw = new ReportSASubWindow(shop);
		subwindows.push_back(report_sa_sw);

		report_customer_sw = new ReportCustomerSubWindow(shop);
		subwindows.push_back(report_customer_sw);

		report_model_sw = new ReportModelSubWindow(shop);
		subwindows.push_back(report_model_sw);

		report_order_sw = new ReportOrderSubWindow(shop);
		subwindows.push_back(report_order_sw);
	}

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
		{"&Create", 0, 0, 0, FL_SUBMENU },
			{"Order", 0, 0, 0},
			{"Customer", 0, 0, 0},
			{"Sales Associate", 0, 0, 0},
			{"Robot Part", 0, 0, 0},
			{"Robot Model", 0, 0, 0},
			{0},
		{"&Report", 0, 0, 0, FL_SUBMENU },
			{"Orders", 0, 0, 0},
			{"Customers", 0, 0, 0},
			{"Sales Associates", 0, 0, 0},
			{"Robot Models", 0, 0, 0},
			{"Robot Parts", 0, 0, 0},
			{0},
		{"&Help", 0, 0, 0, FL_SUBMENU },
			{"&Manual", 0, 0, 0},
			{"Populate Shop", 0, 0, 0},
			{0},
		{0}
	};

	//Manual Menu Callbacks
	{
		menuitems[01].callback(s_resetShop_CB, this);
		menuitems[02].callback(s_displayFileOpenWindow_CB, this);
		menuitems[03].callback(s_displayFileSaveWindow_CB, this);
		menuitems[04].callback(s_displayFileSaveAsWindow_CB, this);
		menuitems[05].callback(s_quit_CB, this);
		menuitems[8].callback(s_displayCreateOrderSubWindow_CB, this); //Create Part
		menuitems[9].callback(s_displayCreateCustomerSubWindow_CB, this); //Create Customer
		menuitems[10].callback(s_displayCreateSASubWindow_CB, this); //Create Sales Assoc
		menuitems[11].callback(s_displayCreatePartSubWindow_CB, this); //Create Part
		menuitems[12].callback(s_displayCreateModelSubWindow_CB, this); //Create Model
		menuitems[15].callback(s_displayReportOrderSubWindow_CB, this); //Report Order
		menuitems[16].callback(s_displayReportCustomerSubWindow_CB, this); //Report Customer
		menuitems[17].callback(s_displayReportSASubWindow_CB, this); //Report SA
		menuitems[18].callback(s_displayReportModelsSubWindow_CB, this); //Report Models
		menuitems[19].callback(s_displayReportPartsSubWindow_CB, this); //Report Parts
		menuitems[23].callback(s_populateShop_CB, this); //Populate Shop
	}

	win = new Fl_Window{WIDTH+3*BORDER, HEIGHT+3*BORDER, "Robbie Robot Shop v0.69"};
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
	create_part_sw->reset();
	report_parts_sw->reset();
	create_customer_sw->reset();
	create_sa_sw->reset();
	create_order_sw->reset();
	report_customer_sw->reset();
	report_model_sw->reset();
	report_order_sw->reset();
	report_sa_sw->reset();
	shop.isDirty = false;
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
			shop.isDirty = false;
		}
	}
	catch(...)
	{
		cerr << "Load was unsuccessful\n";
	}
}

void FLTKController::s_displayCreateOrderSubWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayCreateOrderSubWindow_CB();

}
void FLTKController::displayCreateOrderSubWindow_CB()
{
	hideAllSubWindows();
	create_order_sw->initializeDropDowns();
	create_order_sw->show();
}

void FLTKController::s_displayReportSASubWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayReportSASubWindow_CB();
}

void FLTKController::displayReportSASubWindow_CB()
{
	hideAllSubWindows();
	report_sa_sw->initiliazeSADropDrown();
	report_sa_sw->show();
}

void FLTKController::s_displayReportCustomerSubWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayReportCustomerSubWindow_CB();
}

void FLTKController::displayReportCustomerSubWindow_CB()
{
	hideAllSubWindows();
	report_customer_sw->initiliazeCustomerDropDrown();
	report_customer_sw->show();
}

void FLTKController::s_displayReportModelsSubWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayReportModelsSubWindow_CB();
}

void FLTKController::displayReportModelsSubWindow_CB()
{
	hideAllSubWindows();
	report_model_sw->initiliazeModelDropDrown();
	report_model_sw->show();
}

void FLTKController::s_displayReportOrderSubWindow_CB(Fl_Widget* w, void* p)
{
	((FLTKController*)p)->displayReportOrderSubWindow_CB();
}

void FLTKController::displayReportOrderSubWindow_CB()
{
	hideAllSubWindows();
	report_order_sw->initiliazeOrderDropDrown();
	report_order_sw->show();
}

void FLTKController::s_quit_CB(Fl_Widget*, void* p)
{
	((FLTKController*)p)->quit_CB();
}

void FLTKController::quit_CB()
{
	if (shop.isDirty)
	{
		if (fl_ask("There is unsaved data. Are you sure you want to quit?"))
		{
			hideAllSubWindows();
			win->hide();
		}
	}

	else
	{
		hideAllSubWindows();
		win->hide();
	}
}