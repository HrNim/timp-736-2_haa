#include <stdio.h>
#include <stdlib.h>

int Shells( int *array[], int n)
{
	int i,j,k;
	int t;
	for(k = n/2; k > 0; k /=2)
	for(i = k; i < n; i++)
	{
		t = (*array)[i];
		for(j = i; j>=k; j-=k)
		{
			if(t < (*array)[j-k])
			(*array)[j] = (*array)[j-k];
			else break;
		}
		(*array)[j] = t;
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
	Shells(&array, n);
	for (int i=0; i<n; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
