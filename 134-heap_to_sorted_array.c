#include "binary_trees.h"

/**

heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers

@heap: A pointer to the root node of the heap to convert

@size: A pointer to store the size of the array

Return: A pointer to the sorted array of integers, NULL on failure
*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
int *array, tmp;
size_t i;

if (!heap || !size)
return (NULL);

*size = binary_tree_size(heap);
array = malloc(sizeof(int) * (*size));
if (!array)
return (NULL);

for (i = 0; i < *size; i++)
array[i] = heap_extract(&heap);

for (i = 0; i < *size / 2; i++)
{
tmp = array[i];
array[i] = array[(*size - 1) - i];
array[(*size - 1) - i] = tmp;
}

return (array);
}