
#include "rbt.h"

int bst_insert(tree_t **root, tree_t *new_node)
{
    tree_t *temp = *root;
    tree_t *parent = NULL;

    while (temp != NULL)
    {
        parent = temp;

        if (new_node->data < temp->data)
        {
            temp = temp->left;
        }
        else if (new_node->data > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            free(new_node);
            return FAILURE;
        }
    }

    new_node->parent = parent;

    if (parent == NULL)
    {
        *root = new_node;
    }
    else if (new_node->data < parent->data)
    {
        parent->left = new_node;
    }
    else
    {
        parent->right = new_node;
    }

    return SUCCESS;
}
