void merge(int arr[], int p, int q, int r);
void merge_sort(int arr[], int p, int r);

void merge(int arr[], int p, int q, int r)
{
	int l1 = q - p + 1;
	int r1 = r - q;

	int left[l1], right[r1];

	for (int i = 0; i < l1; i++)
	{
		left[i] = arr[i + p];
	}

	for (int j = 0; j < r1; j++)
	{
		right[j] = arr[q + j + 1];
	}

	int i = 0, j = 0, k = p;

	while (i < l1 && j < r1)
	{
		if (left[i] >= right[j])
		{
			arr[k] = right[j];
			j++;
		}
		else
		{
			arr[k] = left[i];
			i++;
		}
		k++;
	}

	while (i < l1)
	{
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j < r1)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
	
	return;
}

void merge_sort(int arr[], int p, int r)
{
	if (p == r)
	{
		return;
	}

	int q = p + (r - p) / 2;

	merge_sort(arr, p, q);
	merge_sort(arr, q + 1, r);
	merge(arr, p, q, r);
	return;
}