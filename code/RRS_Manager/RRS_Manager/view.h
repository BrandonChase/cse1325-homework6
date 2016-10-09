#ifndef VIEW_H
#define VIEW_H 2016

#include "shop.h"

class View 
{
public:
	View(Shop& p_shop) : shop(p_shop) {};

	void showWelcome();
	void showMainMenu();
	void showCreateMenu();
	void showReportMenu();
	void showSaveMenu();

	void listPartTypes();
	void listRobotParts();

private:
	Shop& shop;
};

#endif
