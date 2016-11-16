#ifndef ROBOT_PART_DROPDOWN_H
#define ROBOT_PART_DROPDOWN_H 2016

#include <FL/Fl.H>
#include <FL/Fl_Choice.H>

#include "part_type.h"

class RobotPartDropDown : public Fl_Choice
{
public:
	//Constructor
	RobotPartDropDown(int x, int y, int width, int height);

	//Misc. Functions
	void setItems();
	PartType getValue();
};

#endif