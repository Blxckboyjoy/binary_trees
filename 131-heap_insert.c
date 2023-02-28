#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify - Heapifies a Max Binary Heap.
 * @node: A pointer to the root node of the tree to heapify.
 */
void heapify(heap_t *node)
{
    heap_t *max = node;

    if (node->left && node->left->n > max->n)
        max = node->left;

    if (node->right && node->right->n > max->n)
        max = node->right;

    if (max != node)
    {
        node->n ^= max->n;
        max->n ^= node->n;
        node->n ^= max->n;
        heapify(max);
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    size_t size = 0, index = 0;
    heap_t *new = NULL, *node = *root;

    if (root == NULL)
        return (NULL);

    size = binary_tree_size(node);

    if (size == 0)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    for (index = 0; index < size; index++)
    {
        if ((size >> (index + 1)) == 0)
            break;

        if (index == 0)
            continue;

        if ((size >> index) & 1)
            node = node->right;
        else
            node = node->left;
    }

    if ((size >> index) & 1)
        node->right = binary_tree_node(node, value);
    else
        node->left = binary_tree_node(node, value);

    new = (size >> index) & 1 ? node->right : node->left;

    while (new->parent != NULL && new->parent->n < new->n)
    {
        new->n ^= new->parent->n;
        new->parent->n ^= new->n;
        new->n ^= new->parent->n;
        new = new->parent;
    }

    heapify(*root);

    return (new);
}
