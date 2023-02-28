#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 *
 * @array: A pointer to the first element of the sorted array.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree,
 *         or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    /* Get the middle element and make it the root */
    int mid = size / 2;
    avl_t *root = binary_tree_node(NULL, array[mid]);
    if (root == NULL)
        return (NULL);

    /* Recursively build the left and right subtrees */
    root->left = sorted_array_to_avl(array, mid);
    root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);

    /* Update the height and balance factor */
    root->height = 1 + MAX(binary_tree_height(root->left),
                           binary_tree_height(root->right));
    root->bf = binary_tree_balance(root);

    return (root);
}
