#include <stdio.h>
int ga=0, gb=1;

int fff(int a, int b){
	static int sa =300;
	return ++sa;
}
int f(int a, int b)
{
	static int sa=100;
	int c=100, d=200;
	sa++;
	printf("f c %d %p\n", c, &c);
	printf("f d %d %p\n", d, &d);
	printf("f sa %d %p\n", sa, &sa);
	printf("f ga %d %p\n", ga, &ga);
	printf("f gb %d %p\n", gb, &gb);
	return (a+b+sa+c+d);
}
int main()
{
	int a=200;
	f(100,a++);
	f(200,a++);
	f(300,a++);
	f(400,a++);
	printf("main a %d %p\n", a, &a);
}
