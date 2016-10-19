#include "robot_models.h"

using namespace std;

ostream& operator<<(ostream& os, const RobotModel& model)
{
	os 
		<< model.name << " ~ Model Number: " << model.model_number << " ~ Cost: $" << model.price << endl
		<< "\tHead:" << endl 
		<< "\t\t" << model.s_head << endl 
		<< "\tTorso:" << endl
		<< "\t\t" << model.s_torso << endl
		<< "\tBattery:" << endl
		<< "\t\t" << model.s_battery <<endl
		<< "\tArm:" << endl
		<< "\t\t" << model.s_arm << endl
		<< "\tLocomotor:" << endl
		<< "\t\t" << model.s_locomotor << endl;
	return os;
}

double RobotModel::getPrice()
{
	return price;
}

int RobotModel::getModelNumber() const
{
	return model_number;
}

string RobotModel::saveData()
{
	return name + "," + to_string(model_number) + "," + to_string(price) + "," + to_string(s_head.getPartNumber()) + "," + to_string(s_torso.getPartNumber())
	 + "," + to_string(s_locomotor.getPartNumber()) + "," + to_string(s_battery.getPartNumber()) + "," + to_string(s_arm.getPartNumber());
}