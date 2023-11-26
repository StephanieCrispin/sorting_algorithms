#include "sort.h"
void swap_integers(int *a, int *b);

/**
 * swap_integers -> swaps two integers
 * @a: Memory location of first integer
 * @b: Memory location of second integer
 */

void swap_integers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
 * bubble_sort -> Sorts an array of integers according to the bubble sort algorithm
 *
 * @array: My array argument of integers
 * @size: the size of my array;
 */
void bubble_sort(int *array, size_t size)
{
    size_t length = size, i;
    bool swapped = false;

    if (!array || size < 2)
        return;

    while (swapped == false)
    {
        swapped = true;
        for (i = 0; i < (length - 1); i++)
        {
            if (array[i] > array[i + 1])
            {
                swap_integers(&array[i], &array[i + 1]);
                print_array(array, size);
                swapped = false;
            }
        }
        length--;
    }
}