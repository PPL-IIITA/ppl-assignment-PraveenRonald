#ifndef EXCHANGE_H
#define EXCHANGE_H
#include "gift.h"
#include "couple.h"
#include "boy.h"
#include "girl.h"
class exchange{
	friend void input();
	friend void make_couple(boy b[],girl g[],couple c[]);
	friend void gift_exchange(gift a[],couple c[]);
	friend void breakup(couple c[],boy b[],girl g[],int t);
};
void input();
void make_couple(boy b[],girl g[],couple c[]);
void gift_exchange(gift a[],couple c[]);
void breakup(couple c[],boy b[],girl g[],int t);
#endif
