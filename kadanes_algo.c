#include <limits.h>

int max_sub_array(int arr[], int size);

int max_sub_array(int arr[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;
	int start = 0, end = 0, s = 0;

	for (int i = 0; i < size; i++)
	{
		max_ending_here += arr[i];

		if (max_ending_here > max_so_far)
		{
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}

		if (max_ending_here < 0)
		{
			max_ending_here = 0;
			s = i + 1;
		}
	}

	return max_so_far;
}