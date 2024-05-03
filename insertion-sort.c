#include <stdio.h>

void insertion_sort(int arr[], int size);

int main(void)
{
	int arr[] = { 2, 5, 77, 192, 234, 72, 44, 123, 95, 12, 199, 20000, 11};
	int size = sizeof(arr) / sizeof(arr[0]);

	insertion_sort(arr, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}

void insertion_sort(int arr[], int size)
{
	int compares = 0;
	int swaps = 0;

	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
			compares++;
			swaps++;
		}

		arr[j + 1] = key;
		swaps++;
	}

	printf("Compares: %d\nSwaps: %d\n", compares, swaps);
	return;
}