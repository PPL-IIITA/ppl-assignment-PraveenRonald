#ifndef GIFT_H
#define GIFT_H
#include <string>
using namespace std;
class gift{
	private:
		int price;
		int val;
		std::string type_of_gift;
		int lux_rating;
		int diff_to_obtain_gift;
		int util_value;
		int util_class;
	public:
		int get_price();
		int get_value();
		std::string get_type_of_gift();
		int get_lux_rating();
		int get_difficulty();
		int get_utility_value();
		int get_utility_class();
		void set_price(int);
		void set_value(int);
		void set_type_of_gift(string);
		void set_lux_rating(int);
		void set_difficulty(int);
		void set_utility_value(int);
		void set_utility_class(int);
};
#endif
