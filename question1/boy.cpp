#include "boy.h"
#include "girl.h"
#include <string>

string boy::getname()
{
    return this->name;
}

int boy::get_attract()
{
    return this->attrac;
}

int boy::get_budget()
{
    return this->budget;
}

int boy::get_intel()
{
    return this->iq;
}
int boy::get_reqattract()
{
    return this->min_attrac;
}
bool boy::get_commitstatus()
{
    return this->commit;
}
void boy::set_commitstatus()
{
    this->commit=true;
}
void boy::setname(string name)
{
	this->name=name;
}
void boy::set_budget(int budget)
{
	this->budget=budget;
}
void boy::set_reqattract(int minattrac)
{
	this->min_attrac=minattrac;
}
void boy::set_intel(int iq)
{
	this->iq=iq;
}
void boy::set_attract(int attract)
{
	this->attrac=attract;
}
bool boy::check_dating_req (boy b,girl g){
    return (b.budget >= g.get_maintenance_cost()&& b.min_attrac <= g.get_attract() ? true : false);
}

