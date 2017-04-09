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
	make_couple(b,g,c);
	int t;
	cout<<"enter the value of t"<<endl;
	cin >> t;
	int i;
	for(i=1;i<=t;i++)//gift exchange and breakup after each day upto t
	{
		gift_exchange(a,c);
		breakup(c,b,g,t);
	}
	return 0;
}

