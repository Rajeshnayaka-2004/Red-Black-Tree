
#include "rbt.h"

// Get the colour of a node
static color_t get_color(tree_t *node)
{
    if (node == NULL)
        return BLACK;

    return node->color;
}

void fix_delete(tree_t **root, tree_t *x, tree_t *parent)
{
    tree_t *sibling;

    while (x != *root && get_color(x) == BLACK)
    {
        if (parent == NULL)
            break;

        // x is the left child
        if (x == parent->left)
        {
            sibling = parent->right;

            // Case 1: Sibling is RED
            if (get_color(sibling) == RED)
            {
                sibling->color = BLACK;
                parent->color = RED;

                left_rotate(root, parent);
                sibling = parent->right;
            }

            // Case 2: Sibling is BLACK and
            // both children are BLACK
            if (sibling == NULL ||
                (get_color(sibling->left) == BLACK &&
                 get_color(sibling->right) == BLACK))
            {
                if (sibling != NULL)
                    sibling->color = RED;

                x = parent;
                parent = x->parent;
            }
            else
            {
                // Case 3: Far child is BLACK
                if (get_color(sibling->right) == BLACK)
                {
                    if (sibling->left != NULL)
                        sibling->left->color = BLACK;

                    sibling->color = RED;

                    right_rotate(root, sibling);
                    sibling = parent->right;
                }

                // Case 4: Far child is RED
                sibling->color = parent->color;
                parent->color = BLACK;

                if (sibling->right != NULL)
                    sibling->right->color = BLACK;

                left_rotate(root, parent);

                x = *root;
                parent = NULL;
            }
        }
        else
        {
            // x is the right child
            sibling = parent->left;

            // Case 1: Sibling is RED
            if (get_color(sibling) == RED)
            {
                sibling->color = BLACK;
                parent->color = RED;

                right_rotate(root, parent);
                sibling = parent->left;
            }

            // Case 2: Sibling is BLACK and
            // both children are BLACK
            if (sibling == NULL ||
                (get_color(sibling->right) == BLACK &&
                 get_color(sibling->left) == BLACK))
            {
                if (sibling != NULL)
                    sibling->color = RED;

                x = parent;
                parent = x->parent;
            }
            else
            {
                // Case 3: Far child is BLACK
                if (get_color(sibling->left) == BLACK)
                {
                    if (sibling->right != NULL)
                        sibling->right->color = BLACK;

                    sibling->color = RED;

                    left_rotate(root, sibling);
                    sibling = parent->left;
                }

                // Case 4: Far child is RED
                sibling->color = parent->color;
                parent->color = BLACK;

                if (sibling->left != NULL)
                    sibling->left->color = BLACK;

                right_rotate(root, parent);

                x = *root;
                parent = NULL;
            }
        }
    }

    if (x != NULL)
        x->color = BLACK;

    if (*root != NULL)
        (*root)->color = BLACK;
}
