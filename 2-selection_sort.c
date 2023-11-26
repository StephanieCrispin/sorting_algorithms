#include "sort.h"

/***
 * selection-sort -> Sorts an array by checking for the
 * last item and swapping it with the ordered part of
 * array
 * @array: Th array to be sorted.
 * @size: The size of my array.
 */

void selection_sort(int *array, size_t size)
{

    size_t i, j, length = size;
    size_t min_int;
    if (!array || size < 2)
        return;

    for (i = 0; i < (length - 1); i++)
    {
        min_int = i;
        for (j = (i + 1); j < length; j++)
            if (array[j] < array[min_int])
                min_int = j;
        if (min_int != i)
            swap_integers(&array[min_int], &array[i]);
        print_array(array, size);
    }
}