#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "functii.h"
int main(void)
{
	double a,b,rez;
	unsigned int n;
	int alegere;
	MENU_ITEM optiuni[]={
	{"calcul prin metoda trapezelor",integralaTrapez},
	{"calcul prin metoda dreptunghiurilor",integralaDreptunghi},
	{"calcul prin metoda Simpson",integralaSimpson}};
	
	printf("nr de diviziuni:");
	scanf("%u",&n);
	printf("\n capetele de integrare:");
	scanf("%lf %lf",&a,&b);
	alegere=meniu(optiuni,3);
	switch (alegere)
	{
		case 0:
			rez=integralaTrapez(a,b,n,f1);
			break;
		case 1:
			rez=integralaDreptunghi(a,b,n,f1);
			break;
		case 2:
			rez=integralaSimpson(a,b,n,f1);
			break;
	}
	printf("Rezultatul este :%lf",rez);
	return 0;
}
