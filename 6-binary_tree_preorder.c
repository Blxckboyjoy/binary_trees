void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Call the function for the current node */
    func(tree->n);

    /* Recursively traverse the left subtree */
    binary_tree_preorder(tree->left, func);

    /* Recursively traverse the right subtree */
    binary_tree_preorder(tree->right, func);
}
