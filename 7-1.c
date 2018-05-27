#include <stdio.h>
#include <stdlib.h>

int comb( int *array[], int n)
{
	int counter = 0;
	double dstep = n-1;
	int step = (int) dstep;
		while(step >= 1)
		{
			for (int i=0; i<( n-step ); ++i)
			{
				if( (*array)[i] < (*array)[i+step] )
				{
					int tmp = (*array)[i];
					(*array)[i] = (*array)[i+step];
					(*array)[i+step] = tmp;
				}
			}
			counter++;
			dstep = dstep/1.2473309;
			step = (int) dstep;
		}

		for (int i=0; i<(n-1); ++i)
		{
			int per = 0;
			if( ((*array)[i] < (*array)[i+1]) )
			{
				int tmp = (*array)[i];
				(*array)[i] = (*array)[i+1];
				(*array)[i+1] = tmp;
				per =1;
				counter++;
			}
			if (per == 0) break;
		}
}

int main()
{
	int n;
	int *array = malloc(sizeof(int[n]));
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		int val;
		scanf("%d",&val);
		array[i] = val;
		printf("%d ", array[i]);
	}
	printf("\n");
	comb(&array, n);
	for (int i=0; i<n; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}