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
	void listRobotParts(int selection, std::string offset);
	void listRobotModels(const std::vector<RobotModel>& models, std::string offset);
	void listSalesAssociates(const std::vector<SalesAssociate>& sales_associates, std::string offset);
	void listCustomers(const std::vector<Customer>& customers, std::string offset);
	void listOrders(const std::vector<Order>& orders, std::string offset);

private:
	Shop& shop;
};

#endif
