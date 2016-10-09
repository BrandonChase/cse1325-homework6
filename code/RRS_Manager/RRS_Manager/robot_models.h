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
				double m_price,
				Head p_head,
				Torso p_torso,
				Locomoter p_locomoter,
				Battery p_battery;
				Arm p_arm;
				) :

				name(m_name),
				model_number(m_number),
				price(m_price),
				s_head(p_head),
				s_torso(p_torso),
				s_locometer(p_locometer),
				s_battery(p_battery).
				s_arm(p_arm) {}

private:
	std::string name;
	int model_number;
	double price;
	double cost;
	Head s_head;
	Torso s_torso;
	Locomoter s_locomoter;
	Battery s_battery; // 1-3
	Arm s_arm; // 1-2

};


#endif