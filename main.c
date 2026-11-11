
#include "rbt.h"

void inorder(tree_t *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    tree_t *root = NULL;

    int choice, value, min, max;

    while (1)
    {
        printf("\n===== RED BLACK TREE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete specific element\n");
        printf("3. Search\n");
        printf("4. Find minimum\n");
        printf("5. Find maximum\n");
        printf("6. Delete minimum\n");
        printf("7. Delete maximum\n");
        printf("8. Display tree\n");
        printf("9. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                if (insert(&root, value) == SUCCESS)
                    printf("Insertion successful\n");
                else
                    printf("Insertion failed or duplicate value\n");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                if (delete(&root, value) == SUCCESS)
                    printf("Element deleted successfully\n");
                else
                    printf("Element not found\n");
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);

                if (search(root, value) == SUCCESS)
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;

            case 4:
                if (find_minimum(&root, &min) == SUCCESS)
                    printf("Minimum value: %d\n", min);
                else
                    printf("Tree is empty\n");
                break;

            case 5:
                if (find_maximum(&root, &max) == SUCCESS)
                    printf("Maximum value: %d\n", max);
                else
                    printf("Tree is empty\n");
                break;

            case 6:
                if (delete_minimum(&root) == SUCCESS)
                    printf("Minimum node deleted successfully\n");
                else
                    printf("Tree is empty\n");
                break;

            case 7:
                if (delete_maximum(&root) == SUCCESS)
                    printf("Maximum node deleted successfully\n");
                else
                    printf("Tree is empty\n");
                break;

            case 8:
                if (root == NULL)
                {
                    printf("Tree is empty\n");
                }
                else
                {
                    printf("\nInorder traversal: ");
                    inorder(root);

                    printf("\nRoot: %d (%s)\n",
                           root->data,
                           root->color == RED ? "RED" : "BLACK");

                    printf("Node values with colours: ");
                    display_tree(root);
                    printf("\n");
                }
                break;

            case 9:
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid choice\n");

        }
    }
}
