#include "shop.h"
#include "easy_input.h"

using namespace std;

//ADDERS
void Shop::addCustomer(Customer p_customer)
{
	customers.push_back(p_customer);
}

void Shop::addSalesAssociate(SalesAssociate p_sa)
{
	sales_associates.push_back(p_sa);
}

void Shop::addOrder(Order p_order)
{
	orders.push_back(p_order);
}

void Shop::addHead(Head p_head)
{
	heads.push_back(p_head);
}

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

const vector<SalesAssociate>& Shop::getSalesAssociates()
{
	return sales_associates;
}

//BOOL CHECKERS

bool Shop::isAnyPartListEmpty()
{
	return(heads.size() == 0 || torsos.size() == 0 || batteries.size() == 0 || arms.size() == 0 || locomotors.size() == 0);
}

bool Shop::areAllPartListsEmpty()
{
	return(heads.size() == 0 && torsos.size() == 0 && batteries.size() == 0 && arms.size() == 0 && locomotors.size() == 0);
}

void Shop::populateShopForTesting()
{
	addHead(Head("Destroyer Head", 111, 1, 5, PartType::HEAD, "This is destroyer head no. 1"));
	addHead(Head("Servant Head", 123, 2, 10, PartType::HEAD, "This is servant head no. 1"));
	addHead(Head("War Head", 135, 4, 11, PartType::HEAD, "This is war head no. 1"));

	addTorso(Torso("Destroyer Torso", 112, 2, 6, PartType::TORSO, "This is destroyer torso no. 1", 2));
	addTorso(Torso("Servant Torso", 134, 23, 12, PartType::TORSO, "This is servant torso no. 1", 2));
	addTorso(Torso("War Torso", 54, 24, 97, PartType::TORSO, "This is war torso no. 1", 2));

	addArm(Arm("Destroyer Arm", 113, 3, 7, PartType::ARM, "This is destroyer arm no. 1", 125));
	addArm(Arm("Servant Arm", 153, 7, 98, PartType::ARM, "This is servant arm no. 1", 125));
	addArm(Arm("War Arm", 131, 10, 43, PartType::ARM, "This is war arm no. 1", 125));

	addBattery(Battery("Destroyer Battery", 114, 4, 8, PartType::BATTERY, "This is destroyer battery no. 1", 500));
	addBattery(Battery("Servant Battery", 123, 8, 9, PartType::BATTERY, "This is servant battery no. 1", 500));
	addBattery(Battery("War Battery", 321, 6, 18, PartType::BATTERY, "This is war battery no. 1", 500));

	addLocomotor(Locomotor("Destroyer Locomotor", 423, 5, 9, PartType::LOCOMOTOR, "This is destroyer locomotor no. 1", 20, 750));
	addLocomotor(Locomotor("Servant Locomotor", 543, 2, 19, PartType::LOCOMOTOR, "This is servant locomotor no. 1", 20, 750));
	addLocomotor(Locomotor("War Locomotor", 234, 8, 91, PartType::LOCOMOTOR, "This is war locomotor no. 1", 20, 750));

	addRobotModel(RobotModel("Destroyer 9000", 111, 500, heads[0], torsos[0], locomotors[0], batteries[0], arms[0]));
	addRobotModel(RobotModel("Personal Servant", 223, 500, heads[0], torsos[0], locomotors[0], batteries[0], arms[0]));
	addRobotModel(RobotModel("War Bot", 3345, 500, heads[0], torsos[0], locomotors[0], batteries[0], arms[0]));

	addCustomer(Customer("John Smith", 12345));
	addCustomer(Customer("Joe Cloud", 42069));
	addCustomer(Customer("Brandon Chase", 10012));
	addCustomer(Customer("Serial Killer", 121212));

	addSalesAssociate(SalesAssociate("Seller 1", 1));
	addSalesAssociate(SalesAssociate("Seller 2", 2));
	addSalesAssociate(SalesAssociate("Seller 3", 3));
}