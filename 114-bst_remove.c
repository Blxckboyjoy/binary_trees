bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else {
        /* Case 1: no children or only one child */
        if (root->left == NULL) {
            bst_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        /* Case 2: two children */
        bst_t *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        root->n = temp->n;
        root->right = bst_remove(root->right, temp->n);
    }

    return root;
}
