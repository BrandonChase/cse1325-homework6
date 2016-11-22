#include "model_tab_viewer.h"

#include <FL/Fl_File_Chooser.H>
#include <stdexcept>
#include <exception>
#include <string>

using namespace std;

ModelTabViewer::ModelTabViewer()
{
	tabs = new Fl_Tabs(xoffset,yoffset,xsize+50,ysize+150);
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

	tabs->redraw();
}

void ModelTabViewer::display_image(RobotModel modelin)
{
	string imagefilename = (modelin.gethead().getImageLocation().c_str());
	cout << imagefilename;
	head_image = new Fl_PNG_Image(imagefilename.c_str());
	head_picture_box->image(head_image);
	head_picture_box->show();

	torso_image = new Fl_PNG_Image(modelin.gettorso().getImageLocation().c_str());
	torso_picture_box->image(torso_image);
	torso_picture_box->show();

	locomotor_image = new Fl_PNG_Image(modelin.getlocomotor().getImageLocation().c_str());
	locomotor_picture_box->image(locomotor_image);
	locomotor_picture_box->show();

	battery_image = new Fl_PNG_Image(modelin.getbattery().getImageLocation().c_str());
	battery_picture_box->image(battery_image);
	battery_picture_box->show();

	arm_image = new Fl_PNG_Image(modelin.getarm().getImageLocation().c_str());
	arm_picture_box->image(arm_image);
	arm_picture_box->show();

	tabs->redraw();
}
