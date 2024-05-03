#include <stdio.h>

void insertion_sort(int arr[], int size);
int binary_search_index(int arr[], int key, int p, int q);

int binary_search_index(int arr[], int key, int p, int q)
{
	int insert_index;

	while (p <= q)
	{
		insert_index = p + (q - p) / 2;
		
		if (arr[insert_index] < key)
		{
			p = insert_index + 1;
		}
		else if (arr[insert_index] > key)
		{
			q = insert_index - 1;
		}
	}

	return p + 1;
}

void insertion_sort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;

		int index = binary_search_index(arr, key, 0, j);

		while (j >= index)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}

	return;
}

int main(void)
{
	int arr[] = {4, 19, 2223, 11, 65, 55};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	insertion_sort(arr, size);
	
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}	
	printf("\n");
	
	return 0;
}