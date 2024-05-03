#include <stdint.h>
#include <stdlib.h>

void swap(int* a, int* b);
int hoare_parition(int arr[], uint32_t p, uint32_t r);
int randomized_partition(int arr[], uint32_t p, uint32_t r);
int partition(int arr[], uint32_t p, uint32_t r);
void quick_sort(int arr[], uint32_t p, uint32_t r);

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

/*
int hoare_parition(int arr[], uint32_t p, uint32_t r)
{
	int x = arr[p];
	uint32_t i = p - 1;
	uint32_t j = r + 1;

	while (1)
	{
		do
		{
			j--;
		} while (arr[j] > x);

		do
		{
			i++;
		} while (arr[i] <= x);

		if (i < j)
		{
			swap(&arr[i], &arr[j]);
		}
		else
		{
			swap(&arr[p], &arr[j]);
			return j;
		}
	}
}
*/

int partition(int arr[], uint32_t p, uint32_t r)
{
	int x = arr[r];
	uint32_t i = p - 1;

	for (uint32_t j = p; j <= r - 1;j++)
	{
		if (arr[j] <= x)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[r])
	return (i + 1);
}

int randomized_partition(int arr[], uint32_t p, uint32_t r)
{
	uint32_t i = (rand() % (r - p + 1)) + p;
	swap(arr[i], arr[r]);
	partition(arr, p, r);
}

void quick_sort(int arr[], uint32_t p, uint32_t r)
{
	if (p < r)
	{
		/* Remove the comments to run below for either randomized-quicksort or basic quicksort */

		// uint32_t q = partition(arr, p, r);
		uint32_t q = randomized_partition(arr, p, r);

		quick_sort(arr, p, q - 1);
		quick_sort(arr, q + 1, r);
	}

	return;
}

