#ifndef allocate_H
#define allocate_H
#include<vector>
#include "boy.h"
#include "girl.h"
class allocate{
	friend void input();
	friend void make_couple(boy a[],girl g[]);
};
void input();
void make_couple(boy a[],girl g[]);
#endif
