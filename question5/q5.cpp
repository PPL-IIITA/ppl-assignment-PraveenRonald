#include<iostream>
#include "boy.h"
#include "girl.h"
#include "couple.h"
#include "gift.h"
#include "utility.h"
#include "newallocation.h"
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
	int t;
	cout<<"make choice for couple allotement 1 for old 2 for new algorithm"<<endl;
	cin>> t;
	if(t==1)
	{
		make_couple(b,g,c);
		
	}
	if(t==2)
	{
		couple_make(b,g,c);
	}
	gift_exchange(a,c);
	return 0;
}

