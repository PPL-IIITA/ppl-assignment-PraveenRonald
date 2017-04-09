#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include "boy.h"
#include "girl.h"
#include "couple.h"
#include "allocate.h"
#include <bits/stdc++.h>
#include <ctime>
#include <string>
using namespace std;
void findgf(boy b[],int type)
{
	fstream fp;
	fp.open("boy_test.txt");
	int i,j=0,k;
	string a[100];
	while(!fp.eof())
	{
		fp>>a[j++];
	}
	//normal array searching
	if(type==1)
	{
		bool flag=true;
		for(k=0;k<j;k++)
		{
			for(i=0;i<90;i++)
			{
				if(b[i].getname()==a[k]&&b[i].get_commitstatus()==true)
				{
					flag=false;
					cout<<a[k]<<" "<<b[i].get_gfname()<<endl;
					break;
				}
			}
			if(flag)
			cout<<a[k]<<" is single"<<endl;
		}
	}
	//searching by binary search
	else if(type==2)
	{
		
		string bname,str;
		bool flag=true;
		for(i=0;i<j-1;i++)
		{
			int l=0,h=90,mid;
			str=a[i].substr(1);
			stringstream geek(str);
			int x;
			geek>>x;
			int y;
			while(l<=h)
			{
				mid=(l+h)/2;
				bname=b[mid].getname();
				str=bname.substr(1);
				stringstream geek(str);
				geek>>y;
				if(x==y&&b[mid].get_commitstatus()==true)	
				{
					flag=false;
					cout<<a[i]<<" "<<b[mid].get_gfname()<<endl;
					break;
				}
				else if(y<x)
				l=mid+1;
				else
				h=mid-1;
			}
			if(flag)
			cout<<a[i]<<" is single"<<endl;
		}
	}
	//searching by hash table
	else
	{
		
		int key;
		boy h[90];
		string bname,str1;
		for(i=0;i<90;i++)
		{
			bname=b[i].getname();
			str1=bname.substr(1);//hash function
			stringstream geek(str1);
			geek>>key;
			h[key]=b[i];
		}
		for(i=0;i<j-1;i++)
		{
			bool flag=true;
			str1=a[i].substr(1);
			stringstream geek(str1);
			geek>>key;
			if(a[i]==h[key].getname()&&h[key].get_commitstatus()==true)
			{
				flag=false;
				cout<<a[i]<<" "<<h[key].get_gfname()<<endl;
				continue;
			}
			if(flag)
			cout<<a[i]<<" is single"<<endl;
		}
	}
}
