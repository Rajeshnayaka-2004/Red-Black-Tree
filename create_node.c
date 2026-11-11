
#include "rbt.h"

tree_t *create_node(data_t item)
{
    tree_t *new_node;

    new_node = malloc(sizeof(tree_t));

    if (new_node == NULL)
    {
        return NULL;
    }

    new_node->data = item;
    new_node->color = RED;

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;

    return new_node;
}
