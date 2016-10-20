#ifndef CONTROLLER_H
#define CONTROLLER_H 2016

#include "shop.h"
#include "view.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

class Controller
{
public:
	Controller(Shop& p_shop) : shop(p_shop), view(View(p_shop)) {};

	void CLI();
	void mainMenuCLI();
	void createCLI();
	void reportCLI();
	void loadsaveCLI();

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
