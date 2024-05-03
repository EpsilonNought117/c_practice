#include <stdio.h>
#include <stdlib.h>

int* local_peak_finder_1d(int arr[], int size);

int* local_peak_finder_1d(int arr[], int size)
{
	if (size == 1)
	{
		return &arr[0];
	}

	int p = 0;
	int q = size - 1;
	int mid = (size - 1) / 2;

	while (p <= q)
	{
		int mid = p + (q - p) / 2;

		if (!mid)
		{	
			return (arr[mid] >= arr[1] ? &arr[mid] : &arr[1]);
		}
		else if (mid == size - 1)
		{
			return (arr[mid] >= arr[size - 2] ? &arr[mid] : &arr[size - 2]);
		}
		else if (arr[mid] < arr[mid - 1])
		{
			q = mid - 1;
		}
		else if (arr[mid] < arr[mid + 1])
		{
			p = mid + 1;
		}
		else
		{
			break;
		}
	}

	return &arr[mid];
}

int main(void)
{
	int arr[6] = { 7, 2, 9, 6, 3 };

	int* peak = local_peak_finder_1d(arr, 6);
	printf("Peak Index: %d\n", peak - &arr[0]);

	return 0;
}