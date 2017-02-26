#ifndef GIRL_H
#define GIRL_H
#include <string>
using namespace std;
class girl{
	private:
		std::string name;
		int attrac;
		int maintenance_cost;
		int iq;
		bool commit;
		std::string criteria_for_choosing_boys;
	public:
        std::string getname();
        std::string get_criteria();
        int get_attract();
        int get_maintenance_cost();
        int get_intel();
        bool get_commitstatus();
        void set_commitstatus();
        void setname(string);
        void set_budget(int);
        void set_intel(int);
        void set_maintenance_cost(int);
        void set_attract(int);
        void set_criteria(string);
};
#endif

