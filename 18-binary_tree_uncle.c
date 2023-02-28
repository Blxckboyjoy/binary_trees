binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return NULL;

    binary_tree_t *grandparent = node->parent->parent;

    if (node->parent == grandparent->left)
        return grandparent->right;
    else
        return grandparent->left;
}
