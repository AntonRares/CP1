#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "functii.h"
double f1(double x)
{
	double rez=exp((-1)*x*x);
	return rez;
}
double f2(double x)
{
	return x;
}
double f3(double x)
{
	double rez=x*x;
	return rez;
}
double f4(double x)
{
	double rez=sqrt(1+1.0/x);
	return rez;
}
double f5(double x)
{
	double rez=x/(1+x);
	return rez;
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
void afisareIntegrale(double (*fMet[])(double,double,unsigned int,double (*pf)(double)),double (*ff[])(double))
{
	int cap[5][2],i;
	cap[0][0]=0;cap[0][1]=1;//pt integrala 1
	cap[1][0]=1;cap[1][1]=3;
	cap[2][0]=0;cap[2][1]=3;
	cap[3][0]=1;cap[3][1]=4;
	cap[4][0]=1;cap[4][1]=5;
	printf("Integrala     Met.Trapezelor     Met.Dreptunghiurilor     Met.Simpson\n");
	
	for(i=0;i<5;i++)
	{
		printf("I%d",i+1);
		printf("               %.3lf",fMet[0](cap[i][0],cap[i][1],100,ff[i]));
		printf("               %.3lf",fMet[1](cap[i][0],cap[i][1],100,ff[i]));
		printf("                  %.3lf",fMet[2](cap[i][0],cap[i][1],100,ff[i]));
		printf("\n");
	}
}














