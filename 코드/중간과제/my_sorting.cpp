#include "my_sorting.h"

#define NUM 10

// 계수 정렬 활용 기수 정렬 구현
void CountingSort(int arr[], int size, int exp)
{
	int output[50000];
	const int BUCKET_SIZE = NUM * 2 - 1; 
	const int OFFSET = NUM - 1;          
	int count[BUCKET_SIZE] = { 0 };       

	for (int i = 0; i < size; i++)
	{
		int digit = (arr[i] / exp) % NUM;
		count[digit + OFFSET]++; 
	}

	for (int i = 1; i < BUCKET_SIZE; i++) 
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		int digit = (arr[i] / exp) % NUM;
		int bucket_index = digit + OFFSET; 
		output[count[bucket_index] - 1] = arr[i];
		count[bucket_index]--;
	}

	for (int i = 0; i < size; i++)
		arr[i] = output[i];
}

// 기수 정렬
void RadixSort(int arr[], int size)
{
	
	for (int exp = 1; exp < 2000000000; exp *= NUM) 
	{
		CountingSort(arr, size, exp);
		if (exp > 200000000)
			break;
	}
}

// 두 배열 경계 정렬(병합정렬)
void MergeSort(int* arr1, int* arr2, int size)
{
	int i = size - 1; 
	int j = 0;        

	while (i >= 0 && j < size)
	{
		if (arr1[i] > arr2[j]) {
			int temp = arr1[i];
			arr1[i] = arr2[j];
			arr2[j] = temp;

			i--;
			j++;
		}
		else {
			break;
		}
	}
}

void Sorting(int* a, int* b, int* c, int arraysize)
{
	//개별정렬
	RadixSort(a, arraysize);
	RadixSort(b, arraysize);
	RadixSort(c, arraysize);

	// A~B, B~C 경계 정렬 
	MergeSort(a, b, arraysize);
	MergeSort(b, c, arraysize);

	// 복구
	RadixSort(a, arraysize);
	RadixSort(b, arraysize);
	RadixSort(c, arraysize);
}
