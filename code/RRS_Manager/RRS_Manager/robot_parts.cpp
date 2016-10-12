#include "robot_parts.h"
#include <iomanip>

using namespace std;

//Operator Overloading
void RobotPart::ostreamBaseFields(ostream& os) const
{
	os
		<< name
		<< "    || " << "\"" << description << "\""
		<< " | Part #" << part_number
		<< " | " << weight << " lb(s)"
		<< " | $" << price;
}

ostream& operator<<(ostream& os, const Head& part)
{
	part.ostreamBaseFields(os);
	return os;
}

ostream& operator<<(ostream& os, const Locomotor& part)
{
	part.ostreamBaseFields(os);
	os 
		<< " | Max of " << part.max_speed << " MPH" << endl 
		<< " | Consumes " << part.power_consumed << " W" << endl;
	return os;
}

ostream& operator<<(ostream& os, const Torso& part)
{
	part.ostreamBaseFields(os);
	os << " | " << part.battery_compartments << " Battery Compartments"<< endl;
	return os;
}

ostream& operator<<(ostream& os, const Battery& part)
{
	part.ostreamBaseFields(os);
	os << " | Contains " << part.contained_energy << " kWh" << endl;
	return os;
}

ostream& operator<<(ostream& os, const Arm& part)
{
	part.ostreamBaseFields(os);
	os << " | Consumes " << part.power_consumed << " W" << endl;
	return os;
}

//RobotPart [Base Class]

double RobotPart::getPrice() const
{
	return price;
}

int Torso::getNumBatteries() const // returns number of battery compartments
{
	return battery_compartments;
}

//Head [Derived] [empty]

//Locomotor [Derived]

//Torso [Derived]

//Battery [Derived]

//Arm [Derived]