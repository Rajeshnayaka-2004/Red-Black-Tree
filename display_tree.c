
#include "rbt.h"

void display_tree(tree_t *root)
{
    if (root == NULL)
        return;

    display_tree(root->left);

    printf("%d(%s) ", root->data,
           root->color == RED ? "RED" : "BLACK");

    display_tree(root->right);
}
