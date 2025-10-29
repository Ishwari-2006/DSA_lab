#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;

    struct tree *left;

    struct tree *right;
};

void create(struct tree **froot, int fnum)
{

    if (*froot == NULL)
    {
        struct tree *newnode = (struct tree *)calloc(1, sizeof(struct tree));

        newnode->data = fnum;

        *froot = newnode;

        return;
    }

    if (fnum < (*froot)->data)
    {

        create(&(*froot)->left, fnum);
    }

    else if (fnum > (*froot)->data)
    {
        create(&(*froot)->right, fnum);
    }
}

void numInput(struct tree **root)
{
    int num;
    char ch;

    do
    {
        printf("Enter the number: ");
        scanf("%d", &num);
        create(root, num);

        printf("Do you want to add new node(y/n)? ");
        scanf(" %c", &ch);

    } while (ch == 'y');
}

int search(struct tree *root, int fkey)
{
    static int count = 0;   
    static int success = 0; 

    if (root != NULL)
    {
        search(root->left, fkey);
        count++; 

        if (root->data == fkey)
        {
            printf("%d is found in tree at %d position in Inorder!\n", fkey, count);
            success = 1;
        }

        search(root->right, fkey);
    }
    
    return success;
}

struct tree* helper(struct tree *root)
{   
    if(root->left==NULL)
    {
        return root->right;
    }
    else if(root->right==NULL)
    {
        return root->left;
    }

    struct tree *rightChild=root->right;
    struct tree *leftSub = root->left;
    struct tree *temp=leftSub;

    while(temp->right!=NULL)
    {
        temp=temp->right;
    }

    temp->right=rightChild;
    free(root);

    return leftSub;
}

struct tree* delete(struct tree *root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return helper(root);
    }

    struct tree *temp=root;

    while(root!=NULL)
    {   
        if(root->data > key)
        {
            if(root->left!=NULL && root->left->data==key)
            {
                root->left=helper(root->left);
                break;
            }
            else
            {
                root=root->left;
            }
        }
        else
        {
           if(root->right!=NULL && root->right->data==key)
            {
                root->right=helper(root->right);
                break;
            }
            else
            {
                root=root->right;
            } 
        }
    }
    return temp;
}

void R_Inorder(struct tree *root)
{
    if (root != NULL)
    {
        R_Inorder(root->left);

        printf("%d ", root->data);

        R_Inorder(root->right);
    }
}

int main()
{
    struct tree *root = NULL;
    int key, choice;

    do
    {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Create (Insert Nodes)\n");
        printf("2. Search a Node\n");
        printf("3. Delete a Node\n");
        printf("4. Display Inorder Traversal\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            numInput(&root);
            printf("\nCurrent Inorder Traversal: ");
            R_Inorder(root);
            printf("\n");
            break;

        case 2:
            if (root == NULL)
            {
                printf("Tree is empty!\n");
                break;
            }
            printf("Enter the number to search: ");
            scanf("%d", &key);
            if (search(root, key))
                printf("Search successful.\n");
            else
                printf("Element not found.\n");
            break;

        case 3:
            if (root == NULL)
            {
                printf("Tree is empty!\n");
                break;
            }
            printf("Enter the number to delete: ");
            scanf("%d", &key);
            root = delete(root, key);
            printf("\nAfter deletion (Inorder): ");
            R_Inorder(root);
            printf("\n");
            break;

        case 4:
            if (root == NULL)
                printf("Tree is empty!\n");
            else
            {
                printf("Inorder Traversal: ");
                R_Inorder(root);
                printf("\n");
            }
            break;

        case 0:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }while(choice!=0);
}
