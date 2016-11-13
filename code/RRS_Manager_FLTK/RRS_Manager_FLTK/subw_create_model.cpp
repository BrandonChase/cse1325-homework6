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
	picture_box = new Fl_Box(425, 100, 200, 200);

	//gotta do something like this
	//part_type_dd->callback(s_part_type_widg_CB, this);
	create_btn->callback(s_create_btn_CB, this);
}

	//CALLBACKS
void CreateModelSubWindow::part_type_widg_CB()
{
}


void CreateModelSubWindow::create_btn_CB()
{
}

void CreateModelSubWindow::update_dd()
{
	
	const vector<Head>& heads_x = shop.getHeads();
	const vector<Locomotor>& locomotors_x = shop.getLocomotors();
	const vector<Torso>& torsos_x = shop.getTorsos();
	const vector<Battery>& batteries_x = shop.getBatteries();
	const vector<Arm>& arms_x = shop.getArms();
	
	//Testing the dd


	for (Head h : heads_x)
	{
		head_choice_dd->add(h.outputFormattedString("",1).c_str());
	}
	head_choice_dd->value(0);

	for (Torso t : torsos_x){
		torso_choice_dd->add(t.outputFormattedString("",1).c_str());
	}
	torso_choice_dd->value(0);

	for (Locomotor l : locomotors_x){
		locomotor_choice_dd->add(l.outputFormattedString("",0).c_str());
	}
	locomotor_choice_dd->value(0);

	for (Battery b : batteries_x){
		battery_choice_dd->add(b.outputFormattedString("",0).c_str());
	}
	battery_choice_dd->value(0);

	for (Arm a : arms_x){
		arm_choice_dd->add(a.outputFormattedString("",0).c_str());
	}
	arm_choice_dd->value(0);


}

	//GETTERS


string CreateModelSubWindow::name() const
{
	return NULL;
}

int CreateModelSubWindow::modelNumber() const
{
	return NULL;
}


double CreateModelSubWindow::price() const
{
	return NULL;
}



//FUNCTIONS
void CreateModelSubWindow::reset()
{
	//set all vals to NULL
}




