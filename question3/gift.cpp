#include "gift.h"
#include <string>
using namespace std;
int gift::get_difficulty()
{
	return this->diff_to_obtain_gift;
}
int gift::get_lux_rating()
{
	return this->lux_rating;
}
int gift::get_price()
{
	return this->price;
}
std::string gift::get_type_of_gift()
{
	return this->type_of_gift;
}
int gift::get_utility_value()
{
	return this->util_value;
}
int gift::get_value()
{
	return this->val;
}
int gift::get_utility_class()
{
	return this->util_class;
}
void gift::set_difficulty(int diff_to_obtain_gift)
{
	this->diff_to_obtain_gift=diff_to_obtain_gift;
}
void gift::set_lux_rating(int lux_rating)
{
	this->lux_rating=lux_rating;
}
void gift::set_price(int price)
{
	this->price=price;
}
void gift::set_type_of_gift(string type_of_gift)
{
	this->type_of_gift=type_of_gift;
}
void gift::set_utility_class(int util_class)
{
	this->util_class=util_class;
}
void gift::set_utility_value(int util_value)
{
	this->util_value;
}
void gift::set_value(int value)
{
	this->val;
}
