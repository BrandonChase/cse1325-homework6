#ifndef ROBOT_MODELS_H
#define ROBOT_MODELS_H 2016

#include <string>
#include "robot_parts.h"

class RobotModel
{
public:
	RobotModel(
				std::string m_name,
				int m_number,
				double m_price,
				Head p_head,
				Torso p_torso,
				Locomotor p_locomotor,
				Battery p_battery,
				Arm p_arm) :

				name(m_name),
				model_number(m_number),
				price(m_price),
				s_head(p_head),
				s_torso(p_torso),
				s_locomotor(p_locomotor),
				s_battery(p_battery),
				s_arm(p_arm) {}

private:
	std::string name;
	int model_number;
	double price;
	double cost;
	Head s_head;
	Torso s_torso;
	Locomotor s_locomotor;
	Battery s_battery; // 1-3
	Arm s_arm; // 1-2

};


#endif