int binary_search(int arr[], int size, int element)
{
	int upper = size - 1, lower = 0, mid;

	while (lower <= upper)
	{
		mid = lower + (upper - lower) / 2;

		if (arr[mid] == element)
		{
			return mid;
		}
		else if (arr[mid] > element)
		{
			upper = mid - 1;
		}
		else if (arr[mid] < element)
		{
			lower = mid + 1;
		}
	}

	return -1;
}

int linear_search(int arr[], int size, int element)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == element)
		{
			return i;
		}
	}

	return -1;
}