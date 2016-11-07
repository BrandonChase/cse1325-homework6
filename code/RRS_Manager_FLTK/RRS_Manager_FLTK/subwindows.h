#ifndef SUBWINDOWS_H
#define SUBWINDOWS_H 2016

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

#include "fltk_controller.h"

class CreatePartWindowFolder
{
public:
	CreatePartWindowFolder(FLTKController& p_controller);
	Fl_Window *create_part_win = new Fl_Window(0, MENUHEIGHT + 1, WIDTH, HEIGHT - MENUHEIGHT);

private:
	//Formatting
	const int tb_offset = 170;
	const int tb_width = 200;
	const int tb_height = 30;
	const int tb_spacing = 10;

	FLTKController& controller;

	//Widgets
	Fl_Choice *part_type_widg = new Fl_Choice(tb_offset, 0, tb_width, tb_height, "Part Type: ");
	Fl_Input *name_widg = new Fl_Input(tb_offset, 1 * (tb_height + tb_spacing), tb_width, tb_height, "Name: ");
	Fl_Int_Input *part_number_widg = new Fl_Int_Input(tb_offset, 2 * (tb_height + tb_spacing), tb_width, tb_height, "Part Number: ");
	Fl_Float_Input *weight_widg = new Fl_Float_Input(tb_offset, 3 * (tb_height + tb_spacing), tb_width, tb_height, "Weight [lb]: ");
	Fl_Float_Input *price_widg = new Fl_Float_Input(tb_offset, 4 * (tb_height + tb_spacing), tb_width, tb_height, "Price [$]: ");
	Fl_Input *description_widg = new Fl_Input(tb_offset, 5 * (tb_height + tb_spacing), tb_width, tb_height, "Description: ");
	Fl_Int_Input *battery_compartments_widg = new Fl_Int_Input(tb_offset, 6 * (tb_height + tb_spacing), tb_width, tb_height, "Battery Compartments: ");
	Fl_Float_Input *power_consumed_widg = new Fl_Float_Input(tb_offset, 7 * (tb_height + tb_spacing), tb_width, tb_height, "Power Consumed [W]: ");
	Fl_Float_Input *max_speed_widg = new Fl_Float_Input(tb_offset, 8 * (tb_height + tb_spacing), tb_width, tb_height, "Max Speed [MPH]: ");
	Fl_Float_Input *contained_energy_widg = new Fl_Float_Input(tb_offset, 9 * (tb_height + tb_spacing), tb_width, tb_height, "Contained Energy [kWh]: ");
	Fl_Button *create_widg = new Fl_Button(210, 10 * (tb_height + tb_spacing), 100, 50, "Create Part");
	Fl_Button *choose_image_btn = new Fl_Button(475, 0, 100, 50, "Choose Image");
	Fl_Box *picture_box = new Fl_Box(425, 100, 200, 200);
	Fl_PNG_Image *image;

	//Widget Callbacks
	static void create_btn_CB(Fl_Widget* w, void* p)
	{
		((CreatePartWindowFolder*)p)->create_btn_CB();
	}

	static void part_type_widg_CB(Fl_Widget* w, void* p)
	{
		((CreatePartWindowFolder*)p)->part_type_widg_CB();
	}

	static void choose_image_btn_CB(Fl_Widget* w, void* p)
	{
		((CreatePartWindowFolder*)p)->choose_image_btn_CB();
	}

	void create_btn_CB();
	void part_type_widg_CB();
	void choose_image_btn_CB();
};
#endif
