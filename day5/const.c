#include <stdio.h>
int main()
{
	int const w=100;
	int const a=100 ,b=200 ,c=300;
	int const * const pa=&a;
        int const * const pb=&b;
        int const * const pc=&c;
	int * ppp;
	ppp = (int *)(pc); //change const int * to int *
	*ppp = 400;	
	printf("%d %d %d\n", a,b,c);
	printf("%d %d %d\n", *pa,*pb,*pc);
	return (w);
}
