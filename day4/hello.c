extern int printf (const char *__restrict __format, ...);
#define __MY_DEBUG

int main(){
#ifdef __MY_DEBUG
	printf("Hello World!\n" "aaaa\n");
#endif
	return 0;
}
