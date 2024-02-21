#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 20
int InterSearch(int n, int arr[], int key)
{
	int left = 0;
	int right = n - 1;
	
	while (left <= right)
	{
		int mid = (key - arr[left]) / (arr[right] - arr[left]) * (right - left);
		if (arr[mid] > key)
			right = mid - 1;
		else if (arr[mid] < key)
			left = mid + 1;
		else
			return mid;
			
	}
}  //²åÖµ²éÕÒ
