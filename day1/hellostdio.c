#include <stdio.h>

int main()
{
	int a = 0;
	fscanf(stdin, "%d", &a);
	fprintf(stdout, "Out:Hello %d\n",a);
	fprintf(stderr, "ERR:Hello %d\n",a);
	return a;
}
