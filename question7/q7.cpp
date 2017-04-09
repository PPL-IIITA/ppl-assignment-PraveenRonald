#include<iostream>
#include "boy.h"
#include "girl.h"
#include "couple.h"
#include "allocate.h"
#include "find.h"
#include <vector>
#include <string>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(NULL));
	boy b[90];
	girl g[60];
	couple c[60];
	input();
	make_couple(b,g,c);
	int type;
	type=rand()%3+1;
	//1 for general array 2 for sorted array 3 for hash table
	cout<<"searching by "<<type<<endl;
	findgf(b,type);
	return 0;
}

