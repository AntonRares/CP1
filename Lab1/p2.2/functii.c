#include <stdio.h>
#include <math.h>
#include "functii.h"
double f1(double x)//ex2.2
{
	double rez=sin(exp(2*x)+3);
	return rez;
}
double integralaTrapez(double a,double b,unsigned int n,double (*pf)(double))
{
	double sum;
	double x;
	double dx;
	double esp=1e-4;
	
	dx=(b-a)/n;
	for(x=a+dx;fabs(x+dx-b)>esp;x+=dx)
	{
		sum+=((*pf)(x));
	}
	sum*=dx;
	
	return sum;
}
