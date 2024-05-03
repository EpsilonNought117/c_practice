#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100

int global_1d_peak_finder(int arr[], int base_offset, int skip_size, int size);
int local_2d_peak_finder(int arr[], int rows, int columns);

int global_1d_peak_finder(int arr[], int base_offset, int skip_size, int size)
{
	int max_index = (skip_size == 1 ? base_offset * size : base_offset);

	for (int i = max_index; i < (size * skip_size); i += skip_size)
	{
		max_index = (arr[max_index] > arr[i] ? max_index : i);
	}

	return max_index;
}

int local_2d_peak_finder(int arr[], int rows, int columns)
{
	int larger = (rows > columns ? rows : columns);
	int p = 0;
	int q = larger - 1;
	int local_2d_peak = 0;

	if (larger == rows)
	{
		while (1)
		{
			int skip_size = 1;
			int mid_row_base_index = (p + (q - p) / 2) * columns;

			local_2d_peak = global_1d_peak_finder(arr, mid_row_base_index, skip_size, columns);

			int i = mid_row_base_index;
			int j = (local_2d_peak % columns);

			if (!i)
			{
				return (arr[local_2d_peak] > *(arr + (i + 1) * columns + j) ? local_2d_peak : (i + 1) * columns + j);
			}
			else if (i == larger - 1)
			{
				return (arr[local_2d_peak] > *(arr + (i - 1) * columns + j) ? local_2d_peak : (i - 1) * columns + j);
			}
			else if (arr[local_2d_peak] < *(arr + (i - 1) * columns + j))
			{
				q = mid_row_base_index - 1;
			}
			else if (arr[local_2d_peak] < *(arr + (i + 1) * columns + j))
			{
				p = mid_row_base_index + 1;
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		while (1)
		{
			int skip_size = columns;
			int mid_column_base_index = (p + (q - p) / 2);

			local_2d_peak = global_1d_peak_finder(arr, mid_column_base_index, skip_size, rows);

			int j = mid_column_base_index;
			int i = (local_2d_peak - j) / columns;

			if (!j)
			{
				return (arr[local_2d_peak] > *(arr + i * columns + j + 1) ? local_2d_peak : i * columns + j + 1);
			}
			else if (j == larger - 1)
			{
				return (arr[local_2d_peak] > *(arr + i * columns + j - 1) ? local_2d_peak : i * columns + j - 1);
			}
			else if (arr[local_2d_peak] < *(arr + i * columns + j - 1))
			{
				q = mid_column_base_index - 1;
			}
			else if (arr[local_2d_peak] < *(arr + i * columns + j + 1))
			{
				p = mid_column_base_index + 1;
			}
			else
			{
				break;
			}
		}
	}

	return local_2d_peak;
}

// TEST CODE BELOW

int main(void)
{
	int rows = 0;
	int columns = 0;

	printf("Enter number of rows in 2D Matrix: ");
	scanf("%d", &rows);
	printf("Enter number of columns in 2D Matrix: ");
	scanf("%d", &columns);

	printf("\n");

	int* arr = (int*)malloc(sizeof(int) * columns * rows);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			*(arr + j + i * columns) = rand() % MAX_NUM;
			printf("%5d ", *(arr + j + i * columns));
		}
		printf("\n");
	}

	int local_2d_peak = local_2d_peak_finder(arr, rows, columns);

	int row_num = local_2d_peak / columns;
	int column_num = local_2d_peak % columns;

	printf("\nROW: %d, COLUMN: %d, ELEMENT_VAL: %d\n", row_num + 1, column_num + 1, arr[local_2d_peak]);
	free(arr);
	return 0;
}