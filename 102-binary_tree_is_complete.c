#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    int is_complete = 1;
    const binary_tree_t *node;
    queue_t *queue = NULL;

    if (tree == NULL)
        return (0);

    enqueue(&queue, (void *)tree);
    while (queue != NULL)
    {
        node = (const binary_tree_t *)dequeue(&queue);
        if (node == NULL)
        {
            while (queue != NULL)
            {
                node = (const binary_tree_t *)dequeue(&queue);
                if (node != NULL)
                {
                    is_complete = 0;
                    break;
                }
            }
            break;
        }
        enqueue(&queue, (void *)node->left);
        enqueue(&queue, (void *)node->right);
    }

    free_queue(&queue);
    return (is_complete);
}
