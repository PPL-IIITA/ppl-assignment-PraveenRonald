#ifndef UTILITY_H
#define UTILITY_H
#include "gift.h"
#include "couple.h"
#include "boy.h"
#include "girl.h"
class utility{
	friend void input();
	friend void make_couple(boy b[],girl g[],couple c[]);
	friend void gift_exchange(gift a[],couple c[]);	
};
void input();
void make_couple(boy b[],girl g[],couple c[]);
void gift_exchange(gift a[],couple c[]);
#endif
