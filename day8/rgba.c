#include <stdio.h>

#define ABS(X)   (X)<0?-(X):(X)
int g_sum=0;
int A_fac =0;

#if 0
void calc_with_float(unsigned char result[256], unsigned char data[256], int r)
{
	for (int i=0; i<256; i++)
	{
		result[i] = (int)((float) (data[i] * r) / 255.0f );
	}
}
#endif

void calc_with_int1(unsigned int result[256], unsigned int data[256], int f)
{
	unsigned int r,g,b,a;
	for (int i=0; i<256; i++)
	{
		a=data[i] & 0xff;
		r=data[i]>>24;
		g=(data[i]>>16)&0xff;
		b=(data[i]>>8)&0xff;
		result[i] = (((r*f)>>8)<<24) | (((g*f)>>8)<<16) | (((b*f)>>8)<<8) | ((a*f)>>8);
	}
}
#define RGBmulF(X,F)	(((F)*(((X)>>8)&0XFF00FF))&&0Xff00ff00) | \
			((((F)*(((X))&0x00ff00ff))&0xff00ff00)>>8)
void calc_with_int2(unsigned int result[256], unsigned int data[256], int f)
{
    for (int i = 0; i < 256; i++)
    {
        unsigned int x = data[i];

        unsigned int rb = x & 0xFF00FF00;  // r, b
        unsigned int ga = x & 0x00FF00FF;  // g, a

        rb = (rb * f) >> 8;
        ga = (ga * f) >> 8;

        result[i] = (rb & 0xFF00FF00) | (ga & 0x00FF00FF);
    }
}
#if 0
void compare_abs_sum(unsigned char a[256], unsigned char b[256])
{
	int diff; 
	for (int i=0; i<256; i++)
	{
		diff = a[i] - b[i]; 
		g_sum+= ABS(diff);
	}
	return;
}
#endif


int main()
{
	unsigned int data[256], f_result[256];
	unsigned int i_result[256];
        int	diff[256];
	int i;
	for (i=0; i < 256; i++)
		data[i] = i<<8 | i<<16 | i<<24 | i;
	for (int k=0; k < 10000; k++)
	{
		g_sum=0;

		for (i=0; i < 256; i++)
		{
			//calc_with_int1(i_result, data, i);
		        //calc_with_int2(i_result, data, i);
			for(int j=0;j<256;j++)
			{
				RGBmulF(data[j],i);
			}	
		}
	
	}
		printf("%d -  %d\n", A_fac, g_sum);

}


