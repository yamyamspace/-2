#include <stdio.h>

int main()
{
	int a = 0;
	char buf[256];
	setvbuf(stdout, buf, _IONBF, 64); 
	setvbuf(stderr, buf, _IONBF, 64);
	for (int i=0;i<1000;i++)
	{			
		fscanf(stdin, "%d", &a);
		if (a==999) break;
		fprintf(stdout, "Out:Hello %d\n",a);
		//fflush(stdout);
		fprintf(stderr, "ERR:Hello %d--",a);
	}
	return a;
}

