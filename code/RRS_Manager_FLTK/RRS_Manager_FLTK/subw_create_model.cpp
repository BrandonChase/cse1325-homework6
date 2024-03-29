#include "subw_create_model.h"

#include <FL/Fl_File_Chooser.H>

#include <stdexcept>
#include <exception>
#include <string>

using namespace std;

//
//CreateModelSUBWINDOW
//
CreateModelSubWindow::CreateModelSubWindow(Shop &p_shop) : Fl_Window(0, MENUHEIGHT + 1, WIDTH, HEIGHT - MENUHEIGHT), shop(p_shop)
{
		//Initialize Widgets
	name_tb = new Fl_Input(tb_offset, 0, TB_WIDTH, TB_HEIGHT, "Name: ");
	model_number_tb = new Fl_Int_Input(tb_offset, 1 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Model Number: ");
	head_choice_dd = new Fl_Choice(tb_offset, 2 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Head: ");
	torso_choice_dd = new Fl_Choice(tb_offset, 3 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Torso: ");
	locomotor_choice_dd = new Fl_Choice(tb_offset, 4 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Locomotor: ");
	battery_choice_dd = new Fl_Choice(tb_offset, 5 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Battery: ");
	num_batteries_tb = new Fl_Int_Input(tb_offset, 6 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Number of batteries: ");
	arm_choice_dd = new Fl_Choice(tb_offset, 7 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Arm: ");		
	num_arms_tb = new Fl_Int_Input(tb_offset, 8 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Number of Arms: ");	
	price_tb = new Fl_Float_Input(tb_offset, 9 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Price [$]: ");
	
	create_btn = new Fl_Button(210, 10 * (TB_HEIGHT + TB_SPACING), 100, 50, "Create Model");
	
	const int xoffset = 220+tb_offset, yoffset = 0, xsize = 200, ysize = 200;

	Fl_Tabs *tabs = new Fl_Tabs(xoffset,yoffset,xsize+50,ysize+150);
	{

		Fl_Group *head_g = new Fl_Group(xoffset,yoffset,xsize,ysize+50,"Head");
		{
			head_picture_box = new Fl_Box(75+xoffset, 50+yoffset, 100, 100);
		}
		head_g->end();

		Fl_Group *torso_g = new Fl_Group(xoffset,yoffset,xsize,ysize+50,"Torso");
		{
			torso_picture_box = new Fl_Box(75+xoffset, 50+yoffset, 100, 100);
		}
		torso_g->end();

		Fl_Group *locomotor_g = new Fl_Group(xoffset,yoffset,xsize,ysize+50,"Loco");
		{
			locomotor_picture_box = new Fl_Box(75+xoffset, 50+yoffset, 100, 100);
		}
		locomotor_g->end();

		Fl_Group *battery_g = new Fl_Group(xoffset,yoffset,xsize,ysize+50,"Batt");
		{
			battery_picture_box = new Fl_Box(75+xoffset, 50+yoffset, 100, 100);
		}
		battery_g->end();

		Fl_Group *arm_g = new Fl_Group(xoffset,yoffset,xsize,ysize+50,"Arm ");
		{
			arm_picture_box = new Fl_Box(75+xoffset, 50+yoffset, 100, 100);
		}
		arm_g->end();


	}
	tabs->end();
	create_btn->callback(s_create_btn_CB, this);
}

	//CALLBACKS
void CreateModelSubWindow::display_image_CB()
{

	if (heads_x.size() != 0)
	{
		head_image = new Fl_PNG_Image(heads_x[head_choice_dd->value()].getImageLocation().c_str());
		head_picture_box->image(head_image);
		head_picture_box->show();
	}
	
	if (torsos_x.size() != 0)
	{
		torso_image = new Fl_PNG_Image(torsos_x[torso_choice_dd->value()].getImageLocation().c_str());
		torso_picture_box->image(torso_image);
		torso_picture_box->show();
	}

	if (locomotors_x.size() != 0)
	{
		locomotor_image = new Fl_PNG_Image(locomotors_x[locomotor_choice_dd->value()].getImageLocation().c_str());
		locomotor_picture_box->image(locomotor_image);
		locomotor_picture_box->show();
	}
	
	if (batteries_x.size() != 0)
	{
		battery_image = new Fl_PNG_Image(batteries_x[battery_choice_dd->value()].getImageLocation().c_str());
		battery_picture_box->image(battery_image);
		battery_picture_box->show();
	}

	if (arms_x.size() != 0)
	{
		arm_image = new Fl_PNG_Image(arms_x[arm_choice_dd->value()].getImageLocation().c_str());
		arm_picture_box->image(arm_image);
		arm_picture_box->show();
	}

	redraw();

}


void CreateModelSubWindow::update_dd()
{

	heads_x = shop.getHeads();
	locomotors_x = shop.getLocomotors();
	torsos_x = shop.getTorsos();
	batteries_x = shop.getBatteries();
	arms_x = shop.getArms();
	

	for (Head h : heads_x)
	{
		head_choice_dd->add(h.outputFormattedString("",1).c_str());
	}
	head_choice_dd->value(0);
	head_choice_dd->callback(s_display_image_CB, this);

	for (Torso t : torsos_x){
		torso_choice_dd->add(t.outputFormattedString("",1).c_str());
	}
	torso_choice_dd->value(0);
	torso_choice_dd->callback(s_display_image_CB, this);

	for (Locomotor l : locomotors_x){
		locomotor_choice_dd->add(l.outputFormattedString("",0).c_str());
	}
	locomotor_choice_dd->value(0);
	locomotor_choice_dd->callback(s_display_image_CB, this);

	for (Battery b : batteries_x){
		battery_choice_dd->add(b.outputFormattedString("",0).c_str());
	}
	battery_choice_dd->value(0);
	battery_choice_dd->callback(s_display_image_CB, this);

	for (Arm a : arms_x){
		arm_choice_dd->add(a.outputFormattedString("",0).c_str());
	}
	arm_choice_dd->value(0);
	arm_choice_dd->callback(s_display_image_CB, this);
}


void CreateModelSubWindow::create_btn_CB()
{
	try
	{
		string name = this->name();
		int model_number = modelNumber();
		double price = this->price();
		int numb_batteries = this->num_batteries();
		int numb_arms = this->num_arms();

		shop.addRobotModel(RobotModel(name, model_number, price, heads_x[head_choice_dd->value()], torsos_x[torso_choice_dd->value()], 
			locomotors_x[locomotor_choice_dd->value()], batteries_x[battery_choice_dd->value()], arms_x[arm_choice_dd->value()], numb_batteries, numb_arms));

		reset();
		this->hide();
	}
	catch (const exception& e)
	{
		Fl::error(e.what());
	}
}


	//GETTERS

string CreateModelSubWindow::name() const
{
	string name = name_tb->value();
	if (name == "")
	{
		throw runtime_error("Required field is blank!");
	}
	return name;
}


double CreateModelSubWindow::price() const
{
	double price;
	try
	{
		price = stod(price_tb->value());
	}
	catch (...)
	{
		throw runtime_error("Price is not valid number!");
	}
	double cost = heads_x[head_choice_dd->value()].getPrice() + locomotors_x[locomotor_choice_dd->value()].getPrice() + torsos_x[torso_choice_dd->value()].getPrice() 
	+ batteries_x[battery_choice_dd->value()].getPrice()*num_batteries() + arms_x[arm_choice_dd->value()].getPrice()*num_arms();
	if (price < cost)
	{
		throw runtime_error("Price must be greater than cost!");
	}

	return price;
}


int CreateModelSubWindow::num_batteries() const
{
	int bat_input;
	try
	{
		bat_input = stoi(num_batteries_tb->value());
	}
	catch (...)
	{
		throw runtime_error("Number of batteries is not valid number!");
	}

	if (bat_input < 0 || !isNumBatOkay(bat_input))
	{
		throw runtime_error("Battery selection out of range!");
	}
	return bat_input;
}

int CreateModelSubWindow::num_arms() const
{
	int arm_input;
	try
	{
		arm_input = stoi(num_arms_tb->value());
	}
	catch (...)
	{
		throw runtime_error("Number of arms is not valid number!");
	}

	if (arm_input < 0 || arm_input > 2)
	{
		throw runtime_error("Number of arms is out of range!");
	}

	return arm_input;
}



bool CreateModelSubWindow::isNumBatOkay(int num_bat) const
{
	if (num_bat > torsos_x[torso_choice_dd->value()].getNumBatteries()) 
	{ 
		return false; 
	}
	else
	{
		return true;
	}
}



int CreateModelSubWindow::modelNumber() const
{
	int model_number;
	try
	{
		model_number = stoi(model_number_tb->value());
	}
	catch (...)
	{
		throw runtime_error("Model number is not valid number!");
	}

	if (model_number < 0)
	{
		throw runtime_error("Model number must be positive!");
	}

	if (!shop.isModelNumberUnique(model_number))
	{
		throw runtime_error("Model number is already taken!");
	}

	return model_number;
}



//FUNCTIONS
void CreateModelSubWindow::reset()
{
	name_tb->value(NULL);
	model_number_tb->value(NULL);
	price_tb->value(NULL);
	num_batteries_tb->value(NULL);
	num_arms_tb->value(NULL);

	head_choice_dd->clear();
	torso_choice_dd->clear();
	locomotor_choice_dd->clear();
	battery_choice_dd->clear();
	arm_choice_dd->clear();


	head_picture_box->hide();
	torso_picture_box->hide();
	locomotor_picture_box->hide();
	battery_picture_box->hide();
	arm_picture_box->hide();
}




