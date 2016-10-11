#include "part_type.h"

using namespace std;

ostream& operator<<(ostream& os, const PartType& part)
{
	switch (part.value)
	{
	case -1:
		os << "All";
		break;
	case 0:
		os << "Torso";
		break;

	case 1:
		os << "Head";
		break;

	case 2:
		os << "Arm";
		break;

	case 3:
		os << "Locomotor";
		break;

	case 4:
		os << "Battery";
		break;

	default:
		os << "UNKNOWN";
	}

	return os;
}