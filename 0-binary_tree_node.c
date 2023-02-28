#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 *
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /* Allocate memory for new node */
    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    /* Initialize node */
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 *
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /* Check if parent is NULL */
    if (parent == NULL)
        return (NULL);

    /* Allocate memory for new node */
    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    /* Insert new node as left-child */
    if (parent->left != NULL)
    {
        parent->left->parent = new_node;
        new_node->left = parent->left;
    }
    parent->left = new_node;

    return (new_node);
}

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 *
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /* Check if parent is NULL */
    if (parent == NULL)
        return (NULL);

    /* Allocate memory for new node */
    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    /* Insert new node as right-child */
    if (parent->right != NULL)
    {
        parent->right->parent = new_node;
        new_node->right = parent->right;
    }
    parent->right = new_node;

    return (new_node);
}

/**
 * binary_tree_delete - deletes an entire binary tree
 *
 * @tree: pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree != NULL)
    {
        binary_tree_delete(tree->left);
       
