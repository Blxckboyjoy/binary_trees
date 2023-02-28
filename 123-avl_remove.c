#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: A pointer to the root node of the tree
 * @value: The value to remove from the tree
 *
 * Return: A pointer to the new root node of the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *node, *parent, *tmp, *left, *right;

    /* Base Case */
    if (!root)
        return (NULL);

    /* Search for the node to remove */
    node = root;
    parent = NULL;
    while (node)
    {
        if (value < node->n)
        {
            parent = node;
            node = node->left;
        }
        else if (value > node->n)
        {
            parent = node;
            node = node->right;
        }
        else
            break;
    }

    /* If the node to remove was not found, return the root node */
    if (!node)
        return (root);

    /* If the node to remove has two children, replace it with its in-order successor */
    if (node->left && node->right)
    {
        tmp = node->right;
        while (tmp->left)
            tmp = tmp->left;

        node->n = tmp->n;
        node = tmp;
        parent = node->parent;
    }

    /* Get the child node of the node to remove */
    if (node->left)
        tmp = node->left;
    else
        tmp = node->right;

    /* If the node to remove is the root node, set the child node as the new root */
    if (!parent)
        root = tmp;
    /* If the node to remove is the left child of its parent, set the child node as the new left child */
    else if (node == parent->left)
        parent->left = tmp;
    /* If the node to remove is the right child of its parent, set the child node as the new right child */
    else
        parent->right = tmp;

    /* Update the parent of the child node */
    if (tmp)
        tmp->parent = parent;

    /* Free the removed node */
    free(node);

    /* Rebalance the tree */
    root = avl_rebalance(root);

    return (root);
}
