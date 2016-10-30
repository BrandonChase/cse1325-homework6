#ifndef PART_TYPE_H
#define PART_TYPE_H 2016

#include <string>
#include <ostream>

class PartType
{
public:
	PartType(int p_value) : value(p_value) {}

	static const int HEAD = 0;
	static const int TORSO = 1;
	static const int BATTERY = 2;
	static const int ARM = 3;
	static const int LOCOMOTOR = 4;
	static const int ALL = -1;
	static const int NUM_OF_PART_TYPES = 5;

	friend std::ostream& operator<<(std::ostream& os, const PartType& type);

private:
	int value;
};

#endif
