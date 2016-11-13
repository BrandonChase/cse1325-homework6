#include "subw_create_customer_sa.h"

#include <stdexcept>
#include <exception>

using namespace std;

//
//BASE CLASS
//

//CONSTRUCTOR
CreatePersonSubWindow::CreatePersonSubWindow(Shop& p_shop) : Fl_Window(0, MENUHEIGHT + 1, WIDTH, HEIGHT - MENUHEIGHT), shop(p_shop)
{
	//Initialize widgets
	name_tb = new Fl_Input(tb_offset, 0 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT);
	number_tb = new Fl_Int_Input(tb_offset, 1 * (TB_HEIGHT + TB_SPACING), TB_WIDTH, TB_HEIGHT);
	create_btn = new Fl_Button(200, 2 * (TB_HEIGHT + TB_SPACING), 150, 50);

	//Set callbacks
	create_btn->callback(s_create_btn_CB, this);
}

//FUNCTIONS
void CreatePersonSubWindow::reset()
{
	name_tb->value(NULL);
	number_tb->value(NULL);
}

//GETTERS
std::string CreatePersonSubWindow::getName() const
{
	string name = name_tb->value();
	if (name == "")
	{
		throw runtime_error("Name is blank!");
	}
	return name;
}

//
//CREATE CUSTOMER SUBWINDOW
//

//CONSTRUCTOR
CreateCustomerSubWindow::CreateCustomerSubWindow(Shop& p_shop) : CreatePersonSubWindow(p_shop)
{
	//Set labels
	name_tb->label("Customer Name: ");
	number_tb->label("Customer Number: ");
	create_btn->label("Create Customer");
}

//GETTER
int CreateCustomerSubWindow::getNumber() const
{
	int customer_number;
	try
	{
		customer_number = stoi(number_tb->value());
	}
	catch (...)
	{
		throw runtime_error("Customer number is not valid number!");
	}

	if (customer_number < 0)
	{
		throw runtime_error("Customer number must be positive!");
	}

	if (!shop.isCustomerNumberUnique(customer_number))
	{
		throw runtime_error("Customer number is already taken!");
	}

	return customer_number;
}

//CALLBACK
void CreateCustomerSubWindow::create_btn_CB()
{
	string name;
	int number;

	try
	{
		name = getName();
		number = getNumber();

		shop.addCustomer(Customer(name, number));
		reset();
		this->hide();
	}
	catch (const exception& e)
	{
		Fl::error(e.what());
	}
}

//
//CREATE SA SUBWINDOW
//

//CONSTRUCTOR
CreateSASubWindow::CreateSASubWindow(Shop& p_shop) : CreatePersonSubWindow(p_shop)
{
	//Set labels
	name_tb->label("Sales Assoc. Name: ");
	number_tb->label("Sales Assoc. Number: ");
	create_btn->label("Create Sales Assoc.");
}

//GETTER
int CreateSASubWindow::getNumber() const
{
	int sa_number;
	try
	{
		sa_number = stoi(number_tb->value());
	}
	catch (...)
	{
		throw runtime_error("Sales Assoc. number is not valid number!");
	}

	if (sa_number < 0)
	{
		throw runtime_error("Sales Assoc. number must be positive!");
	}

	if (!shop.isSANumberUnique(sa_number))
	{
		throw runtime_error("Sales Assoc. number is already taken!");
	}

	return sa_number;
}

//CALLBACK
void CreateSASubWindow::create_btn_CB()
{
	string name;
	int number;

	try
	{
		name = getName();
		number = getNumber();

		shop.addSalesAssociate(SalesAssociate(name, number));
		reset();
		this->hide();
	}
	catch (const exception& e)
	{
		Fl::error(e.what());
	}
}