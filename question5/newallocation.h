#ifndef NEWALLOCATION_H
#define NEWALLOCATION_H
#include "gift.h"
#include "couple.h"
#include "boy.h"
#include "girl.h"
class newallocation{
	friend void couple_make(boy b[],girl g[],couple c[]);
};
void couple_make(boy b[],girl g[],couple c[]);
#endif
