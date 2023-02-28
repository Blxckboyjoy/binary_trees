bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node = NULL, *current = NULL;

    if (!tree)
        return NULL;

    current = *tree;

    while (current)
    {
        if (value == current->n)
            return NULL;

        if (value < current->n)
        {
            if (current->left)
                current = current->left;
            else
            {
                new_node = binary_tree_node(current, value);
                if (!new_node)
                    return NULL;
                current->left = new_node;
                return new_node;
            }
        }
        else
        {
            if (current->right)
                current = current->right;
            else
            {
                new_node = binary_tree_node(current, value);
                if (!new_node)
                    return NULL;
                current->right = new_node;
                return new_node;
            }
        }
    }

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return NULL;
    *tree = new_node;
    return new_node;
}
