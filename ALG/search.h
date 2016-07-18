#pragma once
#include <algorithm>

int binarySearch(int A[], int low, int high, int key)
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) >> 1;
		if (key < A[mid]) high = mid - 1;
		else if (key > A[mid]) low = mid + 1;
		else return mid;
	}
	return -1;
}

int binarySearchRecursive(int A[], int low, int high, int key)
{
	if (low > high) return -1;
	int mid = (low + high) >> 1;
	if (key < A[mid]) return binarySearchRecursive(A, low, mid - 1, key);
	else if (key > A[mid]) return binarySearchRecursive(A, mid + 1, high, key);
	else return mid;
}