#include <iostream>
#include <fstream>
#include "boy.h"
#include "girl.h"
#include "couple.h"
#include "allocate.h"
#include <bits/stdc++.h>
#include <ctime>
#include <string>
using namespace std;
void input()
{
	srand(time(NULL));
	fstream fp;
	fp.open("gift_data.txt");
	int i,n,type;
	fp.open("boy_data.txt");
	int attrac,budget,iq,minattrac;
	n=90;
	std::string type_of_boy;
	string commited_type[]={"The_Miser","The_Generous","The_Geek"};//types of committed boys
	for(i=0;i<n;i++)
	{
		attrac=rand()%400+200;
		budget=rand()%40+20;
		iq=rand()%200+50;
		minattrac=rand()%200+100;
		type=rand()%3;
		type_of_boy=commited_type[type];
		fp << "B" << i  <<" " << attrac <<" "<< budget <<" "<<  iq <<" " << minattrac <<" "<<type_of_boy<<endl;
	}	
	fp.close();
	fp.open("girl_data.txt");
	n=60;
	string criteria[]={"Most_attractive","Most_intelligent","Most_rich"};//types of committed girls
	string commited_type_girl[]={"The_Choosy","The_Normal","The_Desperate"};//required types of boys
	string type_of_girl;
	std::string criteria_for_choosing_boys;
	for(i=0;i<n;i++)
	{
		attrac=rand()%500+120;
		budget=rand()%20+10;
		iq=rand()%150+40;
		type=rand()%3;
		criteria_for_choosing_boys=criteria[type];
		type_of_girl=commited_type_girl[type];
		fp << "G" << i << " " << attrac << " " << budget << " " <<iq << " " << criteria_for_choosing_boys <<" "<<type_of_girl<<endl;
	}
	fp.close();
	fp.open("boy_test.txt");
	for(i=0;i<20;i++)
	fp<<"B"<<rand()%50+40<<endl;
}
void make_couple(boy b[],girl g[],couple z[])
{
	fstream f;
	f.open("boy_data.txt");
	int attrac,iq,minattrac,budget,i=0;
	string name,type;
	while(!(f.eof()))//taking input from file
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
	while(!(f.eof()))//taking input from file
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
	ofstream file;
    file.open("couple.txt");
    int x,y;
	for(x=0;x<j;x++)//algo for formation of couple
	{
    	if(g[x].get_commitstatus()==true)
		continue;
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
				b[index].set_gfname(g[x].getname());
				g[x].set_commitstatus();
				g[x].set_bfname(b[index].getname());
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
				b[index].set_gfname(g[x].getname());
				g[x].set_bfname(b[index].getname());
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
				b[index].set_gfname(g[x].getname());
				g[x].set_commitstatus();
				g[x].set_bfname(b[index].getname());
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
	}
	file.close();	
}

