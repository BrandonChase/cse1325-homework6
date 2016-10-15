#ifndef CONTROLLER_H
#define CONTROLLER_H 2016

#include "shop.h"
#include "view.h"

class Controller
{
public:
	Controller(Shop& p_shop) : shop(p_shop), view(View(p_shop)) {};

	void CLI();
	void mainMenuCLI();
	void createCLI();
	void reportCLI();

	void executeMainMenuCommand(int command);
	void executeCreateMenuCommand(int command);
	void executeReportMenuCommand(int command);

	void createRobotModel();
	void createRobotPart();
	void createOrder();
	void createCustomer();
	void createSalesAssociate();

		
private:
	Shop& shop;
	View view;
};

#endif
