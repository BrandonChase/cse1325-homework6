#include "subwindows.h"

#include <FL/Fl_File_Chooser.H>

#include <string>

using namespace std;

//CreatePartWindowFolder
CreatePartSubWindow::CreatePartSubWindow(Shop& p_shop) : Fl_Window(0, MENUHEIGHT + 1, WIDTH, HEIGHT - MENUHEIGHT), shop(p_controller)
{
	add(picture_box);
	//Set values for drop down box
	part_type_widg->add("Head");
	part_type_widg->add("Torso");
	part_type_widg->add("Battery");
	part_type_widg->add("Arm");
	part_type_widg->add("Locomotor");
	//Disable extra textboxes by deafult
	battery_compartments_widg->hide();
	power_consumed_widg->hide();
	max_speed_widg->hide();
	contained_energy_widg->hide();
	choose_image_btn->hide();
	//Setting Callbacks
	create_widg->callback(create_btn_CB, this);
	part_type_widg->callback(part_type_widg_CB, this);
	choose_image_btn->callback(choose_image_btn_CB, this);
}

void CreatePartSubWindow::create_btn_CB()
{
	
}

void CreatePartSubWindow::part_type_widg_CB()
{
	switch (part_type_widg->value())
	{
	case 0: //Head
		battery_compartments_widg->hide();
		power_consumed_widg->hide();
		max_speed_widg->hide();
		contained_energy_widg->hide();
		choose_image_btn->show();
		break;

	case 1: //Torso
		battery_compartments_widg->show();
		power_consumed_widg->hide();
		max_speed_widg->hide();
		contained_energy_widg->hide();
		choose_image_btn->show();
		break;

	case 2: //Battery
		battery_compartments_widg->hide();
		power_consumed_widg->hide();
		max_speed_widg->hide();
		contained_energy_widg->show();
		choose_image_btn->show();
		break;

	case 3: //Arm
		battery_compartments_widg->hide();
		power_consumed_widg->show();
		max_speed_widg->hide();
		contained_energy_widg->hide();
		choose_image_btn->show();
		break;

	case 4: //Locomotor
		battery_compartments_widg->hide();
		power_consumed_widg->show();
		max_speed_widg->show();
		contained_energy_widg->hide();
		choose_image_btn->show();
		break;
	}
}

void CreatePartSubWindow::choose_image_btn_CB()
{
	string directory = "./Images/";
	switch (part_type_widg->value())
	{
	case 0: //Head
		directory += "Heads";
		break;

	case 1: //Torso
		directory += "Torsos";
		break;

	case 2: //Battery
		directory += "Batteries";
		break;

	case 3: //Arm
		directory += "Arms";
		break;

	case 4: //Locomotor
		directory += "Locomotors";
		break;
	}
	image_filename = fl_file_chooser("Robot Part", "*.png", directory.c_str(), 1);
	picture_box->image(Fl_PNG_Image(image_filename.c_str()));
	redraw();
}

//GETTERS
PartType CreatePartSubWindow::partType() const
{
	int part_type_index = part_type_widg->value();
	return PartType(part_type_index);
}

string CreatePartSubWindow::name() const
{
	return name_widg->value();
}

int CreatePartSubWindow::partNumber() const
{
	return stoi(part_number_widg->value());
}

double CreatePartSubWindow::weight() const
{
	return stod(weight_widg->value());
}

double CreatePartSubWindow::price() const
{
	return stod(price_widg->value());
}

string CreatePartSubWindow::description() const
{
	return description_widg->value();
}

int CreatePartSubWindow::batteryCompartments() const
{
	return stoi(battery_compartments_widg->value());
}

double CreatePartSubWindow::powerConsumed() const
{
	return stod(power_consumed_widg->value());
}

double CreatePartSubWindow::maxSpeed() const
{
	return stod(max_speed_widg->value());
}

double CreatePartSubWindow::containedEnergy() const
{
	return stod(contained_energy_widg->value());
}

string CreatePartSubWindow::imageFileName() const
{
	return image_filename;
}