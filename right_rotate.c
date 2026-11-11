
#include "rbt.h"

void right_rotate(tree_t **root, tree_t *x)
{
    tree_t *y;

    if (x == NULL || x->left == NULL)
        return;

    y = x->left;

    x->left = y->right;

    if (y->right != NULL)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;

    else if (x == x->parent->left)
        x->parent->left = y;

    else
        x->parent->right = y;

    y->right = x;

    x->parent = y;
}
