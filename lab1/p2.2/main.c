#include <stdio.h>
#include <math.h>
#include "functii.h"

int main(void)
{
	unsigned int n;
	double a,b,val;
	
	scanf("%u %lf %lf",&n,&a,&b);
	val=integralaTrapez(a,b,n,f1);
	
	printf("REZULTATUL E: %.4lf",val);
	return 0;
}
