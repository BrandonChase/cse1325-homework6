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
#include <FL/Fl_JPEG_Image.H>

class FLTKController
{
public:
	FLTKController(Shop& p_shop) : shop(p_shop), view(View(p_shop)) {};

	int GUI();


	void executeMainMenuCommand(int command);
	void executeCreateMenuCommand(int command);
	void executeReportMenuCommand(int command);
	void executeLoadSaveMenuCommand(int command);

	void createRobotModel();
	void createRobotPart();
	void createOrder();
	void createCustomer();
	void createSalesAssociate();

	void reportRobotModels(std::vector<RobotModel> models, std::string offset);
	void reportOrders(std::vector<Order> orders, std::string offset);
	void reportCustomers(std::vector<Customer> customers);
	void reportSalesAssociates(std::vector<SalesAssociate> sales_associates);

private:
	Shop& shop;
	View view;
};

#endif
