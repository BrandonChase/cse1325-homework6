#ifndef SUBW_CREATE_ORDER_H
#define SUBW_CREATE_ORDER_H 2016

#include <string>
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>

#include "customer.h"
#include "sales_associate.h"
#include "shop.h"
#include "window_properties.h"
#include "robot_models.h"
#include "date.h"

class CreateOrderSubWindow : public Fl_Window
{
public:
	CreateOrderSubWindow(Shop& p_shop);

	//Getters
	SalesAssociate getSalesAssoc();
	Customer getCustomer();
	RobotModel getChosenModel();
	int getDateMonth();
	int getDateDay();
	int getDateYear();

	void initializeDropDowns();

private:
	Shop& shop;
	std::vector<RobotModel> chosen_models;

	//Formatting
	const int tb_offset = 170;

	//Widgets
	Fl_Int_Input* date_month;
	Fl_Int_Input* date_day;
	Fl_Int_Input* date_year;
	Fl_Choice* sales_assoc_dd;
	Fl_Choice* customer_dd;
	Fl_Choice* available_models_dd;
	Fl_Text_Display* chosen_models_tb;
	Fl_Text_Buffer* buffer;
	Fl_Button* create_btn;
	Fl_Button* add_model_btn;
	Fl_Button* close_btn;

	//Functions
	void reset();

	//Widget Callbacks
	static void s_create_btn_CB(Fl_Widget* w, void* p)
	{
		((CreateOrderSubWindow*)p)->create_btn_CB();
	}

	void create_btn_CB();

	static void s_add_model_btn_CB(Fl_Widget* w, void* p)
	{
		((CreateOrderSubWindow*)p)->add_model_btn_CB();
	}

	void add_model_btn_CB();

	static void s_close_btn_CB(Fl_Widget* w, void* p)
	{
		((CreateOrderSubWindow*)p)->close_btn_CB();
	}

	void close_btn_CB();
};

#endif