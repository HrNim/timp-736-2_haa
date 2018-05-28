#include <stdio.h>
#include <stdlib.h>

int pyr1 (int *array, int left, int right)
{
	int i, j, x=array[left];
	i = left; j = 2*left;
	if (j<right && array[j+1]<array[j])
		j++;
	while (j<=right && array[j]<x)
	{
		array[i] = array[j];
		i = j;
		j *= 2;
		if (j<right && array[j+1]<array[j])
			j++;
	}
	array[i] = x;
	return 0;
}

int PyrSort (int *array, int n)
{
	int left = n/2+1, right=n-1, x;
	while (left>0)
		pyr1 (array, --left, right);
	while (right>0)
	{
		x = array[0];
		array[0] = array[right];
		array[right] = x;
		pyr1 (array, left, --right);
	}
	return 0;
}
int print(int array[],int n)
{
	for (int i=0; i<n; ++i)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	return 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	int *array = malloc(sizeof(int[n]));
	for (int i=0; i<n; ++i)
	{
		int val;
		scanf("%d", &val);
		array[i] = val;
	}
	print(array,n);
	PyrSort(array,n);
	print(array,n);
	free(array);
	return 0;
}
