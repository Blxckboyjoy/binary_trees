/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* check if it is a complete tree */
    if (binary_tree_is_complete(tree) == 0)
        return (0);

    /* check if the root node is greater than or equal to its children */
    if (tree->left != NULL && tree->left->n > tree->n)
        return (0);

    if (tree->right != NULL && tree->right->n > tree->n)
        return (0);

    /* check if the left and right subtrees are also valid Max Binary Heaps */
    if (binary_tree_is_heap(tree->left) == 0 || binary_tree_is_heap(tree->right) == 0)
        return (0);

    return (1);
}
