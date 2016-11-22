#ifndef SUBW_REPORT_ORDERS_H
#define SUBW_REPORT_ORDERS_H 2016

#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>

#include "order.h"
#include "shop.h"
#include "window_properties.h"
#include "model_tab_viewer.h"

class ReportOrderSubWindow : public Fl_Window
{
public:
	ReportOrderSubWindow(Shop& p_shop);
	void initiliazeOrderDropDrown();
	void reset();


private:
	Shop& shop;

	//Formatting
	const int tb_offset = 170;

	//Widgets
	Fl_Choice* order_dd;
	Fl_Choice* model_dd;
	Fl_Button* close_btn;
	ModelTabViewer mtv;

	//GETTERS
	Order getOrder();
	RobotModel getModel();

	//Functions

	//Widget Callbacks
	static void s_order_dd_CB(Fl_Widget* w, void* p)
	{
		((ReportOrderSubWindow*)p)->order_dd_CB();
	}
	void order_dd_CB();

	static void s_model_btn_CB(Fl_Widget* w, void* p)
	{
		((ReportOrderSubWindow*)p)->model_dd_CB();
	}
	void model_dd_CB();

	static void s_close_btn_CB(Fl_Widget* w, void* p)
	{
		((ReportOrderSubWindow*)p)->close_btn_CB();
	}

	void close_btn_CB();
};

#endif
