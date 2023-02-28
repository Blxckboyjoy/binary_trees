#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_l, height_r;

    if (!tree)
        return (0);

    height_l = binary_tree_height(tree->left);
    height_r = binary_tree_height(tree->right);

    if (height_l > height_r)
        return (height_l + 1);
    else
        return (height_r + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 * Return: The balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int balance;

    if (!tree)
        return (0);

    balance = binary_tree_balance(tree);

    if (balance < -1 || balance > 1)
        return (0);

    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}
