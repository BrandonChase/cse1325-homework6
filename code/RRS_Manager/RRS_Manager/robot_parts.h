#ifndef ROBOT_PARTS_H
#define ROBOT_PARTS_H 2016

#include <string>

using namespace std;

enum class PartType { Torso, Head, Arm, Locomotor, Battery};

class RobotPart
{
public:
protected:
	string name;
	int part_number;
	double weight;
	double cost;
	PartType type;
	string description;
};

class Head : public RobotPart {};

class Locomoter : public RobotPart
{
public:
	
private:
	int max_speed; //MPH
	int power_consumed; //W
};

class Torso : public RobotPart
{
public:

private:
	int battery_compartments;
};

class Battery : public RobotPart
{
public:

private:
	int contained_energy; //kWh
};

class Arm : public RobotPart
{
	int power_consumed; //W
};
#endif