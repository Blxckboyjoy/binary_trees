#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    queue_t *queue = NULL;
    const binary_tree_t *node;

    if (tree == NULL || func == NULL)
        return;

    enqueue(&queue, (void *)tree);
    while (queue != NULL)
    {
        node = (const binary_tree_t *)dequeue(&queue);
        func(node->n);

        if (node->left != NULL)
            enqueue(&queue, (void *)node->left);
        if (node->right != NULL)
            enqueue(&queue, (void *)node->right);
    }
}
