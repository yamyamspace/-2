#include <stdio.h>
int main()
{
	int arr[3] = {100,200,300};
	int * p =arr;
	int a = 0;
	a = *p + *++p;
	printf("%d\n", a);
	int l=0;
	printf("%d\n", l++ + 10*l++ + 100*++l); //310
}
