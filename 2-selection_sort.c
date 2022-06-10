#include "sort.h"

/**
 * selection_sort - function that sorts an array of
 * integers in ascending order using the Selection sort algorithm
 *
 * @array: Elements array
 *
 * @size: Array size
 */
void selection_sort(int *array, size_t size)
{
	size_t act, mc, j;
	int temp;

	for (act = 0; act < size - 1; act++)
	{
		mc = act;
		j = act + 1;
		while (j < size)
		{
			if (array[j] < array[mc])
			{
				mc = j;
			}

			j++;
		}
		temp = array[act];
		array[act] = array[mc];
		array[mc] = temp;

		if (mc != act)
			print_array(array, size);
	}
}
