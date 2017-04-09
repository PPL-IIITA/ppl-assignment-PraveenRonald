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
		std::string type_of_committed_girl;
		std::string ex;
	public:
        std::string getname();
        std::string get_criteria();
        int get_attractiveness();
        int get_maintenance_cost();
        int get_intelligence();
        std::string get_type_of_committed_girl();
        bool get_commitstatus();
        std::string get_exname();
        void initialize_commitstatus();
        void set_type_of_committed_girl(string);
        void set_commitstatus();
        void setname(string);
        void set_budget(int);
        void set_intel(int);
        void set_maintenance_cost(int);
        void set_attract(int);
        void set_criteria(string);
        void set_exname(string);
};
#endif

