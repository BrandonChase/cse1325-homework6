#include "subw_report_customer.h"

#include <stdexcept>
#include <exception>

using namespace std;

//
//BASE CLASS
//

//CONSTRUCTOR
ReportCustomerSubWindow::ReportCustomerSubWindow(Shop& p_shop) : Fl_Window(0, MENUHEIGHT + 1, WIDTH, HEIGHT - MENUHEIGHT), shop(p_shop)
{
	//Initialize Widgets
	customer_dd = new Fl_Choice(tb_offset, 0 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Customer: ");
	order_dd = new Fl_Choice(tb_offset, 1 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Order: ");
	model_dd = new Fl_Choice(tb_offset, 2 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Model: ");
	close_btn = new Fl_Button(210, 3 * (TB_HEIGHT + TB_SPACING), 100, 50, "Close");

	//Set Callbacks
	customer_dd->callback(s_customer_dd_CB, this);
	order_dd->callback(s_order_dd_CB, this);
	model_dd->callback(s_model_btn_CB, this);
	close_btn->callback(s_close_btn_CB, this);
}

//FUNCTIONS
void ReportCustomerSubWindow::reset()
{
	customer_dd->clear();
	order_dd->clear();
	model_dd->clear();
	mtv.reset();
}

void ReportCustomerSubWindow::initiliazeCustomerDropDrown()
{
	for (const Customer c : shop.getCustomers())
	{
		customer_dd->add(c.outputFormattedString().c_str());
	}
}

//GETTERS
Customer ReportCustomerSubWindow::getCustomer()
{
	int customer_index = customer_dd->value();
	if (customer_index == -1)
	{
		throw runtime_error("Customer is blank!");
	}

	vector<Customer> customers = shop.getCustomers();
	return customers[customer_index];
}

Order ReportCustomerSubWindow::getOrder()
{
	int order_index = order_dd->value();
	if (order_index == -1)
	{
		throw runtime_error("Order is blank!");
	}

	vector<Order> orders = getCustomer().getOrders();
	return orders[order_index];
}

RobotModel ReportCustomerSubWindow::getModel()
{
	int model_index = model_dd->value();
	if (model_index == -1)
	{
		throw runtime_error("Model is blank!");
	}

	vector<RobotModel> models = getOrder().getRobotModels();
	return models[model_index];
}

//CALLBACKS
void ReportCustomerSubWindow::customer_dd_CB()
{
	order_dd->clear();
	order_dd->value(-1);
	model_dd->clear();
	model_dd->value(-1);
	vector<Order> orders = getCustomer().getOrders();
	for (const Order o : orders)
	{
		order_dd->add(o.outputFormattedString("", false).c_str());
	}
	redraw();
}

void ReportCustomerSubWindow::order_dd_CB()
{
	model_dd->clear();
	model_dd->value(-1);
	Order o = getOrder();
	vector<RobotModel> models = o.getRobotModels();
	for (const RobotModel m : models)
	{
		model_dd->add(m.outputFormattedString("", false).c_str());
	}
	redraw();
}

void ReportCustomerSubWindow::model_dd_CB()
{
	mtv.show();
	mtv.display_image(getModel());
	mtv.update_tb(getModel());
}

void ReportCustomerSubWindow::close_btn_CB()
{
	reset();
	hide();
}