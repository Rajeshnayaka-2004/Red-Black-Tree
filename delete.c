
#include "rbt.h"

// Replace one subtree with another
static void transplant(tree_t **root, tree_t *u, tree_t *v)
{
    if (u->parent == NULL)
    {
        *root = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }

    if (v != NULL)
    {
        v->parent = u->parent;
    }
}

// Delete a specific element
int delete(tree_t **root, data_t item)
{
    tree_t *z;
    tree_t *y;
    tree_t *x;
    tree_t *x_parent;

    color_t original_color;

    if (root == NULL || *root == NULL)
        return FAILURE;

    // Search for the node
    z = *root;

    while (z != NULL && z->data != item)
    {
        if (item < z->data)
            z = z->left;
        else
            z = z->right;
    }

    if (z == NULL)
        return FAILURE;

    y = z;
    original_color = y->color;

    // Case 1: No left child
    if (z->left == NULL)
    {
        x = z->right;
        x_parent = z->parent;

        transplant(root, z, z->right);
    }

    // Case 2: No right child
    else if (z->right == NULL)
    {
        x = z->left;
        x_parent = z->parent;

        transplant(root, z, z->left);
    }

    // Case 3: Two children
    else
    {
        y = minimum_node(z->right);
        original_color = y->color;
        x = y->right;

        if (y->parent == z)
        {
            x_parent = y;
        }
        else
        {
            x_parent = y->parent;

            transplant(root, y, y->right);

            y->right = z->right;
            y->right->parent = y;
        }

        transplant(root, z, y);

        y->left = z->left;
        y->left->parent = y;

        y->color = z->color;
    }

    free(z);

    if (original_color == BLACK)
    {
        fix_delete(root, x,
                   (x != NULL) ? x->parent : x_parent);
    }

    if (*root != NULL)
        (*root)->color = BLACK;

    return SUCCESS;
}
