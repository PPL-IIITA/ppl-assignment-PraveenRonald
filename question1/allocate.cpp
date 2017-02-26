#include<iostream>
#include <fstream>
#include"boy.h"
#include "girl.h"
#include "allocate.h"
#include <bits/stdc++.h>
#include<ctime>
#include <vector>
using namespace std;
void input()
{
	srand(time(NULL));
	fstream fp;
	fp.open("boy_data.txt");
	int n=30,i,attrac,budget,iq,minattrac,type;
	for(i=0;i<n;i++)
	{
		attrac=rand()%10+1;
		budget=rand()%100+1;
		iq=rand()%100+1;
		minattrac=rand()%3+2;
		fp << "B" << i  <<" " << attrac <<" "<< budget <<" "<<  iq <<" " << minattrac <<endl;
	}	
	fp.close();
	fp.open("girl_data.txt");
	n=10;
	string criteria[]={"Most_attractive","Most_intelligent","Most_rich"};
	std::string criteria_for_choosing_boys;
	for(i=0;i<n;i++)
	{
		attrac=rand()%10+1;
		budget=rand()%30;
		iq=rand()%100+1;
		type=rand()%3;
		criteria_for_choosing_boys=criteria[type];
		fp << "G" << i << " " << attrac << " " << budget << " " <<iq << " " << criteria_for_choosing_boys <<endl;
	}
	fp.close();
}
void make_couple(boy a[],girl g[])
{
	fstream f;
	f.open("boy_data.txt");
	int attrac,iq,minattrac,budget,i=0;
	string name;
	while(!(f.eof()))
	{
		f >> name >> attrac >> budget >> iq >> minattrac;
		a[i].setname(name);
		a[i].set_attract(attrac);
		a[i].set_budget(budget);
		a[i].set_intel(iq);
		a[i].set_reqattract(minattrac);
		i++;
		if(i==30)
		break;
	}
	f.close();
	f.open("girl_data.txt");
	string criteria_for_choosing_boys;
	int j=0;
	while(!(f.eof()))
	{
		f >> name >> attrac >> budget >> iq >> criteria_for_choosing_boys;
		g[j].setname(name);
		g[j].set_attract(attrac);
		g[j].set_maintenance_cost(budget);
		g[j].set_intel(iq);
		g[j].set_criteria(criteria_for_choosing_boys);
		j++;
		if(j==10)
		break;
	}
	f.close();
	ofstream file;
    file.open("log.txt");
    int x,y;
	for(x=0;x<j;x++)
	{
    	if(g[x].get_commitstatus()==true)
		continue;
		if(g[x].get_criteria().compare("Most_attractive")==0)
        {
			int max=0,index = -1;
			for(y=0;y<j;y++)
			{
				if(a[y].check_dating_req(a[y],g[x])&&(a[y].get_commitstatus()==false)&&(a[y].get_attract())>=max)
				{
					max=a[y].get_attract();
					index=y;
				}
			}
			if(index!=-1)
			{
				a[index].set_commitstatus();
				g[x].set_commitstatus();
				cout<<a[index].getname() << " " << g[x].getname()<<endl;
				file <<a[index].getname() << " commited to " << g[x].getname()<<endl;
			}
		}
        else if(g[x].get_criteria().compare("Most_intelligent")==0)
        {
			int max=0,index = -1;
			for(y=0;y<j;y++)
			{
				if(a[y].check_dating_req(a[y],g[x])&&(a[y].get_commitstatus()==false)&&(a[y].get_intel())>=max)
				{
					max=a[y].get_intel();
					index=y;
				}
			}
			if(index!=-1)
			{
				a[index].set_commitstatus();
				g[x].set_commitstatus();
				cout<<a[index].getname() << " " << g[x].getname()<<endl;
				file <<a[index].getname() << " commited to " << g[x].getname()<<endl;
			}
		}
        else
        {
			int max=0,index = -1;
			for(y=0;y<j;y++)
			{
				if(a[y].check_dating_req(a[y],g[x])&&(a[y].get_commitstatus()==false)&&a[y].get_budget()>=max)
				{
					max=a[y].get_budget();
					index=y;
				}
			}
			if(index!=-1)
			{
				a[index].set_commitstatus();
				g[x].set_commitstatus();
				cout<<a[index].getname() << " " << g[x].getname()<<endl;
				file <<a[index].getname() << " commited to" << g[x].getname()<<endl;
			}
		}
	}
}
