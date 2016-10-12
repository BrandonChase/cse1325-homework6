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