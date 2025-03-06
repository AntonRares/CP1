#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "functii.h"

int main()
{
	double (*fMet[3])(double,double,unsigned int,double (*pf)(double));
	double (*ff[5])(double);
	
	fMet[0]=&integralaTrapez;
	fMet[1]=&integralaDreptunghi;
	fMet[2]=&integralaSimpson;
	
	ff[0]=&f1;
	ff[1]=&f2;
	ff[2]=&f3;
	ff[3]=&f4;
	ff[4]=&f5;
	
	afisareIntegrale(fMet,ff);
	return 0;
}
