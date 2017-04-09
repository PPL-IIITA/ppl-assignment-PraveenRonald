#include <iostream>
#include <fstream>
#include "boy.h"
#include "girl.h"
#include "exchange.h"
#include "gift.h"
#include "couple.h"
#include <bits/stdc++.h>
#include <ctime>
#include <string>
using namespace std;
void input()
{
	srand(time(NULL));
	fstream fp;
	fp.open("gift_data.txt");
	int i,w=0,n=100,price,type,value,lux_rating,diff_to_obtain_gift,util_value,util_class;
	std::string type_of_gift;
	string types[]={"Essential_Gift","Luxury_Gift","Utility_Gift"};//types of gifts
	for(i=0;i<n;i++)
	{
		type=rand()%3;
		price=rand()%10+15;
		value=rand()%10+25;
		lux_rating=rand()%10+1;
		diff_to_obtain_gift=rand()%10+10;
		util_value=rand()%50+50;
		util_class=rand()%70+50;
		type_of_gift=types[type];
		if(type_of_gift[0]=='L')
		fp<<"Gift" << i << " " << type_of_gift << " "<<price<< " "<< value<<" " << lux_rating << " " << diff_to_obtain_gift << "\n";
		else if(type_of_gift[0]=='U')
		fp<<"Gift" << i << " " << type_of_gift << " "<<price<< " "<< value <<" " << util_value << " " << util_class << "\n";
		else
		fp<<"Gift" << i << " " << type_of_gift << " "<<price<< " "<< value << w <<" "<< w <<"\n";
	}
	fp.close();
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
	string criteria[]={"Most_attractive","Most_intelligent","Most_rich"};//required types of boys
	string commited_type_girl[]={"The_Choosy","The_Normal","The_Desperate"};//types of committed girls
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
}
void make_couple(boy b[],girl g[],couple z[])
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
	while(!(f.eof()))
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
	for(x=0;x<j;x++)//algo for couple formation
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
	}
	file.close();	
}
void gift_exchange(gift a[],couple z[])
{
	fstream fp;
	fp.open("gift_data.txt");
	int price,value,lux_rating,difficulty,util_val,util_class,m=0,i,j;
	string name,type;
	while(!(fp.eof()))//input from gift file
	{
		fp>>name>>type>>price>>value>>util_val>>lux_rating;
		a[m].set_price(price);
		a[m].set_value(value);
		a[m].set_type_of_gift(type);
		if(type[0]=='L')
		{
			a[m].set_lux_rating(util_val);
			a[m].set_difficulty(lux_rating);
		}
		if(type[0]=='U')
		{
			a[m].set_utility_value(util_val);
			a[m].set_utility_class(util_class);
		}
		m++;
		if(m==100)
		break;
	}
	fp.close();
	fp.open("gift_exchange.txt");
	for(i=0;i<60;i++)//algo for exchanging gifts
	{
		int cost=0,value=0,lux_value=0;
		fp<<z[i].get_boytype()<<" " <<z[i].get_boyname() <<"has given";
		if(z[i].get_boytype().compare("The_Miser")==0)
		{
			for(j=0;j<100;j++)
			{
				if(cost+a[j].get_price()<=z[i].get_maintenance_cost())
				{
					if(a[j].get_type_of_gift().compare("Luxury_Gift")==0)
					{
						lux_value+=a[j].get_value();	
					}
					value+=a[j].get_value();
					cost+=a[j].get_price();
					fp<<a[j].get_type_of_gift() << "("<<a[j].get_price()<<"),"; 
				}
			}
			z[i].set_luxuryvalue(lux_value);
		}
		else if(z[i].get_boytype().compare("The_Generous")==0)
		{
			for(j=0;j<100;j++)
			{
				if(cost+a[j].get_price()<=z[i].get_budget())
				{
					if(a[j].get_type_of_gift().compare("Luxury_Gift")==0)
					{
						lux_value+=a[j].get_value();	
					}
					value+=a[j].get_value();
					cost+=a[j].get_price();
					fp<<a[j].get_type_of_gift() << "("<<a[j].get_price()<<"),"; 
				}
			}
			z[i].set_luxuryvalue(lux_value);
		}
		else
		{
			for(j=0;j<100;j++)
			{
				if(cost+a[j].get_price()<=z[i].get_budget())
				{
					if(a[j].get_type_of_gift().compare("Luxury_Gift")==0)
					{
						lux_value+=a[j].get_value();	
					}
					value+=a[j].get_value();
					cost+=a[j].get_price();
					fp<<a[j].get_type_of_gift() << "("<<a[j].get_price()<<"),"; 
				}
			}
			z[i].set_luxuryvalue(lux_value);
		}
		z[i].set_totalprice(cost);
		z[i].set_totalvalue(value);
		fp << "gift to" << z[i].get_girlname()<<"worth "<<z[i].get_totalprice()<<endl;
		fp<<endl;
	}
	fp.close();
	//calculates boys happiness
	
	for(i=0;i<60;i++)
	{
		z[i].set_happiness_of_couple(0);
		int temp=z[i].get_happiness_of_couple();
		if(z[i].get_boytype().compare("The_Miser")==0)
		{
			temp+=z[i].get_budget()-z[i].get_totalprice();
			z[i].set_happiness_of_couple(temp);
		}
		else if(z[i].get_boytype().compare("The_Generous")==0)
		{
			z[i].set_happiness_of_couple(temp);
		}
		else
		{
			temp+=z[i].get_girlintel();
			z[i].set_happiness_of_couple(temp);
		}
	}
	//calculates happiness of girls
	for(i=0;i<60;i++)
	{
		int temp=z[i].get_happiness_of_couple();
		if(z[i].get_girltype().compare("The_Choosy")==0)
		{
			temp+=(int)log(abs(z[i].get_totalprice()-z[i].get_maintenance_cost()));
			z[i].set_happiness_of_couple(temp);
		}
		else if(z[i].get_girltype().compare("The_Normal")==0)
		{
			temp+=z[i].get_totalprice()-z[i].get_maintenance_cost()+z[i].get_totalvalue();
			z[i].set_happiness_of_couple(temp);
		}
		else
		{
			temp+=(abs(z[i].get_totalprice()-z[i].get_maintenance_cost()));
			z[i].set_happiness_of_couple(temp);
		}
	}
	//sort according to couple happiness
	couple temp1;
	for(i=0;i<60;i++)
	{
		for(j=0;j<60;j++)
		{
			if(z[i].get_happiness_of_couple()<z[j].get_happiness_of_couple())
			{
				temp1=z[i];
				z[i]=z[j];
				z[j]=temp1;
			}
		}
	}
}
void breakup(couple z[],boy b[],girl g[])
{
	int k,i;
	cout <<"enter the value of k" <<endl;
	cin >> k;
	cout <<"k least happy couples"<<endl;
	fstream file;
	file.open("break_up.txt");
	for(i=0;i<k;i++)
	{
		cout<<z[i].get_boyname()<<" "<<z[i].get_girlname()<<endl;
		file<<z[i].get_boyname()<<" "<<z[i].get_girlname()<<endl;
	}
	file.close();
	fstream fp,fp1;
	int attrac,iq,minattrac,budget,j=0,w=0;
	string name,type,criteria;
	for(i=0;i<k;i++)//performs breakups
	{
		j=0;w=0;
		string b_name=z[i].get_boyname();
		string g_name=z[i].get_girlname();
		fp.open("boy_data.txt");
		while(!(fp.eof()))
		{
			fp >> name >> attrac >> budget >> iq >> minattrac >> type;
			if(name.compare(b_name)==0)
			break;
			else
			j++;
		}
		b[j].initialize_commitstatus();
		fp1.open("girl_data.txt");
		while(!(fp1.eof()))
		{
			fp1>>name >> attrac >> budget >> iq >> criteria>> type;
			if(name.compare(g_name)==0)
			break;
			else
			w++;
		}
		g[w].initialize_commitstatus();
		g[w].set_exname(b_name);
		fp.close();
		fp1.close();
	}
	//couple formation for break up couples
	cout<<"new couples after break up"<<endl;
    int x,y;
	for(x=0;x<60;x++)
	{
    	if(g[x].get_commitstatus()==true)
		continue;
		if(g[x].get_criteria().compare("Most_attractive")==0)
        {
			int max=0,index = -1;
			for(y=0;y<90;y++)
			{
				if(b[y].check_dating_req(b[y],g[x])&&(b[y].get_commitstatus()==false)&&(b[y].get_attractiveness())>=max&&g[x].get_exname()!=b[y].getname())
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
			}
			else
			{
				cout<<g[x].getname()<<" requirements do not fulfill"<<endl;
			}
		}
        else if(g[x].get_criteria().compare("Most_intelligent")==0)
       	{
			int max=0,index = -1;
			for(y=0;y<i;y++)
			{
				if(b[y].check_dating_req(b[y],g[x])&&(b[y].get_commitstatus()==false)&&(b[y].get_intelligence())>=max&&g[x].get_exname()!=b[y].getname())
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
			}
			else
			{
				cout<<g[x].getname()<<" requirements do not fulfill"<<endl;
			}
		}
        else
        {
			int max=0,index = -1;
			for(y=0;y<i;y++)
			{
				if(b[y].check_dating_req(b[y],g[x])&&(b[y].get_commitstatus()==false)&&b[y].get_budget()>=max&&g[x].get_exname()!=b[y].getname())
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
			}
			else
			{
				cout<<g[x].getname()<<" requirements do not fulfill"<<endl;
			}
		}
	}		
}
