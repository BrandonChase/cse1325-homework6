#include "fltk_controller.h"
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Button.H>

#include "shop.h"
#include "view.h"
#include "easy_input.h"
#include <iostream>

using namespace std;

struct CreatePartWindowFolder
{
	//tb = text box
	const int tb_offset = 30;
	const int tb_width = 50;
	const int tb_height = 30;
	const int tb_spacing = 10;

	CreatePartWindowFolder()
	{
		create_btn->callback(create_btn_CB, this);
	}

	Fl_Window *create_part_win = new Fl_Window(0, MENUHEIGHT + 1, WIDTH, HEIGHT - MENUHEIGHT - BORDER);
	Fl_Input *name_itb = new Fl_Input(tb_offset, 0, tb_width, tb_height, "Name: ");
	Fl_Button *create_btn = new Fl_Button(0, 200, 50, 50, "Create");
	static void create_btn_CB(Fl_Widget* w, void* p)
	{	
		((CreatePartWindowFolder*)p)->create_btn_CB();
	}

	void create_btn_CB()
	{
		create_part_win->hide();
	}
};

int FLTKController::GUI()
{
	CreatePartWindowFolder cpwinfolder;
	Fl_Menu_Item menuitems[] = {
		{"&File", 0, 0, 0, FL_SUBMENU },
			{"&New", FL_ALT + 'n', 0},
			{"&Open", FL_ALT + 'o', 0},
			{"&Save", FL_ALT + 's', 0},
			{"Save As", FL_ALT + FL_SHIFT + 's', 0},
			{"Save Default", FL_ALT + FL_SHIFT + 'd', 0},
			{"&Quit", FL_ALT + 'q', 0},
			{0},
		{"&Edit", 0, 0, 0, FL_SUBMENU },
			{"&Undo", 0, 0},
			{"Cu&t", 0, 0},
			{"&Copy", 0, 0},
			{"&Paste", 0, 0},
			{0},
		{"&Create", 0, 0, 0, FL_SUBMENU },
			{"Order", 0, 0, 0},
			{"Customer", 0, 0, 0},
			{"Sales Associate", 0, 0, 0},
			{"Robot Part", 0, 0, 0},
			{"Robot Model", 0, 0, 0},
			{0},
		{"&Report", 0, 0, 0, FL_SUBMENU },
			{"Invoice", 0, 0, 0},
			{"All Orders", 0, 0, 0},
			{"Orders by Customer", 0, 0, 0},
			{"Orders by Sales Associate", 0, 0, 0},
			{"All Customers", 0, 0, 0},
			{"All Sales Associates", 0, 0, 0},
			{"All Robot Models", 0, 0, 0},
			{"All Robot Parts", 0, 0, 0},
			{0},
		{"&Help", 0, 0, 0, FL_SUBMENU },
			{"&Manual", 0, 0, 0},
			{"&About", 0, 0, 0},
			{0},
		{0}
	};
	//fl_register_images();
	Fl_Window *win= new Fl_Window{WIDTH+3*BORDER, WIDTH+3*BORDER, "Robbie Robot Shop v0.15"};
	Fl_Box *box = new Fl_Box{BORDER, BORDER, WIDTH+BORDER, HEIGHT+BORDER};
	Fl_Menu_Bar *menubar;
	//View *view;


	menubar = new Fl_Menu_Bar(0,0,WIDTH+3*BORDER, MENUHEIGHT);
	menubar->menu(menuitems);
	//win->resizable(box);
	win->end();
	win->add(cpwinfolder.create_part_win);
	win->show();
	return(Fl::run());
}