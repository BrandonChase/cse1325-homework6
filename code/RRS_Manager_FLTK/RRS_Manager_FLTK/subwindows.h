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
	Fl_Choice* part_type_dd = new Fl_Choice(tb_offset, 0, TB_WIDTH, TB_HEIGHT, "Part Type: ");
	Fl_Input* name_tb = new Fl_Input(tb_offset, 1 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Name: ");
	Fl_Int_Input* part_number_tb = new Fl_Int_Input(tb_offset, 2 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Part Number: ");
	Fl_Float_Input* weight_tb = new Fl_Float_Input(tb_offset, 3 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Weight [lb]: ");
	Fl_Float_Input* price_tb = new Fl_Float_Input(tb_offset, 4 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Price [$]: ");
	Fl_Input* description_tb = new Fl_Input(tb_offset, 5 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Description: ");
	Fl_Int_Input* battery_compartments_tb = new Fl_Int_Input(tb_offset, 6 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Battery Compartments: ");
	Fl_Float_Input* power_consumed_tb = new Fl_Float_Input(tb_offset, 6 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Power Consumed [W]: ");
	Fl_Float_Input* max_speed_tb = new Fl_Float_Input(tb_offset, 7 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Max Speed [MPH]: ");
	Fl_Float_Input* contained_energy_tb = new Fl_Float_Input(tb_offset, 6 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Contained Energy [kWh]: ");
	Fl_Button* create_btn = new Fl_Button(210, 10 * (TB_HEIGHT + TB_SPACING), 100, 50, "Create Part");
	Fl_Button* choose_image_btn = new Fl_Button(475, 0, 100, 50, "Choose Image");
	Fl_Box* picture_box = new Fl_Box(425, 100, 200, 200);
	std::string image_filename;
	Fl_PNG_Image* part_image;

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
