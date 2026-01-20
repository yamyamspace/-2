#include <stdio.h>
int main()
{
	printf("size of char : %zu\n", sizeof(char));
	printf("size of short : %zu\n", sizeof(short));
	printf("size of int : %zu\n", sizeof(int));
	printf("size of long : %zu\n", sizeof(long));
	printf("size of long long : %zu\n", sizeof(long long));
	printf("size of pointer : %zu\n", sizeof(char*));
	printf("size of float : %zu\n", sizeof(float));
	printf("size of double : %zu\n", sizeof(double));
	return 0;
}
