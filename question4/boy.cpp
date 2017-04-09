#include "boy.h"
#include "girl.h"
#include <string>
#include <vector>
#include "gift.h"
using namespace std;
//get set functions for accessing private members
string boy::getname()
{
    return this->name;
}

int boy::get_attractiveness()
{
    return this->attrac;
}

int boy::get_budget()
{
    return this->budget;
}

int boy::get_intelligence()
{
    return this->iq;
}
int boy::get_minreqattract()
{
    return this->min_attrac_req;
}
bool boy::get_commitstatus()
{
    return this->is_commit;
}
string boy::get_typeofcommittedboy()
{
	return this->type_of_committed_boy;
}
void boy::set_typeofcommittedboy(string type_of_committed_boy) 
{
	this->type_of_committed_boy=type_of_committed_boy;
}
void boy::set_commitstatus()
{
    this->is_commit=true;
}
void boy::initialize_commitstatus()
{
	this->is_commit=false;
}
void boy::setname(string name)
{
	this->name=name;
}
void boy::set_budget(int budget)
{
	this->budget=budget;
}
void boy::set_minreqattract(int minattrac)
{
	this->min_attrac_req=minattrac;
}
void boy::set_intelligence(int iq)
{
	this->iq=iq;
}
void boy::set_attractiveness(int attract)
{
	this->attrac=attract;
}
bool boy::check_dating_req (boy b,girl g){
    return (b.budget >= g.get_maintenance_cost()&& b.min_attrac_req <= g.get_attractiveness() ? true : false);
}

