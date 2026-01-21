#include <stdio.h>

void mul2s(unsigned int *x, int exp)
{
	//unsigned int a = *x;  //copy for reuse
	//a = a & (0x7f400000); //bit masking
	//a = a + (exp << 23);
	//*x = ( (*x) && (~0x7f400000) ) + a;
	
	if( (exp + (((*x) & 0x7fffffff)>>23) < 0) || (exp + (((*x) & 0x7fffffff)>>23) > 255) ) return;	// if exponent is 0 or overflow
	*x = (*x) + (exp <<23);
}
int main()
{
	float fa =2.333;
	mul2s((void *)(&fa), 3); // don't know pointer type : void *
	printf("2.333 x 8 = %f\n", fa);
}
