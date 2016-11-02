#include "fltk_controller.h"
#include <FL/Fl_Menu_Bar.H>

#include "shop.h"
#include "view.h"
#include "easy_input.h"
#include <iostream>

using namespace std;

int FLTKController::GUI()
{
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
	const int x =640;
	const int y = 480;
	const int border =10;
	//fl_register_images();
	Fl_Window *win= new Fl_Window{x+3*border, y+3*border, "Robbie Robot Shop v0.15"};
	Fl_Box *box = new Fl_Box{border, border, x+border, y+border};
	Fl_Menu_Bar *menubar;
	//View *view;


	menubar = new Fl_Menu_Bar(0,0,x+3*border,30);
	menubar->menu(menuitems);

	//win->resizable(box);
	win->end();
	win->show();
	return(Fl::run());
}