#include binary_trees.h

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted_array;
    size_t i;

    if (heap == NULL)
        return (NULL);

    sorted_array = malloc(heap->size * sizeof(int));
    if (sorted_array == NULL)
        return (NULL);

    for (i = 0; i < heap->size; i++)
        sorted_array[i] = heap_extract(&heap);

    *size = i;
    return (sorted_array);
}
