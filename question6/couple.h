#ifndef COUPLE_H
#define COUPLE_H
#include "girl.h"
#include "boy.h"
#include "gift.h"
#include <bits/stdc++.h>
using namespace std;
class couple{
	private:
		int happi_of_couple;
		int compat_of_couple;
		string boy_name;
		string g_name;
		int maintenance_cost;
		int budget;
		vector <gift> gifts;
		string b_type;
		string g_type;
		int tot_price;
		int g_iq;
		int tot_value;
		int lux_value;
		int b_iq;
		int b_attrac;
		int g_attrac;
		bool bup;
	public:
		std::string get_boyname();
		std::string get_girlname();
		int get_maintenance_cost();
		int get_budget();
		int get_happiness_of_couple();
		int get_compatibility_of_couple();
		std::string get_boytype();
		std::string get_girltype();
		int get_totalprice();
		int get_totalvalue();
		int get_girlintel();
		int get_boyintel();
		int get_luxuryvalue();
		int get_boyattractiveness();
		int get_girlattractiveness();
		bool get_break_up();
		void set_boyname(string);
		void set_girlname(string);
		void set_maintenance_cost(int);
		void set_budget(int);
		void set_happiness_of_couple(int);
		void set_compatibility_of_couple(int);
		void set_gift(vector<gift>);
		void set_boytype(string);
		void set_girltype(string);
		void set_totalprice(int);
		void set_totalvalue(int);
		void set_luxuryvalue(int);
		void set_girlintel(int);
		void set_boyintel(int);
		void set_boyattractiveness(int);
		void set_girlattractiveness(int);
		void set_break_up();
		void initialize_break_up();
};
#endif
