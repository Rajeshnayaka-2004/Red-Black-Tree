
#include "rbt.h"

// Find maximum node
tree_t *maximum_node(tree_t *root)
{
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

// Delete maximum node
int delete_maximum(tree_t **root)
{
    tree_t *temp;
    tree_t *parent;
    tree_t *child;
    color_t original_color;

    if (*root == NULL)
        return FAILURE;

    // Find maximum node
    temp = maximum_node(*root);

    // Store original colour
    original_color = temp->color;

    // Maximum node can have only a left child
    parent = temp->parent;
    child = temp->left;

    // Replace maximum node
    if (parent == NULL)
    {
        *root = child;
    }
    else if (temp == parent->left)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }

    // Update parent pointer
    if (child != NULL)
        child->parent = parent;

    // Fix tree if deleted node was BLACK
    if (original_color == BLACK)
    {
        fix_delete(root, child, parent);
    }

    // Free deleted node
    free(temp);

    return SUCCESS;
}
