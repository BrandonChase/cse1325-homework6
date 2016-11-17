#include "subw_create_order.h"

#include <stdexcept>
#include <exception>

using namespace std;

//CONSTRUCTOR
CreateOrderSubWindow::CreateOrderSubWindow(Shop& p_shop) : Fl_Window(0, MENUHEIGHT + 1, WIDTH, HEIGHT - MENUHEIGHT), shop(p_shop)
{
	//Initialize Widgets
	date_month = new Fl_Int_Input(tb_offset + 0 * (TB_WIDTH+10), 0, 25, TB_HEIGHT, "Date: ");
	date_day = new Fl_Int_Input(tb_offset + 1 * (25 + 20), 0, 25, TB_HEIGHT, "/ ");
	date_year = new Fl_Int_Input(tb_offset + 2 * (25 + 20), 0, 50, TB_HEIGHT, "/ ");
	sales_assoc_dd = new Fl_Choice(tb_offset, 1 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Sales Assoc: ");
	customer_dd = new Fl_Choice(tb_offset, 2 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Customer: ");
	available_models_dd = new Fl_Choice(tb_offset, 3 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Model to Add: ");
	chosen_models_dd = new Fl_Choice(tb_offset, 4 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Added Models: ");
	add_model_btn = new Fl_Button(100, 5 * (TB_HEIGHT + TB_SPACING), 100, 50, "Add Model");
	create_btn = new Fl_Button(100, 6 * (TB_HEIGHT + TB_SPACING), 100, 50, "Create Order");
	close_btn = new Fl_Button(150, 7 * (TB_HEIGHT + TB_SPACING), 100, 50, "Finish Later");


	//Initialize Drop Down
	initializeDropDowns();

	chosen_models_dd->deactivate();

	//Set Callbacks
	add_model_btn->callback(s_add_model_btn_CB, this);
	create_btn->callback(s_create_btn_CB, this);
}

//GETTERS
SalesAssociate CreateOrderSubWindow::getSalesAssoc()
{
	
	int sa_index = sales_assoc_dd->value();
	if (sa_index == -1)
	{
		throw runtime_error("Sales Assoc is blank!");
	}

	const SalesAssociate* sa = &(shop.getSalesAssociates()[sa_index]);
	return *sa;
}

Customer CreateOrderSubWindow::getCustomer()
{
	int customer_index = customer_dd->value();
	if (customer_index == -1)
	{
		throw runtime_error("Customer is blank!");
	}

	const Customer* c = &(shop.getCustomers()[customer_index]);
	return *c;
}

RobotModel CreateOrderSubWindow::getChosenModel()
{
	int model_index = available_models_dd->value();
	if (model_index == -1)
	{
		throw runtime_error("Model to Add is blank!");
	}

	const RobotModel* m = &(shop.getModels()[model_index]);
	return *m;
}

int CreateOrderSubWindow::getDateMonth()
{
	int month = stoi(date_month->value());
	if (month < 1 || month > 12)
	{
		throw runtime_error("Invalid month!");
	}
	return month;
}

int CreateOrderSubWindow::getDateDay()
{
	int day = stoi(date_day->value());
	if (day < 1 || day > 31)
	{
		throw runtime_error("Invalid day!");
	}
	return day;
}

int CreateOrderSubWindow::getDateYear()
{
	int year = stoi(date_year->value());
	if (year < 1970)
	{
		throw runtime_error("Invalid year! Must be greater than 1970!");
	}
	return year;
}

//FUNCTIONS
void CreateOrderSubWindow::reset()
{
	date_month->value("");
	date_day->value("");
	date_year->value("");
	sales_assoc_dd->clear();
	customer_dd->clear();
	available_models_dd->clear();
	chosen_models_dd->clear();
	chosen_models.clear(); //empty vector containing chosen robot models
}

void CreateOrderSubWindow::initializeDropDowns()
{
	for (const SalesAssociate sa : shop.getSalesAssociates())
	{
		sales_assoc_dd->add(sa.outputFormattedString().c_str());
	}

	for (const Customer c : shop.getCustomers())
	{
		customer_dd->add(c.outputFormattedString().c_str());
	}

	for (const RobotModel m : shop.getModels())
	{
		available_models_dd->add(m.outputFormattedString("", false).c_str()); //don't show details
	}
}

//CALLBACKS
void CreateOrderSubWindow::add_model_btn_CB()
{
	try
	{
		RobotModel model = getChosenModel();
		chosen_models.push_back(model);
		chosen_models_dd->add(model.outputFormattedString("", false).c_str());
	}
	catch (const exception& e)
	{
		Fl::error(e.what());
	}
}

void CreateOrderSubWindow::create_btn_CB()
{
	try
	{
		shop.addOrder(Order(0, getCustomer().getCustomerNumber(), getSalesAssoc().getSalesAssociateNumber(), chosen_models, 0,
			Date(getDateMonth(), getDateDay(), getDateYear())), getCustomer().getCustomerNumber(), getSalesAssoc().getSalesAssociateNumber());
	}
	catch (const exception& e)
	{
		Fl::error(e.what());
	}

	reset();
	hide();
}

void CreateOrderSubWindow::close_btn_CB()
{
	hide();
}