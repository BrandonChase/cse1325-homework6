#ifndef CONTROLLER_H
#define CONTROLLER_H 2016

#ifdef _WIN32
#define WIN32
#endif

#include "shop.h"
#include "view.h"
#include "subw_create_part.h"
#include "subw_create_customer_sa.h"
#include "subw_report_all_parts.h"
#include "subw_create_model.h"
#include "subw_create_order.h"
#include "subw_report_sa.h"
#include "subw_report_customer.h"
#include "subw_report_models.h"
#include "subw_report_orders.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>

class FLTKController
{
public:
	FLTKController(Shop& p_shop) : shop(p_shop), view(View(p_shop)) {};

	int GUI();

private:
	Shop& shop;
	View view;

	//
	//WIDGETS
	//

	std::vector<Fl_Window*> subwindows;
	CreatePartSubWindow* create_part_sw;
	CreateCustomerSubWindow* create_customer_sw;
	CreateSASubWindow* create_sa_sw;
	CreateModelSubWindow* create_model_sw;
	CreateOrderSubWindow* create_order_sw;
	ReportPartsSubWindow* report_parts_sw;
	ReportSASubWindow* report_sa_sw;
	ReportCustomerSubWindow* report_customer_sw;
	ReportModelSubWindow* report_model_sw;
	ReportOrderSubWindow* report_order_sw;

	//
	//Callbacks
	//

	static void s_displayCreatePartSubWindow_CB(Fl_Widget* w, void* p);
	void displayCreatePartSubWindow_CB();

	static void s_displayCreateCustomerSubWindow_CB(Fl_Widget* w, void* p);
	void displayCreateCustomerSubWindow_CB();

	static void s_displayCreateSASubWindow_CB(Fl_Widget* w, void* p);
	void displayCreateSASubWindow_CB();

	static void s_displayCreateModelSubWindow_CB(Fl_Widget* w, void* p);
	void displayCreateModelSubWindow_CB();

	static void s_displayCreateOrderSubWindow_CB(Fl_Widget* w, void* p);
	void displayCreateOrderSubWindow_CB();

	static void s_displayReportPartsSubWindow_CB(Fl_Widget* w, void* p);
	void displayReportPartsSubWindow_CB();

	static void s_displayReportSASubWindow_CB(Fl_Widget* w, void* p);
	void displayReportSASubWindow_CB();

	static void s_displayReportCustomerSubWindow_CB(Fl_Widget* w, void* p);
	void displayReportCustomerSubWindow_CB();

	static void s_displayReportModelsSubWindow_CB(Fl_Widget* w, void* p);
	void displayReportModelsSubWindow_CB();

	static void s_displayReportOrderSubWindow_CB(Fl_Widget* w, void* p);
	void displayReportOrderSubWindow_CB();

	static void s_populateShop_CB(Fl_Widget*, void* p);
	void populateShop_CB();

	//HELPER FUNCTIONS
	void hideAllSubWindows();
};

#endif
