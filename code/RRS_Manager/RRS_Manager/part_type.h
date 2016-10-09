#ifndef PART_TYPE_H
#define PART_TYPE_H 2016

#include <string>

class PartType
{
public:
	PartType(int p_value) : value(p_value) {}

	static const int TORSO = 0;
	static const int HEAD = 1;
	static const int ARM = 2;
	static const int LOCOMOTOR = 3;
	static const int BATTERY = 4;

	static const int NUM_OF_PART_TYPES = 5;

	friend std::ostream& operator<<(std::ostream& os, const PartType& type);

private:
	int value;
};

#endif
