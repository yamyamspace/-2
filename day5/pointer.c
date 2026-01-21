#include <stdio.h>
int main()
{
	int b = 100;
	int * a = NULL;
	int (*pa) = NULL;
	int * qa = NULL;

	printf("%d %d \n", *&b, *(&b));
	printf("%p %p %p %p\n", &b, a, pa, qa);
	a = pa = qa = &b;
	printf("%p %p %p %p\n", &b, a, pa, qa);
}
