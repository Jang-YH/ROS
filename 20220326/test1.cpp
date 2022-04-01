#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 20

float datax[SIZE] = { 0, };
float datay[SIZE] = { 0, };


float dis(float datax, float datay, float a, float b) {
	return abs(a * datax - datay + b) / sqrt(a * a + 1);
}

 
float f(float a, float b) {
	float sum = 0.0;
	for (int i = 0; i < SIZE; i++) {
		sum += dis(datax[i], datay[i], a, b) / SIZE;
	}
	return sum;
}


float dfabda(float a, float b, float da) {
	return (f(a + da, b) - f(a, b)) / da;
}


float dfabdb(float a, float b, float db) {
	return (f(a, b + db) - f(a, b)) / db;
}

float EE(float x0, float x1, float y0, float y1) {
	return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

int main() {
	srand((unsigned int)time(NULL));


	for(int i = 0; i<SIZE; i++)
	{
		datax[i] = i + ((float)(rand() % 100)/100 - 0.5);
		datay[i] = i;
		printf("%f %f\n", datax[i], datay[i]);
	}
	
	int iteration = 0;
	
	float a0 = 0;
	float b0 = 0;
	
	float da = 0.01;
	float db = 0.01;
	

	float a1 = 4, b1 = 3;
	
	while (EE(a0, b0, a1, b1) > 0.0001 && iteration < 100000) {
		a0 = a1;
		b0 = b1;
		a1 -= 0.005 * dfabda(a0, b0, da);
		b1 -= 0.005 * dfabdb(a0, b0, db);
		iteration++;
	}
	printf("y = %fx + %f, iteration = %d, E = %f\n", a1, b1, iteration, EE(a0, b0, a1, b1));
	
	return 0;

}