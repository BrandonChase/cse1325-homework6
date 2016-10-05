#ifndef VIEW_H
#define VIEW_H 2016

#include "shop.h"

class View 
{
public:
	View(Shop& param_shop) : shop(param_shop) {};

private:
	Shop& shop;
};

#endif
