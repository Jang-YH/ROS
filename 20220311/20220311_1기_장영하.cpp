#include <stdio.h>
#include <string.h>

int main()
{
	FILE* fp = fopen("test.txt", "w"); //test.txt ���Ϸ� ����

	int num, i;
	unsigned char data[sizeof(int)];

	printf("������ �Է��Ͻÿ� : ");
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