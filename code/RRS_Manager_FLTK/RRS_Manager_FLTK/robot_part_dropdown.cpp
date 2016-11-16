#include "robot_part_dropdown.h"

#include <stdexcept>
#include <exception>

using namespace std;

RobotPartDropDown::RobotPartDropDown(int x, int y, int width, int height) : Fl_Choice(x, y, width, height, "Part Type: ") {};

void RobotPartDropDown::setItems()
{
	add("Head");
	add("Torso");
	add("Battery");
	add("Arm");
	add("Locomotor");
}

PartType RobotPartDropDown::getValue()
{
	int part_type_index = value();
	if (part_type_index == -1)
	{
		throw runtime_error("Part Type is blank!");
	}

	else if (part_type_index < 0 || part_type_index > PartType::NUM_OF_PART_TYPES - 1)
	{
		throw runtime_error("Unknown part type!");
	}
	return PartType(part_type_index);
}