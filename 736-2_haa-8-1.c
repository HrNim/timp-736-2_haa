#include <stdio.h>
#include <stdlib.h>

int Hoar(int* s_arr, int first, int last)
{
	int i = first, j = last, x = s_arr[(first + last) / 2];
    	do {
        	while (s_arr[i] < x) i++;
        	while (s_arr[j] > x) j--;
       		if(i <= j) {
            		if (s_arr[i] > s_arr[j]) 
			{
				int a = s_arr[i];
				s_arr[i] = s_arr[j];
				s_arr[j] = a;	
			}
           		 i++;
           		 j--;
       		 }
    	} while (i <= j);
   	if (i < last)
        	Hoar(s_arr, i, last);
    	if (first < j)
        	Hoar(s_arr, first, j);
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
	Hoar(array, 0, n-1);
	for (int i=0; i<n; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	free(array);
	return 0;
}
