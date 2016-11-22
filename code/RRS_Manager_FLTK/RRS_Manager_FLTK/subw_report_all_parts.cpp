#include "subw_report_all_parts.h"

#include <stdexcept>
#include <exception>
#include <string>

using namespace std;

//Constructor
ReportPartsSubWindow::ReportPartsSubWindow(Shop& p_shop) : Fl_Window(0, MENUHEIGHT + 1, WIDTH, HEIGHT - MENUHEIGHT), shop(p_shop)
{
	//Initialize Widgets
	part_type_dd = new RobotPartDropDown(tb_offset, 0, TB_WIDTH, TB_HEIGHT);
	part_dd = new Fl_Choice(tb_offset, 1 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Parts: ");
	picture_box = new Fl_Box(425, 25, 200, 200);
	part_info_tb = new Fl_Text_Display(300, 25+200+20, 410, 120, "Info: ");
	buffer = new Fl_Text_Buffer();
	close_btn = new Fl_Button(210, 2 * (TB_HEIGHT + TB_SPACING), 100, 50, "Close");

	//Initialize Drop Down
	part_type_dd->setItems();

	picture_box->hide();
	part_dd->hide();
	part_info_tb->hide();

	//Set Callbacks
	part_type_dd->callback(s_part_type_dd_CB, this);
	part_dd->callback(s_part_dd_CB, this);
	close_btn->callback(s_close_btn_CB, this);
}

//GETTERS
PartType ReportPartsSubWindow::getPartType()
{
	return part_type_dd->getValue();
}

const RobotPart* ReportPartsSubWindow::getRobotPart()
{
	PartType part_type = getPartType();
	int part_index = part_dd->value();
	const RobotPart* part = NULL;
	if (part_index == -1)
	{
		throw runtime_error("Part choice is empty!");
	}

	else if (part_type == PartType::HEAD)
	{ 
		const Head* h = &(shop.getHeads()[part_index]);
		part = h;
	}

	else if (part_type == PartType::TORSO)
	{
		const Torso* t = &(shop.getTorsos()[part_index]);
		part = t;
	}

	else if (part_type == PartType::BATTERY)
	{
		const Battery* b = &(shop.getBatteries()[part_index]);
		part = b;
	}

	else if (part_type == PartType::ARM)
	{
		const Arm* a = &(shop.getArms()[part_index]);
		part = a;
	}

	else if (part_type == PartType::LOCOMOTOR)
	{
		const Locomotor* l = &(shop.getLocomotors()[part_index]);
		part = l;
	}

	return part;
}

//CALLBACKS
void ReportPartsSubWindow::part_type_dd_CB()
{
	part_dd->clear();
	redraw();
	PartType part_type = getPartType();

	if (part_type == PartType::HEAD)
	{
		part_dd->label("Heads: ");

		for(Head h : shop.getHeads())
		{
			part_dd->add(h.getName().c_str());
		}
	}

	else if (part_type == PartType::TORSO)
	{
		part_dd->label("Torsos: ");

		for (Torso t : shop.getTorsos())
		{
			part_dd->add(t.getName().c_str());
		}
	}

	else if (part_type == PartType::BATTERY)
	{
		part_dd->label("Batteries: ");

		for (Battery b : shop.getBatteries())
		{
			part_dd->add(b.getName().c_str());
		}
	}

	else if (part_type == PartType::ARM)
	{
		part_dd->label("Arms: ");

		for (Arm a : shop.getArms())
		{
			part_dd->add(a.getName().c_str());
		}
	}

	else if (part_type == PartType::LOCOMOTOR)
	{
		part_dd->label("Locomotors: ");

		for (Locomotor l : shop.getLocomotors())
		{
			part_dd->add(l.getName().c_str());
		}
	}
	part_dd->show();

	redraw();
}

void ReportPartsSubWindow::part_dd_CB()
{
	string image_filename = getRobotPart()->getFileName();
	if (part_image != NULL)
	{
		delete part_image;
	}
	part_image = new Fl_PNG_Image(image_filename.c_str());
	picture_box->image(part_image);
	picture_box->show();

	buffer->text(getRobotPart()->outputFormattedString("", 1).c_str());
	part_info_tb->buffer(buffer);
	part_info_tb->show();
	redraw();
}

void ReportPartsSubWindow::reset()
{
	part_type_dd->value(-1); //Blank
	part_dd->clear();
	buffer->text("");
	part_info_tb->buffer(buffer);
	picture_box->hide();
	part_info_tb->hide();
}

void ReportPartsSubWindow::close_btn_CB()
{
	hide();
	reset();
}