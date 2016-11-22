#ifndef SUBW_CREATE_CUSTOMER_SA
#define SUBW_CREATE_CUSTOMER_SA 2016

#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "customer.h"
#include "sales_associate.h"
#include "shop.h"
#include "window_properties.h"

class CreatePersonSubWindow : public Fl_Window
{
public:
	CreatePersonSubWindow(Shop& p_shop);
	std::string getName() const;
	virtual int getNumber() const = 0;
	void reset();

protected:
	Shop& shop;

	//Formatting
	const int tb_offset = 170;

	//Widgets
	Fl_Input* name_tb;
	Fl_Int_Input* number_tb;
	Fl_Button* create_btn;

	//Functions


	//Widget Callbacks
	static void s_create_btn_CB(Fl_Widget* w, void* p)
	{
		((CreatePersonSubWindow*)p)->create_btn_CB();
	}

	virtual void create_btn_CB() = 0;
};

class CreateCustomerSubWindow : public CreatePersonSubWindow
{
public:
	CreateCustomerSubWindow(Shop& p_shop);
	int getNumber() const override;

private:
	void create_btn_CB() override;
};

class CreateSASubWindow : public CreatePersonSubWindow
{
public:
	CreateSASubWindow(Shop& p_shop);
	int getNumber() const override;

private:
	void create_btn_CB() override;
};

#endif
