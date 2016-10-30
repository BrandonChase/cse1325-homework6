#ifndef TESTER_H
#define TESTER_H 2016

#include "shop.h"
#include "view.h"

class Tester
{
public:
	Tester(Shop p_shop) : shop(p_shop), view(View(p_shop)) {}
	Shop shop;
	View view;

	void testOutputingRobotParts();
	void testOutputingRobotModels();
	void testFileSavingLoading();
};

#endif