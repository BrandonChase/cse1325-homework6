#ifndef SUBWINDOWS_H
#define SUBWINDOWS_H 2016

#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
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
#include "part_type.h"
#include "shop.h"
#include "window_properties.h"

class CreatePartSubWindow : public Fl_Window
{
public:
	CreatePartSubWindow(Shop& p_shop);
	
	//Getters
	PartType partType() const;
	std::string name() const;
	int partNumber() const;
	double weight() const;
	double price() const;
	std::string description() const;
	int batteryCompartments() const;
	double powerConsumed() const;
	double maxSpeed() const;
	double containedEnergy() const;
	std::string imageFileName() const;


private:
	Shop& shop;

	//Formatting
	const int tb_offset = 170;

	//Widgets
	Fl_Choice* part_type_dd;
	Fl_Input* name_tb;
	Fl_Int_Input* part_number_tb;
	Fl_Float_Input* weight_tb;
	Fl_Float_Input* price_tb;
	Fl_Input* description_tb;
	Fl_Int_Input* battery_compartments_tb;
	Fl_Float_Input* power_consumed_tb;
	Fl_Float_Input* max_speed_tb;
	Fl_Float_Input* contained_energy_tb;
	Fl_Button* create_btn;
	Fl_Button* choose_image_btn;
	Fl_Box* picture_box;
	std::string image_filename;
	Fl_PNG_Image* part_image;

	//Functions
	void reset();

	//Widget Callbacks
	static void s_create_btn_CB(Fl_Widget* w, void* p)
	{
		((CreatePartSubWindow*)p)->create_btn_CB();
	}

	static void s_part_type_widg_CB(Fl_Widget* w, void* p)
	{
		((CreatePartSubWindow*)p)->part_type_widg_CB();
	}

	static void s_choose_image_btn_CB(Fl_Widget* w, void* p)
	{
		((CreatePartSubWindow*)p)->choose_image_btn_CB();
	}

	void create_btn_CB();
	void part_type_widg_CB();
	void choose_image_btn_CB();
};
#endif
