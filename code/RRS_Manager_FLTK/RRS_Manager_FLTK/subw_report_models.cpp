#include "subw_report_models.h"

#include <stdexcept>
#include <exception>

using namespace std;

//
//BASE CLASS
//

//CONSTRUCTOR
ReportModelSubWindow::ReportModelSubWindow(Shop& p_shop) : Fl_Window(0, MENUHEIGHT + 1, WIDTH, HEIGHT - MENUHEIGHT), shop(p_shop)
{
	//Initialize Widgets
	model_dd = new Fl_Choice(tb_offset, 0 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Model: ");
	close_btn = new Fl_Button(210, 1 * (TB_HEIGHT + TB_SPACING), 100, 50, "Close");

	//Set Callbacks
	model_dd->callback(s_model_btn_CB, this);
	close_btn->callback(s_close_btn_CB, this);
}

//FUNCTIONS
void ReportModelSubWindow::reset()
{
	model_dd->clear();
}

void ReportModelSubWindow::initiliazeModelDropDrown()
{
	for (const RobotModel m : shop.getModels())
	{
		model_dd->add(m.outputFormattedString("", false).c_str());
	}
}

//GETTERS
RobotModel ReportModelSubWindow::getModel()
{
	int model_index = model_dd->value();
	if (model_index == -1)
	{
		throw runtime_error("Model is blank!");
	}

	vector<RobotModel> models = shop.getModels();
	return models[model_index];
}

//CALLBACKS
void ReportModelSubWindow::model_dd_CB()
{
	//TODO: UPDATE MODEL VIEWER
}

void ReportModelSubWindow::close_btn_CB()
{
	reset();
	hide();
}