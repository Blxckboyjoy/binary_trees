#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 *         NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    binary_tree_t *ancestor;
    const binary_tree_t *node1, *node2;

    if (first == NULL || second == NULL)
        return (NULL);

    node1 = first;
    while (node1 != NULL)
    {
        node2 = second;
        while (node2 != NULL)
        {
            if (node1 == node2)
                return ((binary_tree_t *)node1);
            node2 = node2->parent;
        }
        node1 = node1->parent;
    }

    return (NULL);
}
