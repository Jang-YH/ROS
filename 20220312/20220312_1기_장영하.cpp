#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	FILE* fp;
	fp = fopen("test.txt", "r");

	FILE* fs;
	

	char c[100] = {0,};

	fscanf(fp, "0x%x 0x%x 0x%x 0x%x",&c[0], &c[1], &c[2], &c[3]);
	fclose(fp);

	
	fs = fopen("test2.txt", "w");
	fprintf(fs, "%d %d %d %d \n", c[0],c[1],c[2],c[3]);
	printf("%d %d %d %d \n", c[0], c[1], c[2], c[3]);
	fprintf(fs, "%d %d %d %d", c[3], c[2], c[1], c[0]);
	printf("%d %d %d %d", c[3], c[2], c[1], c[0]);
	fclose(fs);

	return 0;
}