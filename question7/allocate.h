#ifndef ALLOCATE_H
#define ALLOCATE_H
#include "couple.h"
#include "boy.h"
#include "girl.h"
class allocate{
	friend void input();
	friend void make_couple(boy b[],girl g[],couple c[]);
};
void input();
void make_couple(boy b[],girl g[],couple c[]);
#endif
