#ifndef SUBW_REPORT_SA_H
#define SUBW_REPORT_SA_H 2016

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

class ReportSASubWindow : public Fl_Window
{
public:
	ReportSASubWindow(Shop& p_shop);
	void initiliazeSADropDrown();
	void reset();


protected:
	Shop& shop;

	//Formatting
	const int tb_offset = 170;

	//Widgets
	Fl_Choice* sa_dd;
	Fl_Choice* order_dd;
	Fl_Choice* model_dd;
	Fl_Button* close_btn;

	//GETTERS
	SalesAssociate getSA();
	Order getOrder();
	RobotModel getModel();

	//Functions

	//Widget Callbacks
	static void s_sa_dd_CB(Fl_Widget* w, void* p)
	{
		((ReportSASubWindow*)p)->sa_dd_CB();
	}
	void sa_dd_CB();

	static void s_order_dd_CB(Fl_Widget* w, void* p)
	{
		((ReportSASubWindow*)p)->order_dd_CB();
	}
	void order_dd_CB();

	static void s_model_btn_CB(Fl_Widget* w, void* p)
	{
		((ReportSASubWindow*)p)->model_dd_CB();
	}
	void model_dd_CB();

	static void s_close_btn_CB(Fl_Widget* w, void* p)
	{
		((ReportSASubWindow*)p)->close_btn_CB();
	}

	void close_btn_CB();
};

#endif