
#ifndef RBT_H
#define RBT_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef enum
{
    RED,
    BLACK
} color_t;

typedef struct node
{
    int data;
    color_t color;

    struct node *left;
    struct node *right;
    struct node *parent;

} tree_t;

typedef int data_t;

/* Function declarations */

tree_t *create_node(data_t item);

int bst_insert(tree_t **root, tree_t *new_node);

void inorder(tree_t *root);
void left_rotate(tree_t **root, tree_t *x);
void right_rotate(tree_t **root, tree_t *x);
void fix_insert(tree_t **root, tree_t *new_node);
int insert(tree_t **root, data_t item);
void display_tree(tree_t *root);
int search(tree_t *root, data_t item);
int find_minimum(tree_t **root, data_t *min);
int find_maximum(tree_t **root, data_t *max);
void fix_delete(tree_t **root, tree_t *x, tree_t *parent);
tree_t *minimum_node(tree_t *root);
int delete_minimum(tree_t **root);
tree_t *maximum_node(tree_t *root);
int delete_maximum(tree_t **root);
int delete(tree_t **root, data_t item);
#endif
