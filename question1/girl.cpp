#include "girl.h"
#include <string>
using namespace std;
std::string girl::getname()
{
    return this->name;
}
std::string girl::get_criteria()
{
	return this->criteria_for_choosing_boys;
}
int girl::get_attract()
{
    return this->attrac;
}
int girl::get_maintenance_cost()
{
    return this->maintenance_cost;
}
int girl::get_intel()
{
	return this->iq;
}
bool girl::get_commitstatus()
{
	return this->commit;
}
void girl::set_commitstatus()
{
	this->commit=true;
}
void girl::setname(string name)
{
	this->name=name;
}
void girl::set_maintenance_cost(int budget)
{
	this->maintenance_cost=budget;
}
void girl::set_intel(int iq)
{
	this->iq=iq;
}
void girl::set_attract(int attract)
{
	this->attrac=attract;
}
void girl::set_criteria(string criteria_for_choosing_boys)
{
	this->criteria_for_choosing_boys=criteria_for_choosing_boys;
}
