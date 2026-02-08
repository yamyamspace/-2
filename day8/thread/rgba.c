#include <pthread.h>
#include <stdio.h>
#define ABS(X)   (X)<0?-(X):(X)

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int A_fac = 0;
int g_sum=0;
unsigned int data[256];
unsigned int result_f[256]; 
unsigned int result_i1[256]; 
unsigned int result_i2[256]; 

void calc_with_float()
{
	for (int f=0; f<256; f++)
	for (int k=0; k < 10000; k++)
	{
		pthread_mutex_lock(&mutex);
		g_sum++;
		pthread_mutex_unlock(&mutex);
		for (int i=0; i<256; i++)
		{
			result_f[i] = (int)((float) (data[i] * f) / 255.0f );
		}
	}
}

void calc_with_int2()
{
	unsigned int rb,ga;
	for (int f=0; f<256; f++)
	for (int k=0; k < 10000; k++)
	{	pthread_mutex_lock(&mutex);
                g_sum++;
                pthread_mutex_unlock(&mutex);

		for (int i=0; i<256; i++)
		{
			rb =f*((data[i]>>8)&0x00ff00ff);
			ga =f*((data[i])&0x00ff00ff);
			result_i2[i] = (rb&0xff00ff00) | ((ga&0xff00ff00)>>8);
		}
	}
}


void calc_with_int1()
{
	unsigned int r,g,b,a;
	for (int f=0; f<256; f++)
	for (int k=0; k < 10000; k++)
	{

		pthread_mutex_lock(&mutex);
                g_sum++;
                pthread_mutex_unlock(&mutex);

		for (int i=0; i<256; i++)
		{
			a = data[i]&0xff;
			r = data[i]>>24;
			g = (data[i]>>16)&0xff;
			b = (data[i]>>8)&0xff;
			result_i1[i] = (((r*f)>>8)<<24) | (((g*f)>>8)<<16) 
				| (((b*f)>>8)<<8) | ((a*f)>>8) ;
		}
	}
}

int main()
{
	pthread_t  thread_f, thread_i1, thread_i2;
	int result_i1, result_i2, result_f;
	int i;
	for (i=0; i < 256; i++)
		data[i] = i << 8 | i << 16 | i << 24 | i;
	g_sum=0;
	pthread_create(&thread_i1, NULL, calc_with_int1, NULL);
	pthread_create(&thread_i2, NULL, calc_with_int2, NULL);
	pthread_create(&thread_f, NULL, calc_with_float, NULL);
	
	printf("Three thread started\n");
	pthread_join(thread_i1, &result_i1);
	printf("Three thread i1 finished\n");
	pthread_join(thread_i2, &result_i2);
	printf("Three thread i2 finished\n");
	pthread_join(thread_f, &result_f);
	printf("Three thread f finished\n");

	printf("%d -  %d\n", A_fac, g_sum);

}


