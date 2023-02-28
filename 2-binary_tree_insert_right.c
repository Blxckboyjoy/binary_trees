#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 *
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = NULL;

    if (!parent)
        return (NULL);

    new_node = binary_tree_node(parent, value);
    if (!new_node)
        return (NULL);

    if (parent->right)
        binary_tree_swap_right(parent->right, new_node);

    parent->right = new_node;

    return (new_node);
}

/**
 * binary_tree_swap_right - Swaps two nodes in the right subtree
 *
 * @old_right: The old right child
 * @new_right: The new right child
 */
void binary_tree_swap_right(binary_tree_t *old_right, binary_tree_t *new_right)
{
    new_right->right = old_right;
    new_right->parent = old_right->parent;

    if (old_right->right)
        old_right->right->parent = new_right;

    old_right->right = NULL;
    old_right->parent = new_right;
}

/**
 * binary_tree_node - Creates a binary tree node
 *
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

/**
 * binary_tree_delete - Deletes a binary tree
 *
 * @tree: Pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (!tree)
        return;

    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);

    free(tree);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (MAX(left_height, right_height) + 1);
}
