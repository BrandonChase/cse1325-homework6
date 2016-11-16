#include "robot_models.h"
#include "easy_input.h"

using namespace std;

double RobotModel::getPrice()
{
	return price;
}

int RobotModel::getModelNumber() const
{
	return model_number;
}

std::string RobotModel::outputFormattedString(std::string offset, bool show_details) const
{
	string result;
	result += name + " ~ Model #: " + to_string(model_number) + "\n";

	if (show_details)
	{
		offset += "\t";
		result += offset + "Model Price: $" + doubleToString(price) + "\n";
		result += offset + s_head.outputFormattedString(offset, 1);
		result += offset + s_torso.outputFormattedString(offset, 1);
		result += offset + to_string(battery_quantity) + " x " + s_battery.outputFormattedString(offset, 1);
		result += offset + to_string(arm_quantity) + " x " + s_arm.outputFormattedString(offset, 1);
		result += offset + s_locomotor.outputFormattedString(offset, 1);
	}

	return result;
}

// SAVE METHOD FOR LOAD/SAVE

string RobotModel::saveData()
{
	return name + "," + to_string(model_number) + "," + to_string(price) + "," + to_string(s_head.getPartNumber()) + "," + to_string(s_torso.getPartNumber())
	 + "," + to_string(s_locomotor.getPartNumber()) + "," + to_string(s_battery.getPartNumber()) + "," + to_string(s_arm.getPartNumber()) 
	 + "," + to_string(battery_quantity) + "," + to_string(arm_quantity);
}

string RobotModel::getModelName()
{
	return name;
}