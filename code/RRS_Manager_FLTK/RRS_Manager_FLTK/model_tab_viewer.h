#ifndef MODEL_TAB_VIEWER_H
#define MODEL_TAB_VIEWER_H 2016

#include <string>
#include <vector> 
#include <cstdlib>
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
#include <FL/Fl_Group.H>
#include <FL/Fl_Tabs.H>
#include "robot_parts.h"
#include "robot_models.h"
#include "part_type.h"
#include "shop.h"
#include "window_properties.h"
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>

class ModelTabViewer
{
public:
	ModelTabViewer();
	void display_image(RobotModel modelin);
	void update_tb(RobotModel modelin);
	void show();
	void hide();
	void reset();



private:
	Fl_Tabs *tabs;
	Fl_Text_Display* model_tb;
	//Formatting
	const int tb_offset = 170;
	const int xoffset = 220+tb_offset, yoffset = 0, xsize = 200, ysize = 200;

	Fl_Text_Buffer* buffer;

	Fl_Box* head_picture_box;
	Fl_Box* torso_picture_box;
	Fl_Box* locomotor_picture_box;
	Fl_Box* battery_picture_box;
	Fl_Box* arm_picture_box;

	Fl_PNG_Image* head_image;
	Fl_PNG_Image* torso_image;
	Fl_PNG_Image* locomotor_image;
	Fl_PNG_Image* battery_image;
	Fl_PNG_Image* arm_image;
	
};
#endif
