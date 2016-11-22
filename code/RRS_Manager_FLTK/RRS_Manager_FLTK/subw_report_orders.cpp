#include "subw_report_orders.h"

#include <stdexcept>
#include <exception>

using namespace std;

//
//BASE CLASS
//

//CONSTRUCTOR
ReportOrderSubWindow::ReportOrderSubWindow(Shop& p_shop) : Fl_Window(0, MENUHEIGHT + 1, WIDTH, HEIGHT - MENUHEIGHT), shop(p_shop)
{
	//Initialize Widgets
	order_dd = new Fl_Choice(tb_offset, 0 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Order: ");
	model_dd = new Fl_Choice(tb_offset, 1 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Model: ");
	close_btn = new Fl_Button(210, 2 * (TB_HEIGHT + TB_SPACING), 100, 50, "Close");

	//Set Callbacks
	order_dd->callback(s_order_dd_CB, this);
	model_dd->callback(s_model_btn_CB, this);
	close_btn->callback(s_close_btn_CB, this);
}

//FUNCTIONS
void ReportOrderSubWindow::reset()
{
	order_dd->clear();
	model_dd->clear();
	mtv.reset();
}

void ReportOrderSubWindow::initiliazeOrderDropDrown()
{
	for (const Order o : shop.getOrders())
	{
		order_dd->add(o.outputFormattedString("", false).c_str());
	}
}

//GETTERS
Order ReportOrderSubWindow::getOrder()
{
	int order_index = order_dd->value();
	if (order_index == -1)
	{
		throw runtime_error("Order is blank!");
	}

	vector<Order> orders = shop.getOrders();
	return orders[order_index];
}

RobotModel ReportOrderSubWindow::getModel()
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
void ReportOrderSubWindow::order_dd_CB()
{
	model_dd->clear();
	Order o = getOrder();
	vector<RobotModel> models = o.getRobotModels();
	for (const RobotModel m : models)
	{
		model_dd->add(m.outputFormattedString("", false).c_str());
	}
}

void ReportOrderSubWindow::model_dd_CB()
{
	mtv.show();
	mtv.display_image(getModel());
	mtv.update_tb(getModel());
}

void ReportOrderSubWindow::close_btn_CB()
{
	reset();
	hide();
}