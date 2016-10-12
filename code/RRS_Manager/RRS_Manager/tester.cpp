#include "tester.h"

#include "shop.h"
#include "view.h"
#include "part_type.h"
#include <iostream>

using namespace std;

void Tester::testOutputingRobotParts()
{
	Shop shop;
	View view(shop);
	const vector<Head>& heads_x = shop.getHeads();
	const vector<Locomotor>& locomotors_x = shop.getLocomotors();
	const vector<Torso>& torsos_x = shop.getTorsos();
	const vector<Battery>& batteries_x = shop.getBatteries();
	const vector<Arm>& arms_x = shop.getArms();
	const vector<RobotModel>& models = shop.getModels();

	shop.addHead(Head("Head1", 111, 1, 5, PartType::HEAD, "This is head no. 1"));
	shop.addTorso(Torso("Torso1", 112, 2, 6, PartType::TORSO, "This is torso no. 1", 2));
	shop.addArm(Arm("Arm1", 113, 3, 7, PartType::ARM, "This is arm no. 1",125));
	shop.addBattery(Battery("Battery", 114, 4, 8, PartType::BATTERY, "This is battery no. 1", 500));
	shop.addLocomotor(Locomotor("Locomotor1", 115, 5, 9, PartType::LOCOMOTOR, "This is locomotor no. 1",20,750));
	shop.addRobotModel(RobotModel("Destroyer 9000", 111, 500, heads_x[0], torsos_x[0], locomotors_x[0], batteries_x[0], arms_x[0]));
	shop.addRobotModel(RobotModel("Personal Servant", 223, 500, heads_x[0], torsos_x[0], locomotors_x[0], batteries_x[0], arms_x[0]));
	shop.addRobotModel(RobotModel("War Bot", 3345, 500, heads_x[0], torsos_x[0], locomotors_x[0], batteries_x[0], arms_x[0]));

	view.listRobotModels();
}