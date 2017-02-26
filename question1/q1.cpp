#include<iostream>
#include "boy.h"
#include "girl.h"
#include "allocate.h"
#include <vector>
using namespace std;
int main()
{
	boy a[30];
	girl g[10];
	input();
	make_couple(a,g);
}

