#pragma once
#include <algorithm>

//此函数接受一个从0开始的整数数组
void insertSort(int* A, int length)
{
	for (int j = 1;j < length;++j)
	{
		int key = A[j];
		//Insert A[j] into the sorted sequence A[0,...j-1]
		int i = j - 1;
		while (i >= 0 && A[i]>key)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}
//另一种赋值方法
void insertSortAnother(int A[], int length)
{
	for (int j = 1;j < length;++j)
	{
		int k = j;
		int i = j - 1;
		while (i >= 0 && A[i] > A[k])
		{
			std::swap(A[i], A[k]);
			k = i--;
		}
	}
}

void quickSort(int A[], int low, int high)
{
	if (low >= high) return;
	int i = low;
	int j = high;
	int p = A[high];
	do
	{
		while (A[i] <= p)
		{
			++i;
		}
		while (i < j&&A[j] >= p)
		{
			--j;
		}
		std::swap(A[i], A[j]);
	} while (i < j);
	A[high] = A[i];
	A[i] = p;
	quickSort(A, low, i - 1);
	quickSort(A, i + 1, high);
}
