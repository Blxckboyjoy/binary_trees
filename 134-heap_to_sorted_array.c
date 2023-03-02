#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers, or NULL if heap is NULL or empty
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array = NULL;
    size_t i, n;

    if (heap == NULL)
        return (NULL);

    n = binary_tree_size(heap);
    array = malloc(n * sizeof(int));
    if (array == NULL)
        return (NULL);

    for (i = 0; i < n; i++)
        array[i] = heap_extract(&heap);

    *size = n;
    return (array);
}
