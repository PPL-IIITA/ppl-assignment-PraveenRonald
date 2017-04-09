#include "girl.h"
#include <string>
using namespace std;
//get set functions for accessing private members
std::string girl::getname()
{
    return this->name;
}
std::string girl::get_exname()
{
	return this->ex;
}
std::string girl::get_criteria()
{
	return this->criteria_for_choosing_boys;
}
int girl::get_attractiveness()
{
    return this->attrac;
}
int girl::get_maintenance_cost()
{
    return this->maintenance_cost;
}
int girl::get_intelligence()
{
	return this->iq;
}
void girl::initialize_commitstatus()
{
	this->commit=false;
}
bool girl::get_commitstatus()
{
	return this->commit;
}
string girl::get_type_of_committed_girl()
{
	return this->type_of_committed_girl;
}
void girl::set_exname(std::string ex)
{
	this->ex=ex;
}
void girl::set_type_of_committed_girl(std::string type_of_committed_girl)
{
	this->type_of_committed_girl=type_of_committed_girl;
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
