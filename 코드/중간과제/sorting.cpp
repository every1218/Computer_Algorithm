#define _CRT_SECURE_NO_WARNINGS
#define MSIZE 50000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_sorting.h"

void SetArray(int* a, int* b, int* c, int arraysize);
void PrintArray(int* a, int* b, int* c, int arraysize);



int main()
{
	int a[MSIZE];
	int b[MSIZE];
	int c[MSIZE];
	clock_t start, finish;
	double cal_sec = 0.0;
	srand(time(NULL));

	SetArray(a, b, c, MSIZE);
	start = clock();
	Sorting(a, b, c, MSIZE);
	finish = clock();
	cal_sec = (double)(finish - start) / CLOCKS_PER_SEC;

	PrintArray(a, b, c, MSIZE);
		printf("\n%f 초가 소요되었습니다..\n", cal_sec);

	return 0;
}



void SetArray(int* a, int* b, int* c, int arraysize)
{
	int i = 0;
	for (i = 0; i < arraysize; i++)
	{
		a[i] = rand() * rand();
		b[i] = rand() * rand();
		c[i] = rand() * rand();
	}
}



void PrintArray(int* a, int* b, int* c, int arraysize)
{
	for (int i = 0; i < arraysize; i++)
	{
		if( i % 100 == 0)
			printf("%10d\n", a[i]);
	}
}