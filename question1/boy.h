#ifndef BOY_H
#define BOY_H
#include <string>
#include "girl.h"
using namespace std;
class boy{
	private:
		std::string name;
		int attrac;
		int budget;
		int iq;
		int min_attrac;
		bool commit;
	public:
        std::string getname();
        int get_attract();
        int get_budget();
        int get_intel();
        int get_reqattract();
        bool get_commitstatus();
        void set_commitstatus();
        void setname(string);
        void set_budget(int);
        void set_intel(int);
        void set_reqattract(int);
        void set_attract(int);
        bool check_dating_req(boy,girl);
};
#endif
