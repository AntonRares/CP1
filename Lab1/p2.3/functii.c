#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "functii.h"
double f1(double x)
{
	double rez;
	rez=sin(exp(2*x)+3);
	return rez;
}
int meniu(MENU_ITEM optiuni[],unsigned int nf)
{
	int alegere;
	int i;
	for(i=0;i<nf;i++)
	{
		printf("\n%d - %s\n",i,optiuni[i].nume);
	}
	scanf("%d",&alegere);
	return alegere;
}
double integralaTrapez(double a,double b,unsigned int n,double (*pf)(double))
{
	double sum,x,dx,eps=1e-4;
	
	dx=(b-a)/n;
	sum=((*pf)(a)+(*pf)(b))/2;
	for(x=a+dx;fabs(x+dx-b)>eps;x+=dx)
	{
		sum+=(*pf)(x);
	}
	sum*=dx;
	
	return sum;
}
double integralaDreptunghi(double a,double b,unsigned int n,double (*pf)(double))
{
	double sum=0,dx=(b-a)/n,x;
	int i;
	for(i=0;i<n;i++)
	{
		x=a+i*dx;
		sum+=(*pf)(x)*dx;
	}
	return sum;
}
double integralaSimpson(double a,double b,unsigned int n,double (*pf)(double))
{
	double dx=(b-a)/n,sum=(*pf)(a)+(*pf)(b),x,rez;
	int i;
	//metoda simpson necesita un nr par de diviziuni
	if(n%2)
	{
		n++;
	}
	for(i=0;i<n;i++)
	{
		x=a+i*dx;
		if(!i%2)
		{
			sum+=2*(*pf)(x);
		}
		else
		{
			sum+=4*(*pf)(x);
		}
	}
	rez=(dx/3)*sum;
	return rez;
}
