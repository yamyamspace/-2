#include <stdio.h>
int main()
{
	int a =0;
	int result;
	int attempts =0;
	const int MAX_TRIES =10;

	while (attempts<MAX_TRIES){

		result = fscanf(stdin,"%d", &a);
		if( result ==1){
			fprintf(stdout, "STDOUT: %d\n", a);
			break;
		}else{
			fprintf(stderr, "Stderr retry. Type integer\n");

			int c;
			while ((c=fgetc(stdin))!='\n' && c!=EOF){}
		}
		attempts++;
	}
	if (attempts == MAX_TRIES && result !=1){
		fprintf(stderr, "out of tries quit program\n");
		return 1;
	}
		fprintf(stdout, "OUT: Hello %d\n",a);
	return 0;
}
