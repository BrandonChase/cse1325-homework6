#ifndef CONTROLLER_H
#define CONTROLLER_H 2016

#include "shop.h"
#include "view.h"

class Controller
{
public:
	Controller(Shop& p_shop) : shop(p_shop), view(View(p_shop)) {};
	void cli();
	void executeCommand(int command);
	void createmenu(int command);
	void reportmenu(int command);


		
private:
	Shop& shop;
	View view;
};

#endif
