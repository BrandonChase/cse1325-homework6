#ifndef SHOP_H
#define SHOP_H 2016

#include "sales_associate.h"
#include "customer.h"
#include "order.h"
#include "robot_models.h"
#include "robot_parts.h"
#include "part_type.h"
#include "date.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

class Shop
{
public:
	bool isDirty = false;
	void addHead(Head p_head);
	void addLocomotor(Locomotor p_locomotor);
	void addTorso(Torso p_torso);
	void addBattery(Battery p_battery);
	void addArm(Arm p_arm);
	void addRobotModel(RobotModel p_model);
	void addOrder(Order p_order, int sales_associate_id, int customer_id);
	void addCustomer(Customer p_customer);
	void addSalesAssociate(SalesAssociate p_sa);



	const std::vector<Customer>& getCustomers();
	const std::vector<Order>& getOrders();
	const std::vector<RobotModel>& getModels();
	const std::vector<Head>& getHeads();
	const std::vector<Locomotor>& getLocomotors();
	const std::vector<Torso>& getTorsos();
	const std::vector<Battery>& getBatteries();
	const std::vector<Arm>& getArms();
	const std::vector<SalesAssociate>& getSalesAssociates();

	bool isAnyPartListEmpty();
	bool areAllPartListsEmpty();
	void LoadRobotModel(std::string name, int model_num, double price, int head_p, int torso_p, int locomotor_p, int battery_p, int arm_p, int battery_quantity, int arm_quantity);
	void LoadOrder(std::string line);
	std::vector<std::string> splitter(const std::string &s, char delim);

	void resetShop();
	void populateShopForTesting();
	void savefile(std::string outfile);
	void loadfile(std::string infile);

	bool isPartNumberUnique(int desired_part_number);
	bool isModelNumberUnique(int desired_model_number);
	bool isCustomerNumberUnique(int desired_customer_number);
	bool isSANumberUnique(int desired_sa_number);
	bool isOrderNumberUnique(int desired_order_number);


private:
	std::vector<SalesAssociate> sales_associates;
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
