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
	int a =0;
	unsigned int b =-1;
	toBinaryString(buf, b);	printf("%u - \t%s\n", b, buf);

	toBinaryString(buf, 200);	printf("%d - \t%s\n", 200, buf);
	toBinaryString(buf, -201);	printf("%d - \t%s\n", -201, buf);
	toBinaryString(buf, a);		printf("%d - \t%s\n", a, buf);
	toBinaryString(buf, ~a);	printf("%d - \t%s\n", ~a, buf);
	a = -20;
	
	toBinaryString(buf, a);	printf("%d - \t%s\n", a, buf);
	toBinaryString(buf, a>>1);	printf("%d - \t%s\n", a>>1, buf);
	toBinaryString(buf, a>>2);	printf("%d - \t%s\n", a>>2, buf);
	toBinaryString(buf, a>>4);	printf("%d - \t%s\n", a>>4, buf);
	toBinaryString(buf, a>>8);	printf("%d - \t%s\n", a>>8, buf);
	toBinaryString(buf, a>>10);	printf("%d - \t%s\n", a>>10, buf);
	return 0;
}
