#include "robot_parts.h"

using namespace std;

//RobotPart [Base Class]
ostream& operator<<(ostream& os, const RobotPart& part)
{
	os << part.name;
	return os;
}

//Head [Derived] [empty]

//Locomotor [Derived]

//Torso [Derived]

//Battery [Derived]

//Arm [Derived]