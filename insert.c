
#include "rbt.h"

int insert(tree_t **root, data_t item)
{
    tree_t *new_node;

    new_node = create_node(item);

    if (new_node == NULL)
        return FAILURE;

    if (bst_insert(root, new_node) == FAILURE)
        return FAILURE;

    fix_insert(root, new_node);

    return SUCCESS;
}
