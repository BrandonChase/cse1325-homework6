#ifndef ROBOT_MODELS_H
#define ROBOT_MODELS_H 2016

#include <string>

class RobotModel
{
public:
	RobotModel(
				std::string m_name,
				int m_number,
				double m_price) :

				name(m_name),
				model_number(m_number),
				price(m_price) {}

protected:
	std::string name;
	int model_number;
	double price;
	double cost;
};


#endif