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
	model_number_tb = new Fl_Int_Input(tb_offset, 1 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Part Number: ");
	head_choice_dd = new Fl_Choice(tb_offset, 2 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Head: ");
	torso_choice_dd = new Fl_Choice(tb_offset, 3 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Torso: ");
	locomotor_choice_dd = new Fl_Choice(tb_offset, 4 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Locomotor: ");
	battery_choice_dd = new Fl_Choice(tb_offset, 5 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Battery: ");
	//battery_compartments_tb = new Fl_Int_Input(tb_offset, 6 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Battery Compartments: ");
	arm_choice_dd = new Fl_Choice(tb_offset, 6 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Arm: ");		
	price_tb = new Fl_Float_Input(tb_offset, 7 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Price [$]: ");
	
	create_btn = new Fl_Button(210, 10 * (TB_HEIGHT + TB_SPACING), 100, 50, "Create Model");
	

	
	
	
	
	const int xoffset = 350, yoffset = 0, xsize = 200, ysize = 200;
	//gotta do something like this
	//part_type_dd->callback(s_part_type_widg_CB, this);
	create_btn->callback(s_create_btn_CB, this);
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


void CreateModelSubWindow::create_btn_CB()
{
}

void CreateModelSubWindow::update_dd()
{

	heads_x = shop.getHeads();
	locomotors_x = shop.getLocomotors();
	torsos_x = shop.getTorsos();
	batteries_x = shop.getBatteries();
	arms_x = shop.getArms();
	
	//Testing the dd


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

	//GETTERS


string CreateModelSubWindow::name() const
{
	return "";
}

int CreateModelSubWindow::modelNumber() const
{
	return 0;
}


double CreateModelSubWindow::price() const
{
	return 0.0;
}



//FUNCTIONS
void CreateModelSubWindow::reset()
{
	//set all vals to NULL
}




