#ifndef BOY_H
#define BOY_H
#include <string>
#include "girl.h"
#include "gift.h"
#include <vector>
using namespace std;
class boy{
	private:
		std::string name;
		int attrac;
		int budget;
		int iq;
		int min_attrac_req;
		bool is_commit;
		string type_of_committed_boy;
	public:
        std::string getname();
        int get_attractiveness();
        int get_budget();
        int get_intelligence();
        int get_minreqattract();
        bool get_commitstatus();
        std::string get_typeofcommittedboy();
        void initialize_commitstatus();
        void set_typeofcommittedboy(string);
        void set_commitstatus();
        void setname(string);
        void set_budget(int);
        void set_intelligence(int);
        void set_minreqattract(int);
        void set_attractiveness(int);
        bool check_dating_req(boy,girl);
};
#endif
