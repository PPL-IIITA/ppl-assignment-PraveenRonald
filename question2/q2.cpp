#include<iostream>
#include "boy.h"
#include "girl.h"
#include "couple.h"
#include "gift.h"
#include "exchange.h"
#include <vector>
#include <string>
using namespace std;
int main()
{
	boy b[90];
	girl g[60];
	couple c[60];
	gift a[100];
	input();
	gift_exchange(a,b,g,c);
	return 0;
}

