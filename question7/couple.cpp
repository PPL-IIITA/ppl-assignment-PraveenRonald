#include "couple.h"
#include <vector>
#include <string>
using namespace std;
bool couple::get_break_up()
{
	return this->bup;
}
std::string couple::get_boyname()
{
	return this->boy_name;
}
std::string couple::get_girlname()
{
	return this->g_name;
}
int couple::get_maintenance_cost()
{
	return this->maintenance_cost;
}
int couple::get_budget()
{
	return this->budget;
}
int couple::get_happiness_of_couple()
{
	return this->happi_of_couple;
}
int couple::get_compatibility_of_couple()
{
	return this->compat_of_couple;
}
std::string couple::get_boytype()
{
	return this->b_type;
}
std::string couple::get_girltype()
{
	return this->g_type;
}
int couple::get_totalprice()
{
	return this->tot_price;
}
int couple::get_totalvalue()
{
	return this->tot_value;
}
int couple::get_girlintel()
{
	return this->g_iq;
}
int couple::get_boyintel()
{
	return this->b_iq;
}
int couple::get_luxuryvalue()
{
	return this->lux_value;
}
int couple::get_boyattractiveness()
{
	return this->b_attrac;
}
int couple::get_girlattractiveness()
{
	return this->g_attrac;
}
void couple::set_boyname(string boy_name)
{
	this->boy_name=boy_name;
}
void couple::set_girlname(string g_name)
{
	this->g_name=g_name;
}
void couple::set_maintenance_cost(int maintenance_cost)
{
	this->maintenance_cost=maintenance_cost;
}
void couple::set_budget(int budget)
{
	this->budget=budget;
}
void couple::set_happiness_of_couple(int happi_of_couple)
{
	this->happi_of_couple=happi_of_couple;
}
void couple::set_compatibility_of_couple(int compat_of_couple)
{
	this->compat_of_couple=compat_of_couple;
}
void couple::set_break_up()
{
	this->bup=true;
}
void couple::initialize_break_up()
{
	this->bup=false;
}
void couple::set_boytype(string b_type)
{
	this->b_type=b_type;
}
void couple::set_girltype(string g_type)
{
	this->g_type=g_type;
}
void couple::set_totalprice(int tot_price)
{
	this->tot_price=tot_price;
}
void couple::set_totalvalue(int tot_value)
{
	this->tot_value=tot_value;
}
void couple::set_luxuryvalue(int lux_value)
{
	this->lux_value=lux_value;
}
void couple::set_boyintel(int b_iq)
{
	this->b_iq=b_iq;
}
void couple::set_girlintel(int g_iq)
{
	this->g_iq=g_iq;
}
void couple::set_boyattractiveness(int b_attrac)
{
	this->b_attrac=b_attrac;
}
void couple::set_girlattractiveness(int g_attrac)
{
	this->g_attrac=g_attrac;
}
