void max_heapify(int heap_arr[], int heap_size, int index);
void build_max_heap(int heap_arr[], int heap_size);
void heap_sort(int heap_arr[], int *heap_size);

void max_heapify(int heap_arr[], int heap_size, int index)
{
	while (1)
	{
		int largest = index;
		int left = (largest << 1) + 1;
		int right = (largest << 1) + 2;

		if (left < heap_size && heap_arr[left] > heap_arr[largest])
		{
			largest = left;
		}
		if (right < heap_size && heap_arr[right] > heap_arr[largest])
		{
			largest = right;
		}

		if (largest != index)
		{
			int temp = heap_arr[largest];
			heap_arr[largest] = heap_arr[index];
			heap_arr[index] = temp;

			index = largest;
		}
		else
		{
			break;
		}

	}
	return;
}

void build_max_heap(int heap_arr[], int heap_size)
{
	for (int i = (heap_size / 2) - 1; i >= 0; i--)
	{
		max_heapify(heap_arr, heap_size, i);
	}

	return;
}

void heap_sort(int heap_arr[], int *heap_size)
{
	build_max_heap(heap_arr, (*heap_size));

	for (int i = (*heap_size) - 1; i > 0; i--)
	{
		int temp = heap_arr[i];
		heap_arr[i] = heap_arr[0];
		heap_arr[0] = temp;

		(*heap_size)--;
		max_heapify(heap_arr, (*heap_size), 0);
	}

	return;
}
