#ifndef CONTROLLER_H
#define CONTROLLER_H 2016

#ifdef _WIN32
#define WIN32
#endif

#define HEIGHT 480
#define WIDTH 640
#define BORDER 10
#define MENUHEIGHT 30

#include "shop.h"
#include "view.h"
#include "subwindows.h"

#include "subw_create_model.h"

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

	void createPart();

	/* OLD STUFF
	void executeMainMenuCommand(int command);
	void executeCreateMenuCommand(int command);
	void executeReportMenuCommand(int command);
	void executeLoadSaveMenuCommand(int command);

	void createRobotModel();
	void createOrder();
	void createCustomer();
	void createSalesAssociate();

	void reportRobotModels(std::vector<RobotModel> models, std::string offset);
	void reportOrders(std::vector<Order> orders, std::string offset);
	void reportCustomers(std::vector<Customer> customers);
	void reportSalesAssociates(std::vector<SalesAssociate> sales_associates);
	*/
private:
	Shop& shop;
	View view;

	//
	//WIDGETS
	//
	std::vector<Fl_Window*> subwindows;
	CreatePartSubWindow* create_part_sw;


	CreateModelSubWindow* create_model_sw;
	//
	//Callbacks
	//
	static void s_displayCreatePartSubWindow_CB(Fl_Widget* w, void* p);
	void displayCreatePartSubWindow_CB();
	static void createPart_CB(Fl_Widget* w, void* p);


	static void s_displayCreateModelSubWindow_CB(Fl_Widget* w, void* p);
	void displayCreateModelSubWindow_CB();	
	static void createModel_CB(Fl_Widget* w, void* p);
	//HELPER FUNCTIONS
	void hideAllSubWindows();
};

#endif
