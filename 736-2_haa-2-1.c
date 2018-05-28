#include <stdio.h>

int main () {
	int n,x, l=0;
	double z=0,y=0;
	scanf ("%d", &n);
	while (l<n) {
		scanf ("%d", &x);
		z=z+((double)x/(double)n);
		l=l+1;
	}
	printf ("%lf\n",z);
	return 0;
}
