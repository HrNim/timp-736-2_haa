#include <stdio.h>

int main () {
	int n,y=1,x, l=0;
	scanf ("%d", &n);
	while (l<n) {
		scanf ("%d", &x);
		y=y*x;
		l=l+1;
	}
	printf ("%d\n",y);
	return 0;
}
