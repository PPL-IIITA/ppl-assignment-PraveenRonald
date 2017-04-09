#include <iostream>
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
	make_couple(b,g,c);
	gift_exchange(a,c);
	breakup(c,b,g);
	return 0;
}

