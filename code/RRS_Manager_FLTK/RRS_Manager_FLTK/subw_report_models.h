#ifndef SUBW_REPORT_MODELS_H
#define SUBW_REPORT_MODELS_H 2016

#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>

#include "customer.h"
#include "sales_associate.h"
#include "order.h"
#include "shop.h"
#include "window_properties.h"
#include "model_tab_viewer.h"

class ReportModelSubWindow : public Fl_Window
{
public:
	ReportModelSubWindow(Shop& p_shop);
	void initiliazeModelDropDrown();
	void reset();

protected:
	Shop& shop;

	//Formatting
	const int tb_offset = 170;

	//Widgets
	Fl_Choice* model_dd;
	Fl_Button* close_btn;
	ModelTabViewer mtv;

	//GETTERS
	RobotModel getModel();

	//Functions

	//Widget Callbacks
	static void s_model_btn_CB(Fl_Widget* w, void* p)
	{
		((ReportModelSubWindow*)p)->model_dd_CB();
	}
	void model_dd_CB();

	static void s_close_btn_CB(Fl_Widget* w, void* p)
	{
		((ReportModelSubWindow*)p)->close_btn_CB();
	}

	void close_btn_CB();
};

#endif