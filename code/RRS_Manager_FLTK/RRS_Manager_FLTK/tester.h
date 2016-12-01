#ifndef TESTER_H
#define TESTER_H 2016

#include "shop.h"

class Tester
{
public:
	Tester(Shop p_shop) : shop(p_shop) {}
	Shop shop;

	void testOutputingRobotParts();
	void testOutputingRobotModels();
	void testFileSavingLoading();
};

#endif