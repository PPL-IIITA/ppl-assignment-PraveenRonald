#ifndef FIND_H
#define FIND_H
#include "couple.h"
#include "boy.h"
#include "girl.h"
class find{
	friend void findgf(boy b[],int type);
};
void findgf(boy b[],int type);
#endif

