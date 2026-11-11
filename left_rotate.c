
#include "rbt.h"

void left_rotate(tree_t **root, tree_t *x)
{
    tree_t *y;

    if (x == NULL || x->right == NULL)
        return;

    y = x->right;

    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;

    else if (x == x->parent->left)
        x->parent->left = y;

    else
        x->parent->right = y;

    y->left = x;

    x->parent = y;
}
