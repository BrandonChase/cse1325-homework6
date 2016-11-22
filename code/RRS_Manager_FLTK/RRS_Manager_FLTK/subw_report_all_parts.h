#ifndef SUBW_REPORT_ALL_PARTS_H 
#define SUBW_REPORT_ALL_PARTS_H 2016

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>

#include "shop.h"
#include "part_type.h"
#include "robot_parts.h"
#include "window_properties.h"
#include "robot_part_dropdown.h"

class ReportPartsSubWindow : public Fl_Window
{
public:
	//Constructor
	ReportPartsSubWindow(Shop& p_shop);

	//Getters
	PartType getPartType();
	const RobotPart* getRobotPart();
	void reset();

private:
	Shop& shop;

	//Misc. Functions

	//Formatting
	const int tb_offset = 170;

	//Widgets
	RobotPartDropDown* part_type_dd;
	Fl_Choice* part_dd;
	Fl_Box* picture_box;
	Fl_PNG_Image* part_image;
	Fl_Text_Display* part_info_tb;
	Fl_Text_Buffer* buffer;
	Fl_Button* close_btn;

	//Callbacks
	static void s_part_type_dd_CB(Fl_Widget* w, void* p)
	{
		((ReportPartsSubWindow*)p)->part_type_dd_CB();
	}
	void part_type_dd_CB();

	static void s_part_dd_CB(Fl_Widget* w, void* p)
	{
		((ReportPartsSubWindow*)p)->part_dd_CB();
	}
	void part_dd_CB();

	static void s_close_btn_CB(Fl_Widget* w, void* p)
	{
		((ReportPartsSubWindow*)p)->close_btn_CB();
	}
	void close_btn_CB();
};

#endif