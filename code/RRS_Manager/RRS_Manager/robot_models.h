#ifndef ROBOT_MODELS_H
#define ROBOT_MODELS_H 2016

#include <string>
#include <robotparts.h>

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

private:
	std::string name;
	int model_number;
	double price;
	double cost;
	Head model_head;
	Torso model_torso;
	Locomoter model_locomoter;
	Battery model_battery; // 1-3
	Arm model_arm; // 1-2

};


#endif