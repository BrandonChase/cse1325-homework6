#include "subw_report_sa.h"

#include <stdexcept>
#include <exception>

using namespace std;

//
//BASE CLASS
//

//CONSTRUCTOR
ReportSASubWindow::ReportSASubWindow(Shop& p_shop) : Fl_Window(0, MENUHEIGHT + 1, WIDTH, HEIGHT - MENUHEIGHT), shop(p_shop)
{
	//Initialize Widgets
	sa_dd = new Fl_Choice(tb_offset, 0 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Sale Assoc.: ");
	order_dd = new Fl_Choice(tb_offset, 1 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Order: ");
	model_dd = new Fl_Choice(tb_offset, 2 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Model: ");
	close_btn = new Fl_Button(210, 3 * (TB_HEIGHT + TB_SPACING), 100, 50, "Close");

	//Set Callbacks
	sa_dd->callback(s_sa_dd_CB, this);
	order_dd->callback(s_order_dd_CB, this);
	model_dd->callback(s_model_btn_CB, this);
	close_btn->callback(s_close_btn_CB, this);
}

//FUNCTIONS
void ReportSASubWindow::reset()
{
	sa_dd->clear();
	order_dd->clear();
	model_dd->clear();
}

void ReportSASubWindow::initiliazeSADropDrown()
{
	for (const SalesAssociate sa : shop.getSalesAssociates())
	{
		sa_dd->add(sa.outputFormattedString().c_str());
	}
}

//GETTERS
SalesAssociate ReportSASubWindow::getSA()
{
	int sa_index = sa_dd->value();
	if (sa_index == -1)
	{
		throw runtime_error("Sales Assoc is blank!");
	}

	vector<SalesAssociate> sas = shop.getSalesAssociates();
	return sas[sa_index];
}

Order ReportSASubWindow::getOrder()
{
	int order_index = order_dd->value();
	if (order_index == -1)
	{
		throw runtime_error("Order is blank!");
	}

	vector<Order> orders = getSA().getOrders();
	return orders[order_index];
}

RobotModel ReportSASubWindow::getModel()
{
	int model_index = model_dd->value();
	if (model_index == -1)
	{
		throw runtime_error("Model is blank!");
	}

	const RobotModel* m = &(getOrder().getRobotModels()[model_index]);
	return *m;
}

//CALLBACKS
void ReportSASubWindow::sa_dd_CB()
{
	order_dd->clear();
	vector<Order> orders = getSA().getOrders();
	for (const Order o : orders)
	{
		order_dd->add(o.outputFormattedString("",false).c_str());
	}
}

void ReportSASubWindow::order_dd_CB()
{
	model_dd->clear();
	Order o = getOrder();
	vector<RobotModel> models = o.getRobotModels();
	for (const RobotModel m : models)
	{
		model_dd->add(m.outputFormattedString("", false).c_str());
	}
}

void ReportSASubWindow::model_dd_CB()
{
	//TODO: UPDATE MODEL VIEWER
}

void ReportSASubWindow::close_btn_CB()
{
	reset();
	hide();
}