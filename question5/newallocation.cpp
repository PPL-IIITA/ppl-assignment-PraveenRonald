#include <iostream>
#include <fstream>
#include "boy.h"
#include "girl.h"
#include "utility.h"
#include "gift.h"
#include "couple.h"
#include "newallocation.h"
#include <bits/stdc++.h>
#include <ctime>
#include <string>
using namespace std;
void couple_make(boy b[],girl g[],couple z[])
{
	fstream f;
	f.open("boy_data.txt");
	int attrac,iq,minattrac,budget,i=0;
	string name,type;
	while(!(f.eof()))//input from boy file
	{
		f >> name >> attrac >> budget >> iq >> minattrac >> type;
		b[i].setname(name);
		b[i].set_attractiveness(attrac);
		b[i].set_budget(budget);
		b[i].set_intelligence(iq);
		b[i].set_minreqattract(minattrac);
		b[i].set_typeofcommittedboy(type);
		b[i].initialize_commitstatus();
		i++;
		if(i==90)
		break;
	}
	f.close();
	f.open("girl_data.txt");
	string criteria_for_choosing_boys,type_girl;
	int j=0;
	while(!(f.eof()))//input from girl file
	{
		f >> name >> attrac >> budget >> iq >> criteria_for_choosing_boys>> type_girl;
		g[j].setname(name);
		g[j].set_attract(attrac);
		g[j].set_maintenance_cost(budget);
		g[j].set_intel(iq);
		g[j].set_criteria(criteria_for_choosing_boys);
		g[j].set_type_of_committed_girl(type_girl);
		g[j].initialize_commitstatus();
		j++;
		if(j==60)
		break;
	}
	f.close();

	//sort girl list by maintenance cost
	int x,y;
	girl temp;
	for(x=0;x<60;x++)
	{
		for(y=0;y<60;y++)
		{
			if(g[x].get_maintenance_cost()>g[y].get_maintenance_cost())
			{
				temp=g[x];
				g[x]=g[y];
				g[y]=temp;
			}
		}
	}
	//sort boys list by attractiveness
	boy temp1;
	for(x=0;x<90;x++)
	{
		for(y=0;y<90;y++)
		{
			if(b[x].get_attractiveness()>b[y].get_attractiveness())
			{
				temp1=b[x];
				b[x]=b[y];
				b[y]=temp1;
			}
		}
	}
	ofstream file;
    file.open("couple.txt");
	x=0;
	while(x<60)
	{
		//girl chooses
    	if(g[x].get_commitstatus()==true)
    	{
    		x++;
    		continue;
		}
		if(g[x].get_criteria().compare("Most_attractive")==0)
        {
			int max=0,index = -1;
			for(y=0;y<i;y++)
			{
				if(b[y].check_dating_req(b[y],g[x])&&(b[y].get_commitstatus()==false)&&(b[y].get_attractiveness())>=max)
				{
					max=b[y].get_attractiveness();
					index=y;
				}
			}
			if(index!=-1)
			{
				b[index].set_commitstatus();
				g[x].set_commitstatus();
				z[x].set_boyname(b[index].getname());
				z[x].set_girlname(g[x].getname());
				z[x].set_maintenance_cost(g[x].get_maintenance_cost());
				z[x].set_budget(b[index].get_budget());
				z[x].set_boytype(b[index].get_typeofcommittedboy());
				z[x].set_girltype(g[x].get_type_of_committed_girl());
				z[x].set_girlintel(g[x].get_intelligence());
				z[x].set_boyintel(b[index].get_intelligence());
				z[x].set_girlattractiveness(g[x].get_attractiveness());
				z[x].set_boyattractiveness(b[index].get_attractiveness());
				cout<<g[x].getname() << " " << b[index].getname()<<endl;
				file <<g[x].getname() << g[x].get_type_of_committed_girl() << " commited to " << b[index].getname()<< b[index].get_typeofcommittedboy()<<endl;
			}
		}
        else if(g[x].get_criteria().compare("Most_intelligent")==0)
       	{
			int max=0,index = -1;
			for(y=0;y<i;y++)
			{
				if(b[y].check_dating_req(b[y],g[x])&&(b[y].get_commitstatus()==false)&&(b[y].get_intelligence())>=max)
				{
					max=b[y].get_intelligence();
					index=y;
				}
			}
			if(index!=-1)
			{
				b[index].set_commitstatus();
				g[x].set_commitstatus();
				z[x].set_boyname(b[index].getname());
				z[x].set_girlname(g[x].getname());
				z[x].set_maintenance_cost(g[x].get_maintenance_cost());
				z[x].set_budget(b[index].get_budget());
				z[x].set_boytype(b[index].get_typeofcommittedboy());
				z[x].set_girltype(g[x].get_type_of_committed_girl());
				z[x].set_girlintel(g[x].get_intelligence());
				z[x].set_boyintel(b[index].get_intelligence());
				z[x].set_girlattractiveness(g[x].get_attractiveness());
				z[x].set_boyattractiveness(b[index].get_attractiveness());
				cout<<g[x].getname() << " " << b[index].getname()<<endl;
				file <<g[x].getname() << g[x].get_type_of_committed_girl() << " commited to " << b[index].getname()<< b[index].get_typeofcommittedboy()<<endl;
			}
		}
        else
        {
			int max=0,index = -1;
			for(y=0;y<i;y++)
			{
				if(b[y].check_dating_req(b[y],g[x])&&(b[y].get_commitstatus()==false)&&b[y].get_budget()>=max)
				{
					max=b[y].get_budget();
					index=y;
				}
			}
			if(index!=-1)
			{
				b[index].set_commitstatus();
				g[x].set_commitstatus();
				z[x].set_boyname(b[index].getname());
				z[x].set_girlname(g[x].getname());
				z[x].set_maintenance_cost(g[x].get_maintenance_cost());
				z[x].set_budget(b[index].get_budget());
				z[x].set_boytype(b[index].get_typeofcommittedboy());
				z[x].set_girltype(g[x].get_type_of_committed_girl());
				z[x].set_girlintel(g[x].get_intelligence());
				z[x].set_boyintel(b[index].get_intelligence());
				z[x].set_girlattractiveness(g[x].get_attractiveness());
				z[x].set_boyattractiveness(b[index].get_attractiveness());
				cout<<g[x].getname() << " " << b[index].getname()<<endl;
				file <<g[x].getname() << g[x].get_type_of_committed_girl() << " commited to " << b[index].getname()<< b[index].get_typeofcommittedboy()<<endl;
			}
		}
		//boy chooses
		int w=0,max1=0,index;
		while(b[w].get_commitstatus()!=false)
		w++;
		for(y=0;y<60;y++)
		{
			if(g[y].get_attractiveness()>max1&&g[y].get_commitstatus()==false)
			{
				max1=g[y].get_attractiveness();
				index=y;
			}
		}
		b[w].set_commitstatus();
		g[index].set_commitstatus();
		z[index].set_boyname(b[w].getname());
		z[index].set_girlname(g[index].getname());
		z[index].set_maintenance_cost(g[index].get_maintenance_cost());
		z[index].set_budget(b[w].get_budget());
		z[index].set_boytype(b[w].get_typeofcommittedboy());
		z[index].set_girltype(g[index].get_type_of_committed_girl());
		z[index].set_girlintel(g[index].get_intelligence());
		z[index].set_boyintel(b[w].get_intelligence());
		z[index].set_girlattractiveness(g[index].get_attractiveness());
		z[index].set_boyattractiveness(b[w].get_attractiveness());
		cout<<g[index].getname() << " " << b[w].getname()<<endl;
		file <<g[index].getname() << g[index].get_type_of_committed_girl() << " commited to " << b[w].getname()<< b[w].get_typeofcommittedboy()<<endl;
		x++;
	}
	file.close();	
}
