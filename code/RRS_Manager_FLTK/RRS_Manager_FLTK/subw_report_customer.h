#ifndef SUBW_REPORT_CUSTOMER_H
#define SUBW_REPORT_CUSTOMER_H 2016

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

class ReportCustomerSubWindow : public Fl_Window
{
public:
	ReportCustomerSubWindow(Shop& p_shop);
	void initiliazeCustomerDropDrown();
	void reset();


protected:
	Shop& shop;

	//Formatting
	const int tb_offset = 170;

	//Widgets
	Fl_Choice* customer_dd;
	Fl_Choice* order_dd;
	Fl_Choice* model_dd;
	Fl_Button* close_btn;
	ModelTabViewer mtv;

	//GETTERS
	Customer getCustomer();
	Order getOrder();
	RobotModel getModel();

	//Functions

	//Widget Callbacks
	static void s_customer_dd_CB(Fl_Widget* w, void* p)
	{
		((ReportCustomerSubWindow*)p)->customer_dd_CB();
	}
	void customer_dd_CB();

	static void s_order_dd_CB(Fl_Widget* w, void* p)
	{
		((ReportCustomerSubWindow*)p)->order_dd_CB();
	}
	void order_dd_CB();

	static void s_model_btn_CB(Fl_Widget* w, void* p)
	{
		((ReportCustomerSubWindow*)p)->model_dd_CB();
	}
	void model_dd_CB();

	static void s_close_btn_CB(Fl_Widget* w, void* p)
	{
		((ReportCustomerSubWindow*)p)->close_btn_CB();
	}

	void close_btn_CB();
};

#endif