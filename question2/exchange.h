#ifndef EXCHANGE_H
#define EXCHANGE_H
#include "gift.h"
#include "couple.h"
#include "boy.h"
#include "girl.h"
class exchange{
	friend void input();
	friend void gift_exchange(gift a[],boy b[],girl g[],couple c[]);
};
void input();
void gift_exchange(gift a[],boy b[],girl g[],couple c[]);
#endif
