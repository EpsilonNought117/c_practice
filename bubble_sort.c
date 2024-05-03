#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b);
void bubble_sort(int arr[], int size);

int main(void)
{
    int arr[] = {11, 9, 13, 65, 42, 33, 99, 23, 1, 0, 0, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size - i; j++)
        {
            if (arr[j] <= arr[j - 1])
            {
                swap(&arr[j], &arr[j - 1]);
            }
        }
    }

    return;
}