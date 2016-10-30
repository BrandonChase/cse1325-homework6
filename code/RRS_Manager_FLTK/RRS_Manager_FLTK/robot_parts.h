#ifndef ROBOT_PARTS_H
#define ROBOT_PARTS_H 2016

#include <string>
#include <ostream>
#include <sstream>
#include "part_type.h"

class RobotPart
{
public:
	RobotPart(
		std::string p_name,
		int p_part_number,
		double p_weight,
		double p_price,
		PartType p_type,
		std::string p_description) :

	name(p_name),
	part_number(p_part_number),
	weight(p_weight),
	price(p_price),
	type(p_type),
	description(p_description) {}

	int getPartNumber() const;
	double getPrice() const;
	virtual std::string outputFormattedString(std::string offset, bool show_details) const = 0;
	std::string saveData() const; 
protected:
	std::string name;
	int part_number;
	double weight; //lbs
	double price; //$
	PartType type;
	std::string description;
	std::string outputBasics(std::string offset) const;
	std::string outputSpecifics(std::string offset) const;
};

class Head : public RobotPart 
{
public:
	Head(
		std::string p_name,
		int p_part_number,
		double p_weight,
		double p_price,
		PartType p_type,
		std::string p_description) :

	RobotPart(p_name, p_part_number, p_weight, p_price, p_type, p_description) {}
	std::string outputFormattedString(std::string offset, bool show_details) const;

private:
};

class Locomotor : public RobotPart
{
public:
	Locomotor(
		std::string p_name,
		int p_part_number,
		double p_weight,
		double p_price,
		PartType p_type,
		std::string p_description,
		double p_max_speed,
		double p_power_consumed) :


	RobotPart(p_name, p_part_number, p_weight, p_price, p_type, p_description),
	max_speed(p_max_speed),
	power_consumed(p_power_consumed) {}

	std::string outputFormattedString(std::string offset, bool show_details) const;
	std::string saveData() const;

private:
	double max_speed; //MPH
	double power_consumed; //W
};

class Torso : public RobotPart
{
public:
	Torso( 
		std::string p_name, 
		int p_part_number, 
		double p_weight, 
		double p_price, 
		PartType p_type, 
		std::string p_description,
		int p_battery_compartments) :

	RobotPart(p_name, p_part_number, p_weight, p_price, p_type, p_description), 
	battery_compartments(p_battery_compartments){}
	std::string saveData() const;
	std::string outputFormattedString(std::string offset, bool show_details) const;
	int getNumBatteries() const;
private:
	int battery_compartments;
};

class Battery : public RobotPart
{
public:
	Battery(
		std::string p_name,
		int p_part_number,
		double p_weight,
		double p_price,
		PartType p_type,
		std::string p_description,
		double p_contained_energy) :

	RobotPart(p_name, p_part_number, p_weight, p_price, p_type, p_description),
	contained_energy(p_contained_energy) {}
	std::string saveData() const;
	std::string outputFormattedString(std::string offset, bool show_details) const;

private:
	double contained_energy; //kWh
};

class Arm : public RobotPart
{
public:
	Arm(
		std::string p_name,
		int p_part_number,
		double p_weight,
		double p_price,
		PartType p_type,
		std::string p_description,
		double p_power_consumed) :

	RobotPart(p_name, p_part_number, p_weight, p_price, p_type, p_description),
	power_consumed(p_power_consumed) {}
	std::string saveData() const;
	std::string outputFormattedString(std::string offset, bool show_details) const;

private:
	double power_consumed; //W
};
#endif