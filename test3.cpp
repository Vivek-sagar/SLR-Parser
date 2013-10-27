#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{
	float a[30000];
	#pragma omp parallel for
	for (int i=0; i<30000; i++)
		a[i] = sin(i)*cos(i)*5234.099887;
	return 0;
}