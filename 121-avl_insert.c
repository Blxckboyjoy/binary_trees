avl_t *avl_insert(avl_t **tree, int value)
{
    if (!tree)
        return NULL;

    avl_t *node = binary_tree_node(NULL, value);
    if (!node)
        return NULL;

    if (!(*tree)) {
        *tree = node;
        return node;
    }

    avl_t *current = *tree;
    avl_t *parent = NULL;

    while (current) {
        parent = current;
        if (value < current->n)
            current = current->left;
        else if (value > current->n)
            current = current->right;
        else {
            free(node);
            return NULL;
        }
    }

    if (value < parent->n)
        parent->left = node;
    else
        parent->right = node;

    node->parent = parent;

    // balance the tree if necessary
    *tree = avl_balance(*tree);

    return node;
}
