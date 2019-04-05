#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
	int i,j,k;
	char dataword[100],generator[50],crc[50];
	int dsize,gsize,len;

	strcpy(crc,dataword);
	cout<<"Enter generator size:"<<endl;
	cin>>gsize;
	cout<<"Enter  generator :"<<endl;
	for(i=0;i<gsize;i++)
	cin>>generator[i];
start:  cout<<"Enter dataword size:"<<endl;
	cin>>dsize;
	cout<<"Enter dataword:"<<endl;
	for(i=0;i<dsize;i++)
	cin>>dataword[i];
	
	if(dsize<gsize)
	{
		cout<<"Incorrect entered generator size.enter it again"<<endl;
		goto start;
	}
	for(i=0;i<gsize-1;i++)
	{
		dataword[dsize+i]='0';
	}	
	dataword[dsize+gsize-1]='\0';

	//new dataword
	for(i=0;i<dsize+gsize-1;i++)
	cout<<dataword[i];
	cout<<endl;
	do
	{
		for(i=0;i<gsize;i++)
		{
			if(dataword[i]==generator[i])
			{	
				dataword[i]='0';
			}
			else
			{
				dataword[i]='1';
			}		
		}
		k=0;
		for(i=0;i<gsize+dsize-1;i++)
		{
			if(dataword[i]=='0')
			{
				k++;
			}
		}
		if(k==(dsize+gsize-1))
		break;
		while(dataword[0]!='1')
		{
			for(i=0;i<dsize+gsize-1;i++)
			{
				dataword[i]=dataword[i+1];
			}
		dsize--;
		}
	len=dsize+gsize-1;
	}while(len>gsize-1);
	dataword[len]='\0';
	
	cout<<"Remainder is : "<<dataword<<endl;
	int csize;
	cout<<"Do you want to change the remainder enter 0 else 1 "<<endl;
	cin>>j;	
	if(j==0)
	{
		crc[0]='\0';
		cout<<"enter new dataword size :"<<endl;
		cin>>csize;
		cout<<"enter new dataword :"<<endl;
		for(i=0;i<csize;i++)
		cin>>crc[i];
	}
	len=strlen(dataword);
	dsize=strlen(crc);
	if(len!=gsize-1)
	{
		for(i=0;i<gsize-1-len;i++)
		{
			crc[dsize+i]='0';
		}
	}
	crc[dsize+i]='\0';
	len=strlen(dataword);
	dsize=strlen(crc);
	for(i=0;i<len;i++)
	{
		crc[dsize+i]=dataword[i];
	}
	crc[dsize+i]='\0';
	dataword[0]='\0';
	strcpy(dataword,crc);
	
	do
	{
		for(i=0;i<gsize;i++)
		{
			if(dataword[i]==generator[i])
			{	
				dataword[i]='0';
			}
			else
			{
				dataword[i]='1';
			}		
		}
		k=0;
		for(i=0;i<gsize+dsize-1;i++)
		{
			if(dataword[i]=='0')
			{
				k++;
			}
		}
		if(k==(dsize+gsize-1))
		break;
		while(dataword[0]!='1')
		{
			for(i=0;i<dsize+gsize-1;i++)
			{
				dataword[i]=dataword[i+1];
			}
		dsize--;
		}
	len=dsize+gsize-1;
	}while(len>gsize-1);
	dataword[len]='\0';
	
	cout<<"Syndrome is : "<<dataword<<endl;
	
	return 0;
}
