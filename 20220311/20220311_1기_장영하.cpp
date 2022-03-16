#include <stdio.h>
#include <string.h>

int main()
{
	FILE* fp = fopen("test.txt", "w"); //test.txt 파일로 저장

	int num, i;
	unsigned char data[sizeof(int)];

	printf("정수를 입력하시오 : ");
	scanf("%d", &num);

	memcpy(data, &num, sizeof(int));

	fprintf(fp,"MSB - > LSB : ");
	printf("MSB - > LSB : ");
	for (i = 0; i < 4; i++) {
		fprintf(fp, "0x%0.2x ", data[i]);
		printf("0x%0.2x ", data[i]);
	}
	
	fprintf(fp, "\n\n");
	printf("\n\n");

	fprintf(fp,"LSB - > MSB : ");
	printf("LSB - > MSB : ");
	for (i = 3; i >= 0 ; i--) {
		fprintf(fp, "0x%0.2x ", data[i]);
		printf("0x%0.2x ", data[i]);
	}
	
	return 0;
}