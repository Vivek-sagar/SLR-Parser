#include <stdio.h>
#include <omp.h>

int main()
{
	int count = 10000;
	int a[10000];
	omp_set_num_threads(4); 
	#pragma omp parallel for 
	for (int i = 0; i < count; ++i)
	{
		a[i] = 56*i;
	}
	return 0;
}