#include <stdio.h>

static int hello_global_a;
int global_b;
int *g_p_f_b;

int f(int * a)
{
	int b =10;
	*a = 100;
	g_p_f_b = &b;
	printf("in f() = %d %d\n", *(a+1), *(a-1));
	return (*a)*b;
}

int main()
{
	int a=0, b=1;
	f(&a);
	printf("%d\n", *g_p_f_b);

	hello_global_a=1; global_b=2;
	printf("%d - %d %d\n", a, hello_global_a,global_b);
	return 0;
}
