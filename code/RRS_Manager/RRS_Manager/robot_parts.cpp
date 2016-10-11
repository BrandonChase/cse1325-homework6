#include "robot_parts.h"

using namespace std;

//RobotPart [Base Class]
ostream& operator<<(ostream& os, const RobotPart& part)
{
	os << part.name;
	return os;
}

double RobotPart::costofpart() const
{
	return price;
}

int Torso::numbatteries() const // returns number of battery compartments
{
	return battery_compartments;
}

//Head [Derived] [empty]

//Locomotor [Derived]

//Torso [Derived]

//Battery [Derived]

//Arm [Derived]