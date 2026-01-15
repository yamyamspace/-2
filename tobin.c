#include <stdio.h>

int toBinaryString(char *buf, int a)
{
	for(int i=31; i>=0;i--){
		buf[31-i]=((a>>i)&1)? '1':'0';
	}
	buf[32]='\0';
	return 0;
}
int main(){
	char buf[256];
	toBinaryString(buf, 200);
	printf("%d = %s\n", 200, buf);
	return 0;
}
