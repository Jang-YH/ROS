#include <stdio.h>
#include <math.h>
int  Resistor_value[5] = { -1, };
char Resistor_color[13] = { 'B','b','r','o','y','g','u','p','g','w','G','S','N' };
// 0   1   2   3   4   5   6   7   8   9   10  11  12  No color = N
int main(void)
{
	int no_band = 0; // �ݵ�� ���� ����� �Բ� �ʱ�ȭ �� ��
	int i = 0;
	char temp_color = ' ';
	int resistor_value = -1;
	int decimal = 0;
	int tolerance = 0;
	printf("----------------------------------------------\n");
	printf("------- Resistor Color code Conversion -------\n");
	printf("----------------------------------------------\n");

	do
	{
		printf(" Input number of reisitor band (4,5)   :  ");
		scanf("%d", &no_band);
		printf("\n");
	} while ((no_band < 4) || (no_band > 5));

	printf(" no_band  :  %d \n\n", no_band);


	for (i = 0; i < no_band - 1; i++)
	{
		printf("%d ��° Į�� �Է��ϼ���.   ", i + 1);
		scanf("%*c%c", &temp_color);  // \n�� ����� ���

		for (int j = 0; j < 13; j++)
		{
			if (Resistor_color[j] == temp_color) Resistor_value[i] = j;
		}
		if (Resistor_value[i] == -1)
		{
			printf("�߸� �Է��Ͽ����ϴ�.\n");
			i--;
		}
	}


	printf("������ ���� Į�� �Է��ϼ���.   ", i + 1);

	scanf("%*c%c", &temp_color);  // \n�� ����� ���


	for (int j = 0; j < 13; j++)
	{
		if (Resistor_color[j] == temp_color) Resistor_value[i] = j;  // �� �� �Է� ���� ���� ó�� �κ��� �߰��ϼ���.
	}


	resistor_value = 0;


	/*
	for (i = 0 ; i < no_band; i++)
	{
		printf("%d %d \n", i, Resistor_value[i]);
	}
	*/


	if (no_band == 4)
	{
		//
		resistor_value = (Resistor_value[0] * 10 + Resistor_value[1]) * (int)pow(10.0, (double)Resistor_value[2]);
		if (Resistor_value[3] == 12) tolerance = 20;
		else                    	 tolerance = (Resistor_value[3] - 9) * 5;
	}
	if (no_band == 5)
	{
		//
		resistor_value = (Resistor_value[0] * 100 + Resistor_value[1] * 10 + +Resistor_value[2]) * (int)pow(10.0, (double)Resistor_value[3]);
		if (Resistor_value[4] == 12) tolerance = 20;
		else                    	 tolerance = (Resistor_value[4] - 9) * 5;
	}

	printf("���װ��� = %d �Դϴ�.\n", resistor_value);
	printf("�������� = %3d %%�Դϴ�.\n\n", tolerance);
}