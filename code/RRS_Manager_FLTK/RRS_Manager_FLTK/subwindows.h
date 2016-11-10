#ifndef SUBWINDOWS_H
#define SUBWINDOWS_H 2016

#define HEIGHT 480
#define WIDTH 640
#define BORDER 10
#define MENUHEIGHT 30

#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>

#include "robot_parts.h"
#include "part_type.h"

class CreatePartSubWindow : public Fl_Window
{
public:
	CreatePartSubWindow();
	
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
	Fl_Button* create_button();


private:
	//Formatting
	const int tb_offset = 170;
	const int tb_width = 200;
	const int tb_height = 30;
	const int tb_spacing = 10;

	//Widgets
	Fl_Choice *part_type_widg = new Fl_Choice(tb_offset, 0, tb_width, tb_height, "Part Type: ");
	Fl_Input *name_widg = new Fl_Input(tb_offset, 1 * (tb_height + tb_spacing), tb_width, tb_height, "Name: ");
	Fl_Int_Input *part_number_widg = new Fl_Int_Input(tb_offset, 2 * (tb_height + tb_spacing), tb_width, tb_height, "Part Number: ");
	Fl_Float_Input *weight_widg = new Fl_Float_Input(tb_offset, 3 * (tb_height + tb_spacing), tb_width, tb_height, "Weight [lb]: ");
	Fl_Float_Input *price_widg = new Fl_Float_Input(tb_offset, 4 * (tb_height + tb_spacing), tb_width, tb_height, "Price [$]: ");
	Fl_Input *description_widg = new Fl_Input(tb_offset, 5 * (tb_height + tb_spacing), tb_width, tb_height, "Description: ");
	Fl_Int_Input *battery_compartments_widg = new Fl_Int_Input(tb_offset, 6 * (tb_height + tb_spacing), tb_width, tb_height, "Battery Compartments: ");
	Fl_Float_Input *power_consumed_widg = new Fl_Float_Input(tb_offset, 6 * (tb_height + tb_spacing), tb_width, tb_height, "Power Consumed [W]: ");
	Fl_Float_Input *max_speed_widg = new Fl_Float_Input(tb_offset, 7 * (tb_height + tb_spacing), tb_width, tb_height, "Max Speed [MPH]: ");
	Fl_Float_Input *contained_energy_widg = new Fl_Float_Input(tb_offset, 6 * (tb_height + tb_spacing), tb_width, tb_height, "Contained Energy [kWh]: ");
	Fl_Button *create_widg = new Fl_Button(210, 10 * (tb_height + tb_spacing), 100, 50, "Create Part");
	Fl_Button *choose_image_btn = new Fl_Button(475, 0, 100, 50, "Choose Image");
	Fl_Box *picture_box = new Fl_Box(425, 100, 200, 200);
	std::string image_filename;

	//Widget Callbacks
	static void create_btn_CB(Fl_Widget* w, void* p)
	{
		((CreatePartSubWindow*)p)->create_btn_CB();
	}

	static void part_type_widg_CB(Fl_Widget* w, void* p)
	{
		((CreatePartSubWindow*)p)->part_type_widg_CB();
	}

	static void choose_image_btn_CB(Fl_Widget* w, void* p)
	{
		((CreatePartSubWindow*)p)->choose_image_btn_CB();
	}

	void create_btn_CB();
	void part_type_widg_CB();
	void choose_image_btn_CB();
};
#endif
