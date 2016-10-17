#ifndef ORDER_H
#define ORDER_H 2016

#include "robot_models.h"
#include "date.h"

#include <vector>
#include <chrono>
#include <ostream>

class Order
{
public:
	Order(
		int p_order_number,
		int p_customer_number,
		int p_sales_associate_number,
		std::vector<RobotModel> p_models,
		double p_price,
		Date p_date) :

		order_number(p_order_number),
		customer_number(p_customer_number),
		sales_associate_number(p_sales_associate_number),
		models(p_models),
		price(p_price),
		date(p_date) {};

	static double calculatePrice(std::vector<RobotModel> models)
	{
		double result = 0;
		for (int i = 0; i < models.size(); i++)
		{
			result += models[i].getPrice();
		}

		return result;
	}

	friend std::ostream& operator<<(std::ostream& os, const Order& order);
private:
	int order_number;
	int customer_number;
	int sales_associate_number;
	std::vector <RobotModel> models;
	double price;
	Date date;
};

#endif
