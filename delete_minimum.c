
#include "rbt.h"

// Find minimum node
tree_t *minimum_node(tree_t *root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

// Delete minimum node
int delete_minimum(tree_t **root)
{
    tree_t *temp;
    tree_t *parent;
    tree_t *child;
    color_t original_color;

    if (*root == NULL)
        return FAILURE;

    // Find minimum node
    temp = minimum_node(*root);

    // Store original colour
    original_color = temp->color;

    // Get parent and right child
    parent = temp->parent;
    child = temp->right;

    // Replace minimum node
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
