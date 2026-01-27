#include <stdio.h>
#define ABS(x) ((x) < 0 ? -(x) : (x))

int add(int a, int b){ return a+b; }
int sub(int a, int b){ return a-b; }
int div(int a, int b){ return b==0?0:a/b; }
int mul(int a, int b){ return a*b; }

int main()
{
	const char *name = "yeun yim";	
	const int (*f[4])(int, int) = {add, sub, mul, div} ;
	int fval=0, a=0,b=0;
	scanf("%d %d %d", &fval, &a,&b);
	if(fval>3) fval=0; //fval >=4 -> default = add;
	//fval 0: add....
	printf("%d\n", f[fval](a,b));
}
