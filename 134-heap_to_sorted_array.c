#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a binary max heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    if (heap == NULL || size == NULL)
        return (NULL);

    int *sorted_array = malloc(heap->size * sizeof(int));
    if (sorted_array == NULL)
        return (NULL);

    heap_extract_all(heap, sorted_array);
    *size = heap->size;
    return (sorted_array);
}

/**
 * heap_extract_all - Extracts all elements of a binary max heap
 * @heap: Pointer to the root node of the heap to extract
 * @sorted_array: Array to store the extracted elements
 */
void heap_extract_all(heap_t *heap, int *sorted_array)
{
    while (heap != NULL)
        sorted_array[--heap->size] = heap_extract(&heap);
}

/**
 * heap_extract - Extracts the maximum value from a binary max heap
 * @heap: Pointer to the root node of the heap to extract
 *
 * Return: The maximum value in the heap
 */
int heap_extract(heap_t **heap)
{
    if (*heap == NULL)
        return (0);

    int value = (*heap)->n;
    heap_t *temp = *heap;
    if ((*heap)->left == NULL && (*heap)->right == NULL)
        *heap = NULL;
    else if (heap_height((*heap)->left) > heap_height((*heap)->right))
        *heap = (*heap)->left;
    else
        *heap = (*heap)->right;

    if (*heap != NULL)
        (*heap)->parent = NULL;

    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    free(temp);

    return (value);
}

/**
 * heap_height - Gets the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree
 */
size_t heap_height(const heap_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t left_height = heap_height(tree->left);
    size_t right_height = heap_height(tree->right);
    return (1 + (left_height > right_height ? left_height : right_height));
}
