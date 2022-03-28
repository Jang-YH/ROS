#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	
	for(int i = 0; i<argc; i++)
		printf("argc[%d] : %s\n", i, argv[i]);
	
	printf("%d + %d = %d \n",a, b , a+b);
	printf("%d - %d = %d \n",a, b , a-b);
	printf("%d * %d = %d \n",a, b , a*b);
	printf("%d / %d = %d \n",a, b , a/b);
	
	
	return 0;
}
