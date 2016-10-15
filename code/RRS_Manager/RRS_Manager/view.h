#ifndef VIEW_H
#define VIEW_H 2016

#include "shop.h"
#include <vector>

class View 
{
public:
	View(Shop& p_shop) : shop(p_shop) {};

	void showWelcome();
	void showMainMenu();
	void showCreateMenu();
	void showReportMenu();
	void showLoadSaveMenu();

	void listPartTypes();
	void listRobotParts(int selection);
	void listRobotModels();
	void listSalesAssociates();
	void listCustomers();
	void listOrders(std::vector<Order>& orders);

private:
	Shop& shop;
};

#endif
