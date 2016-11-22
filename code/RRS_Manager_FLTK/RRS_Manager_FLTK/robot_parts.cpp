#include "robot_parts.h"
#include <iomanip>
#include "easy_input.h"

using namespace std;

//STRING OUTPUT
string RobotPart::getImageLocation() const
{
	return image_filename;
}

string RobotPart::outputBasics(string offset) const
{
	return (name + " ~ Part #: " + to_string(part_number) + "\n");
}

string RobotPart::outputSpecifics(string offset) const
{
	string result;

	result += offset + "Description: " + description + "\n";
	result += offset + "Weight: " + doubleToString(weight) + "lbs\n";
	result += offset + "Price: $" + doubleToString(price) + "\n";

	return result;
}

string Head::outputFormattedString(string offset, bool show_details) const
{
	string result;
	result += outputBasics(offset);

	if (show_details)
	{
		offset += "\t";
		result += outputSpecifics(offset);
	}

	return result;
}

string Torso::outputFormattedString(string offset, bool show_details) const
{
	string result;
	result += outputBasics(offset);

	if (show_details)
	{
		offset += "\t";
		result += outputSpecifics(offset);
		result += offset + "Battery Compartments: " + to_string(battery_compartments) + " compartments\n";
	}

	return result;
}

string Locomotor::outputFormattedString(string offset, bool show_details) const
{
	string result;
	result += outputBasics(offset);

	if (show_details)
	{
		offset += "\t";
		result += outputSpecifics(offset);
		result += offset + "Max Speed: " + doubleToString(max_speed) + "MPH\n";
		result += offset + "Power Consumed: " + doubleToString(power_consumed) + "W\n";
	}

	return result;
}

string Battery::outputFormattedString(string offset, bool show_details) const
{
	string result;
	result += outputBasics(offset);

	if (show_details)
	{
		offset += "\t";
		result += outputSpecifics(offset);
		result += offset + "Contained Energy: " + doubleToString(contained_energy) + "kWh\n";
	}

	return result;
}

string Arm::outputFormattedString(string offset, bool show_details) const
{
	string result;
	result += outputBasics(offset);

	if (show_details)
	{
		offset += "\t";
		result += outputSpecifics(offset);
		result += offset + "Power Consumed: " + doubleToString(power_consumed) + "W\n";
	}

	return result;
}


int RobotPart::getPartNumber() const 
{
	return part_number;
}


double RobotPart::getPrice() const
{
	return price;
}

string RobotPart::getName() const
{
	return name;
}

string RobotPart::getFileName() const
{
	return image_filename;
}

int Torso::getNumBatteries() const 
{
	return battery_compartments;
}

// SAVE METHODS FOR LOAD/SAVE

string RobotPart::saveData() const 
{
	return name + "," + to_string(part_number) + "," + to_string(weight) + "," + to_string(price) + "," + description + "," + image_filename;
}

string Locomotor::saveData() const 
{
	return RobotPart::saveData() + "," + to_string(max_speed) + "," + to_string(power_consumed);
}

string Torso::saveData() const 
{
	return RobotPart::saveData() + "," + to_string(battery_compartments);
}

string Battery::saveData() const 
{
	return RobotPart::saveData() + "," + to_string(contained_energy);
}

string Arm::saveData() const 
{
	return RobotPart::saveData() + "," + to_string(power_consumed);
}
