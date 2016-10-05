#ifndef CONTROLLER_H
#define CONTROLLER_H 2016

#include "shop.h"
#include "view.h"

class Controller
{
public:
	Controller(Shop& param_shop) : shop(param_shop), view(View(param_shop)) {};
	void cli();
	void executeCommand(int command);
	
private:
	Shop& shop;
	View view;
};

#endif
