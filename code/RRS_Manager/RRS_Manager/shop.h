#ifndef SHOP_H
#define SHOP_H 2016

//include boss
//include sales associate
#include "customer.h"
#include "order.h"
#include "robot_models.h"
#include "robot_parts.h"

#include <vector>

class Shop
{
public:
	void addHead(Head p_head);
	void addLocomotor(Locomotor p_locomotor);
	void addTorso(Torso p_torso);
	void addBattery(Battery p_battery);
	void addArm(Arm p_arm);
	void addRobotModel(RobotModel p_model);

	const std::vector<Customer>& getCustomers();
	const std::vector<Order>& getOrders();
	const std::vector<RobotModel>& getModels();
	const std::vector<Head>& getHeads();
	const std::vector<Locomotor>& getLocomotors();
	const std::vector<Torso>& getTorsos();
	const std::vector<Battery>& getBatteries();
	const std::vector<Arm>& getArms();

	bool isAnyPartListEmpty();
	bool areAllPartListsEmpty();

private:
	//PointedHairedBoss boss;
	//std::vector<SalesAssociate> sales_associates;
	std::vector<Customer> customers;
	std::vector<Order> orders;
	std::vector<RobotModel> models;
	std::vector<Head> heads;
	std::vector<Locomotor> locomotors;
	std::vector<Torso> torsos;
	std::vector<Battery> batteries;
	std::vector<Arm> arms;
};

#endif
