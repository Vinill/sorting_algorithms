#include "sort.h"
int partition(int *array, int low, int high, int size);
void r_quick(int *arr, int low, int high, int size);
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	r_quick(array, 0, size - 1, size);
}


/**
 * r_quick - sorts an array of integers recursion
 * @arr: array
 * @low: index low
 * @high: index high
 * @size: size
 */
void r_quick(int *arr, int low, int high, int size)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high, size);
		r_quick(arr, low, pi - 1, size);
		r_quick(arr, pi + 1, high, size);
	}

}
/**
 * partition - takes last elem as pivot and places
 * all smaller to left and all grater to right
 * @array: array
 * @low: index low
 * @high: index high
 * @size: size
 * Return: pivot position
 */
int partition(int *array, int low, int high, int size)
{
	int temp, pivot = array[high], i = low - 1, j = 0;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high]  = temp;
	if (array[i + 1] != array[high])
		print_array(array, size);
	return (i + 1);
}
