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

void Shop::addOrder(Order p_order, int sales_associate_id, int customer_id) // was not adding orders to sales assoc or customer, so save was seg faulting. 
{
	for (int i = 0; i < customers.size(); i++)
	{
		if (customers[i].getCustomerNumber() == customer_id)
		{
			customers[i].addOrder(p_order);
		}
	}

	for (int i = 0; i < sales_associates.size(); i++)
	{
		if (sales_associates[i].getSalesAssociateNumber() == sales_associate_id)
		{
			sales_associates[i].addOrder(p_order);
		}
	}
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


void Shop::LoadRobotModel(string name, int model_num, double price, int head_p, int torso_p, int locomotor_p, int battery_p, int arm_p)
{

	int h_choice = -1 , l_choice = -1 , t_choice = -1, b_choice = -1, a_choice = -1;

	for (int i = 0; i < heads.size(); i++)
	{
		if (heads[i].getPartNumber() == head_p)
		{	
			h_choice = i;
		}
	}

	for (int i = 0; i < locomotors.size(); i++)
	{
		if (locomotors[i].getPartNumber() == locomotor_p)
		{
			l_choice = i;
		}
	}

	for (int i = 0; i < torsos.size(); i++)
	{
		if (torsos[i].getPartNumber() == torso_p)
		{
			t_choice = i;
		}
	}

	for (int i = 0; i < batteries.size(); i++)
	{
		if (batteries[i].getPartNumber() == battery_p)
		{
			b_choice = i;
		}
	}

	for (int i = 0; i < arms.size(); i++)
	{
		if (arms[i].getPartNumber() == arm_p)
		{
			a_choice = i;
		}
	}

	if ((h_choice == -1) || (l_choice == -1) || (t_choice == -1) || (b_choice == -1) || (a_choice == -1))
	{
		cout << "\t***Error: Was unable to load Model - corrupted save file.\n";
		return;
	}

	addRobotModel(RobotModel(name, model_num, price, heads[h_choice], torsos[t_choice], locomotors[l_choice], batteries[b_choice], arms[a_choice]));
}


void Shop::LoadOrder(string line)
{
	vector<string> spline = splitter(line, ',');
	vector<RobotModel> ordermodels;
	for (int i = 3; i < spline.size() - 3; i++)
	{
		for (int j = 0; j < models.size(); j++)
		{
			if (stoi(spline[i]) == models[j].getModelNumber())
			{
				ordermodels.push_back(models[j]);
			}
		}
	}
	vector<string> spdate = splitter( spline[spline.size()-1], '/');
	Date dresult(stoi(spdate[0]), stoi(spdate[1]), stoi(spdate[2]));

	addOrder(Order(stoi(spline[0]), stoi(spline[1]), stoi(spline[2]), ordermodels,stod(spline[spline.size()-2]), dresult), stoi(spline[1]), stoi(spline[2])); //last var needs some work, needs to convert to date.
}

vector<string> Shop::splitter(const string &s, char delim) 
{
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}

// SAVE METHOD FOR LOAD/SAVE


void Shop::savefile()
{
	cout << "Name of file to write to: ";
	string outfile;
	cin >> outfile;
	ofstream ofs;
	ofs.open(outfile.c_str());
	if(!ofs) throw runtime_error("Unable to open output file " + outfile);
	int i=1;
	for (int i = 0; i < PartType::NUM_OF_PART_TYPES; i++)
	{
		ofs << "/" << PartType(i) << "/\n";

		if (i == PartType::HEAD)
		{
			for (Head head : heads)
			{
				ofs <<  head.saveData() << "\n";
			}
		}
		if (i == PartType::TORSO)
		{
			for (Torso torso : torsos)
			{
				ofs <<  torso.saveData() << "\n";
			}
		}
		if (i == PartType::BATTERY)
		{
			for (Battery battery : batteries)
			{
				ofs <<  battery.saveData() << "\n";
			}
		}
		if (i == PartType::ARM)
		{
			for (Arm arm : arms)
			{
				ofs <<  arm.saveData() << "\n";
			}
		}
		if (i == PartType::LOCOMOTOR)
		{
			for (Locomotor locomotor : locomotors)
			{
				ofs <<  locomotor.saveData() << "\n";
			}
		}		
	}

	ofs << "/RobotModel/\n";
	for (RobotModel model : models)
	{
		ofs << model.saveData() << "\n";
	}



	ofs << "/Customers/\n";
	for (Customer customer : customers)
	{
		ofs << customer.saveData() << "\n";
	}


	ofs << "/SalesAssociates/\n";
	for (SalesAssociate sales_associate : sales_associates)
	{
		ofs << sales_associate.saveData() << "\n";
	}


	ofs << "/Orders/\n";
	for (Order order : orders)
	{
		ofs << order.saveData() << "\n";
	}


	ofs.close();
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
	addCustomer(Customer("Ted Cruz", 666));

	addSalesAssociate(SalesAssociate("Seller 1", 1));
	addSalesAssociate(SalesAssociate("Seller 2", 2));
	addSalesAssociate(SalesAssociate("Seller 3", 3));
	vector<RobotModel> models_pop = {models[0], models[1]};
	Date odate(5,6,1996);
	addOrder(Order(1, 12345, 1, models_pop, 600.0, odate), 1, 12345);
	addOrder(Order(2, 666, 1, models_pop, 600.0, odate), 2, 666);
	addOrder(Order(3, 12345, 1, models_pop, 500.0, odate), 3, 12345);

}




