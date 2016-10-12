#include "shop.h"
#include "easy_input.h"

using namespace std;

void Shop::addHead(Head p_head)
{
	heads.push_back(p_head);
}

//ADDERS

void Shop::addLocomotor(Locomotor p_locomotor)
{
	locomotors.push_back(p_locomotor);
}

void Shop::addTorso(Torso p_torso)
{
	torsos.push_back(p_torso);
}

void Shop::addBattery(Battery p_battery)
{
	batteries.push_back(p_battery);
}

void Shop::addArm(Arm p_arm)
{
	arms.push_back(p_arm);
}

void Shop::addRobotModel(RobotModel p_model)
{
	models.push_back(p_model);
}

//GETTERS

const vector<Customer>& Shop::getCustomers()
{
	return customers;
}


const vector<Order>& Shop::getOrders()
{
	return orders;
}


const vector<RobotModel>& Shop::getModels()
{
	return models;
}

const vector<Head>& Shop::getHeads()
{
	return heads;
}

const vector<Locomotor>& Shop::getLocomotors()
{
	return locomotors;
}

const vector<Torso>& Shop::getTorsos()
{
	return torsos;
}

const vector<Battery>& Shop::getBatteries()
{
	return batteries;
}

const vector<Arm>& Shop::getArms()
{
	return arms;
}

bool Shop::isAnyPartListEmpty()
{
	return(heads.size() == 0 || torsos.size() == 0 || batteries.size() == 0 || arms.size() == 0 || locomotors.size() == 0);
}

bool Shop::areAllPartListsEmpty()
{
	return(heads.size() == 0 && torsos.size() == 0 && batteries.size() == 0 && arms.size() == 0 && locomotors.size() == 0);
}