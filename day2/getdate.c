#include <stdio.h>

int main()
{
	char buf[1024];
	FILE *pin;
	pin = popen("date", "r");
        fscanf(pin, "%s", buf);
	printf("------------------%s-------------------\n", buf);	
	return 0;
}

