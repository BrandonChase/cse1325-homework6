#include "subwindows.h"

#include <FL/Fl_File_Chooser.H>

#include <string>

using namespace std;

//CreatePartWindowFolder
CreatePartWindowFolder::CreatePartWindowFolder(FLTKController& p_controller) : controller(p_controller)
{
	create_part_win->add(picture_box);
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

void CreatePartWindowFolder::create_btn_CB()
{
	controller.createRobotPart();
}

void CreatePartWindowFolder::part_type_widg_CB()
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

void CreatePartWindowFolder::choose_image_btn_CB()
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
	string filename = fl_file_chooser("Robot Part", "*.png", directory.c_str(), 1);
	delete image;
	image = new Fl_PNG_Image(filename.c_str());
	picture_box->image(image);
	create_part_win->redraw();
}