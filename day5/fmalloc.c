#include <stdio.h>
#include <stdlib.h>

int fmalloc(int **p, int count)
{
	printf("%p %p\n", p, &p);
	*p = malloc(count*4);
	//int *q = *p;
	//*q++ = 0;	*q++ = 1;	*q++ = 2;	*q++ = 3;
	//*q++ = 4;	*q++ = 5;	*q++ = 6;	*q++ = 7;
	//*q++ = 8;	*q = 9;
	
	//(*p)[2] = 100;
	//(*p)[3] = 200;
}
	
int main()
{
	int *pi = NULL;
	printf("%p %p \n", pi, &pi);
	fmalloc(pi, 10);
	pi[5]=500;
	for (int i=0;i<10;i++){
		printf("%d", *pi++);
	}
	printf("\n");	
}

