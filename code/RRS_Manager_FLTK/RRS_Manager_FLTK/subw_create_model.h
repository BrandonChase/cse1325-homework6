#ifndef SUBW_CREATE_MODEL_H
#define SUBW_CREATE_MODEL_H 2016

#include <string>
#include <vector> 

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
//#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>

#include "robot_parts.h"
#include "robot_models.h"
#include "part_type.h"
#include "shop.h"
#include "view.h"
#include "window_properties.h"

class CreateModelSubWindow : public Fl_Window
{
public:
	CreateModelSubWindow(Shop *p_shop);
	
	//Getters
	std::string name() const;
	int modelNumber() const;
	double price() const;
	int batteryCompartments() const;



private:
	Shop *shop;

	//Formatting
	const int tb_offset = 170;

	//Widgets
	Fl_Input* name_tb;
	Fl_Int_Input* model_number_tb;
	Fl_Choice* head_choice_dd;
	Fl_Choice* torso_choice_dd;
	Fl_Choice* locomotor_choice_dd;
	Fl_Choice* arm_choice_dd;
	Fl_Choice* battery_choice_dd;

	Fl_Float_Input* price_tb;
	Fl_Button* create_btn;

	Fl_Box* picture_box;


	//Functions
	void reset();

	//Widget Callbacks
	static void s_create_btn_CB(Fl_Widget* w, void* p)
	{
		((CreateModelSubWindow*)p)->create_btn_CB();
	}

	static void s_part_type_widg_CB(Fl_Widget* w, void* p)
	{
		((CreateModelSubWindow*)p)->part_type_widg_CB();
	}



	void create_btn_CB();
	void part_type_widg_CB();

};
#endif
