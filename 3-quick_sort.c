#include "sort.h"

void swap_integers(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * lomuto_partition - Arranges a subset from an array into an ordered
 * collection of integers in ascending order
 * @size: size of the array.
 * @left: starting index of the subset to order.
 * @right:ending index of the subset to be order.
 *
 * Return: The partition index used.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int *pivot, above, below;

    pivot = array + right;
    for (above = below = left; below < right; below++)
    {
        if (array[below] < *pivot)
        {
            if (above < below)
            {
                swap_ints(array + below, array + above);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot)
    {
        swap_ints(array + above, pivot);
        print_array(array, size);
    }

    return (above);
}

/**
 * swap_ints - Swap two integers .
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_integers(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    int part;

    if (right - left > 0)
    {
        part = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, part - 1);
        lomuto_sort(array, size, part + 1, right);
    }
}

/**
 * quick_sort - Sorts an array of integers with quicksort
 * @array:array of integers.
 * @size: size of the array.
 *
 * Description:  Prints the array after each swap of two elements
 * ,Uses the Lomuto partition scheme..
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}