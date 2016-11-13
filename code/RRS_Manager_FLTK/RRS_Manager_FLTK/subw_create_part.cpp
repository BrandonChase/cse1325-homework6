#include "subw_create_part.h"

#include <FL/Fl_File_Chooser.H>

#include <stdexcept>
#include <exception>
#include <string>

using namespace std;

	CreatePartSubWindow::CreatePartSubWindow(Shop& p_shop) : Fl_Window(0, MENUHEIGHT + 1, WIDTH, HEIGHT - MENUHEIGHT), shop(p_shop)
	{
		//Initialize Widgets
		part_type_dd = new Fl_Choice(tb_offset, 0, TB_WIDTH, TB_HEIGHT, "Part Type: ");
		name_tb = new Fl_Input(tb_offset, 1 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Name: ");
		part_number_tb = new Fl_Int_Input(tb_offset, 2 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Part Number: ");
		weight_tb = new Fl_Float_Input(tb_offset, 3 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Weight [lb]: ");
		price_tb = new Fl_Float_Input(tb_offset, 4 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Price [$]: ");
		description_tb = new Fl_Input(tb_offset, 5 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Description: ");
		battery_compartments_tb = new Fl_Int_Input(tb_offset, 6 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Battery Compartments: ");
		power_consumed_tb = new Fl_Float_Input(tb_offset, 6 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Power Consumed [W]: ");
		max_speed_tb = new Fl_Float_Input(tb_offset, 7 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Max Speed [MPH]: ");
		contained_energy_tb = new Fl_Float_Input(tb_offset, 6 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT, "Contained Energy [kWh]: ");
		create_btn = new Fl_Button(210, 10 * (TB_HEIGHT + TB_SPACING), 100, 50, "Create Part");
		choose_image_btn = new Fl_Button(475, 0, 100, 50, "Choose Image");
		picture_box = new Fl_Box(425, 100, 200, 200);

		//Initialize drop down box
		part_type_dd->add("Head");
		part_type_dd->add("Torso");
		part_type_dd->add("Battery");
		part_type_dd->add("Arm");
		part_type_dd->add("Locomotor");
		part_type_dd->value(0);

		//Disable extra textboxes by deafult
		battery_compartments_tb->hide();
		power_consumed_tb->hide();
		max_speed_tb->hide();
		contained_energy_tb->hide();

		//Setting Callbacks
		part_type_dd->callback(s_part_type_widg_CB, this);
		choose_image_btn->callback(s_choose_image_btn_CB, this);
		create_btn->callback(s_create_btn_CB, this);
	}

	//CALLBACKS
	void CreatePartSubWindow::part_type_widg_CB()
	{
		switch (part_type_dd->value())
		{
		case 0: //Head
			battery_compartments_tb->hide();
			power_consumed_tb->hide();
			max_speed_tb->hide();
			contained_energy_tb->hide();
			choose_image_btn->show();
			break;

		case 1: //Torso
			battery_compartments_tb->show();
			power_consumed_tb->hide();
			max_speed_tb->hide();
			contained_energy_tb->hide();
			choose_image_btn->show();
			break;

		case 2: //Battery
			battery_compartments_tb->hide();
			power_consumed_tb->hide();
			max_speed_tb->hide();
			contained_energy_tb->show();
			choose_image_btn->show();
			break;

		case 3: //Arm
			battery_compartments_tb->hide();
			power_consumed_tb->show();
			max_speed_tb->hide();
			contained_energy_tb->hide();
			choose_image_btn->show();
			break;

		case 4: //Locomotor
			battery_compartments_tb->hide();
			power_consumed_tb->show();
			max_speed_tb->show();
			contained_energy_tb->hide();
			choose_image_btn->show();
			break;
		}
	}

	void CreatePartSubWindow::choose_image_btn_CB()
	{
		string directory = "./Images/";
		switch (part_type_dd->value())
		{
		case 0: //Head
			directory += "Heads";
			break;

		case 1: //Torso
			directory += "Torsos";
			break;

		case 2: //Battery
			directory += "Batteries";
			break;

		case 3: //Arm
			directory += "Arms";
			break;

		case 4: //Locomotor
			directory += "Locomotors";
			break;
		}

		image_filename = fl_file_chooser("Robot Part", "*.png", directory.c_str(), 1);
		if (part_image != NULL)
		{
			delete part_image;
		}
		part_image = new Fl_PNG_Image(image_filename.c_str());
		picture_box->image(part_image);
		picture_box->show();
		redraw();
	}

	void CreatePartSubWindow::create_btn_CB()
	{
		try
		{
			PartType part_type(partType());
			string name = this->name();
			string description = this->description();
			int part_number = partNumber();
			double weight = this->weight();
			double price = this->price();
			string image_filename = imageFileName();

			if (part_type == PartType::HEAD)
			{
				shop.addHead(Head(name, part_number, weight, price, part_type, description, image_filename));
			}

			else if (part_type == PartType::TORSO)
			{
				int battery_compartments = batteryCompartments();
				shop.addTorso(Torso(name, part_number, weight, price, part_type, description, battery_compartments, image_filename));
			}

			else if (part_type == PartType::BATTERY)
			{
				double contained_energy = containedEnergy();
				shop.addBattery(Battery(name, part_number, weight, price, part_type, description, contained_energy, image_filename));
			}

			else if (part_type == PartType::ARM)
			{
				double power_consumed = powerConsumed();
				shop.addArm(Arm(name, part_number, weight, price, part_type, description, power_consumed, image_filename));
			}

			else if (part_type == PartType::LOCOMOTOR)
			{
				double max_speed = maxSpeed();
				double power_consumed = powerConsumed();
				shop.addLocomotor(Locomotor(name, part_number, weight, price, part_type, description, max_speed, power_consumed, image_filename));
			}

			reset();
			this->hide();
		}
		catch (const exception& e)
		{
			Fl::error(e.what());
		}
	}

	//GETTERS
	PartType CreatePartSubWindow::partType() const
	{
		int part_type_index = part_type_dd->value();
		if (part_type_index < 0 || part_type_index > PartType::NUM_OF_PART_TYPES - 1)
		{
			throw runtime_error("Uknown Part Type!");
		}
		return PartType(part_type_index);
	}

	string CreatePartSubWindow::name() const
	{
		string name = name_tb->value();
		if (name == "")
		{
			throw runtime_error("Required field is blank!");
		}
		return name;
	}

	int CreatePartSubWindow::partNumber() const
	{
		int part_number;
		try
		{
			part_number = stoi(part_number_tb->value());
		}
		catch (...)
		{
			throw runtime_error("Part number is not valid number!");
		}

		if (part_number < 0)
		{
			throw runtime_error("Part number must be positive!");
		}

		if (!shop.isPartNumberUnique(part_number))
		{
			throw runtime_error("Part number is already taken!");
		}

		return part_number;
	}

	double CreatePartSubWindow::weight() const
	{
		double weight;
		try
		{
			weight = stod(weight_tb->value());
		}
		catch (...)
		{
			throw runtime_error("Weight is not valid number!");
		}

		if (weight < 0)
		{
			throw runtime_error("Weight must be positive!");
		}

		return weight;
	}

	double CreatePartSubWindow::price() const
	{
		double price;
		try
		{
			price = stod(price_tb->value());
		}
		catch (...)
		{
			throw runtime_error("Price is not valid number!");
		}

		if (price < 0)
		{
			throw runtime_error("Price must be positive!");
		}

		return price;
	}

	string CreatePartSubWindow::description() const
	{
		string description = description_tb->value();
		if (description == "")
		{
			throw runtime_error("Required field is blank!");
		}
		return description;
	}

	int CreatePartSubWindow::batteryCompartments() const
	{
		int battery_compartments;
		try
		{
			battery_compartments = stoi(battery_compartments_tb->value());
		}
		catch (...)
		{
			throw runtime_error("Battery compartments is not valid number!");
		}

		if (battery_compartments < 1 || battery_compartments > 3)
		{
			throw runtime_error("Torsos can only have 1, 2, or 3 battery compartments!");
		}

		return battery_compartments;
	}

	double CreatePartSubWindow::powerConsumed() const
	{
		double power_consumed;
		try
		{
			power_consumed = stod(power_consumed_tb->value());
		}
		catch (...)
		{
			throw runtime_error("Power consumed is not valid number!");
		}

		if (power_consumed < 0)
		{
			throw runtime_error("Power consumed must be positive!");
		}

		return power_consumed;
	}

	double CreatePartSubWindow::maxSpeed() const
	{
		double max_speed;
		try
		{
			max_speed = stod(max_speed_tb->value());
		}
		catch (...)
		{
			throw runtime_error("Max speed is not valid number!");
		}

		if (max_speed < 0)
		{
			throw runtime_error("Max speed must be positive!");
		}

		return max_speed;
	}

	double CreatePartSubWindow::containedEnergy() const
	{
		double contained_energy;
		try
		{
			contained_energy = stod(contained_energy_tb->value());
		}
		catch (...)
		{
			throw runtime_error("Contained energy is not valid number!");
		}

		if (contained_energy < 0)
		{
			throw runtime_error("Contained energy must be positive!");
		}

		return contained_energy;
	}

	string CreatePartSubWindow::imageFileName() const
	{
		if (image_filename == "")
		{
			throw runtime_error("No image selected!");
		}
		return image_filename;
	}

//FUNCTIONS
	void CreatePartSubWindow::reset()
	{
		part_type_dd->value(0);
		name_tb->value(NULL);
		part_number_tb->value(NULL);
		weight_tb->value(NULL);
		price_tb->value(NULL);
		description_tb->value(NULL);
		battery_compartments_tb->value(NULL);
		power_consumed_tb->value(NULL);
		max_speed_tb->value(NULL);
		contained_energy_tb->value(NULL);
		image_filename = "";
		picture_box->hide();
	}