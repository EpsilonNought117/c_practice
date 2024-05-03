#include <stdint.h>

void swap(int* a, int* b);
void selection_sort(int arr[], uint32_t size);

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void selection_sort(int arr[], uint32_t size)
{
	for (uint32_t i = 0; i < size; i++)
	{
		uint32_t min_index = i;

		for (uint32_t j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[i])
			{
				min_index = j;
			}
		}

		if (min_index != i)
		{
			swap(arr[i], arr[min_index]);
		}
	}
}