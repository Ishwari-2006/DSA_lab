#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct stackNode
{
    struct node *treeNode;
    struct stackNode *next;
};

struct node *createTreeNode(char data)
{
    struct node *newnode = (struct node *)calloc(1, sizeof(struct node));

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void push(struct stackNode **top, struct node *t)
{
    struct stackNode *newnode = (struct stackNode *)calloc(1, sizeof(struct stackNode));

    newnode->treeNode = t;
    newnode->next = *top;
    *top = newnode;
}

struct node *pop(struct stackNode **top)
{
    if(*top==NULL)
    {
        return NULL;
    }

    struct stackNode *temp = *top;
    struct node *t = temp->treeNode;
    *top=temp->next;
    free(temp);
    return t;
}

int operand(char ch)
{
    return ((ch>='0' && ch<='9')||(ch>='a' && ch<='z')||(ch>='A' && ch<='Z'));
}

struct node* expTree(char postfix[])
{
    struct node *t, *t1, *t2;
    struct stackNode *stack=NULL;

    for(int i=0; postfix[i]!='\0'; i++)
    {   char ch=postfix[i];

        if(operand(ch))
        {   t=createTreeNode(ch);
            push(&stack,t);
        }
        else
        {   t=createTreeNode(ch);

            t1=pop(&stack);
            t2=pop(&stack);

            t->left=t2;
            t->right=t1;

            push(&stack,t);

        }
    }
    return pop(&stack);
}

void R_Inorder(struct node *root)
{
    if(root!=NULL)
    {
        R_Inorder(root->left);
        printf("%c ",root->data);
        R_Inorder(root->right);
    }
    
}

void R_Preorder(struct node *root)
{
    if(root!=NULL)
    {   printf("%c ",root->data);
        R_Preorder(root->left);       
        R_Preorder(root->right);
    }
    
}

void R_Postorder(struct node *root)
{
    if(root!=NULL)
    {
        R_Postorder(root->left);        
        R_Postorder(root->right);
        printf("%c ",root->data);
    }
    
}

void NR_Inorder(struct node *root)
{
    struct node *curr=root;
    struct stackNode *stack=NULL;

    while(curr!=NULL || stack!=NULL)
    {
        while(curr!=NULL)
        {
            push(&stack,curr);
            curr=curr->left;
        }

        curr=pop(&stack);
        printf("%c ",curr->data);
        curr=curr->right;
    }
}

void NR_Preorder(struct node *root)
{
  if(!root)
  {
    return;
  } 

  struct stackNode *stack=NULL;
  push(&stack,root);
  
  while(stack!=NULL)
  {
    struct node *curr=pop(&stack);
    printf("%c ",curr->data);

    if(curr->right)
    {
        push(&stack,curr->right);
    }
    if(curr->left)
    {
        push(&stack,curr->left);
    }
  }
}

void NR_Postorder(struct node *root)
{
    struct stackNode *s1=NULL;
    struct stackNode *s2=NULL;

    push(&s1,root);

    while(s1!=NULL)
    {
        struct node *curr=pop(&s1);
        push(&s2,curr);

        if(curr->left)
        {
            push(&s1,curr->left);
        }
        if(curr->right)
        {
            push(&s1,curr->right);
        }
    }

    while(s2!=NULL)
    {
        struct node *curr=pop(&s2);
        printf("%c ",curr->data);
        
    }
}



int main()
{
    char postfix[100];
    int ch,choice;
    struct node *root=NULL;

    printf("\nPlease enter the postfix: ");
    scanf("%s",postfix);

    root=expTree(postfix);

    do
    {   
        printf("\n\n===MENU===");
        printf("\n1. Inorder");
        printf("\n2. Preorder");
        printf("\n3. Postorder");
        printf("\n0. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\n--Way to traverse--\n1.Recursive\n2.Non recursive\n");
                scanf("%d",&choice);

                switch(choice){
                    case 1:
                        R_Inorder(root);
                        break;
                    case 2:
                        NR_Inorder(root);
                        break;
                    default:
                        printf("Invalid Input");
                }
                break;
            
            case 2:
                printf("\n--Way to traverse--\n1.Recursive\n2.Non recursive\n");
                printf("\nYour choice: ");
                scanf("%d",&choice);

                switch(choice){
                    case 1:
                        R_Preorder(root);
                        break;
                    case 2:
                        NR_Preorder(root);
                        break;
                    default:
                        printf("Invalid Input");
                }
                break;

            case 3:
                printf("\n--Way to traverse--\n1.Recursive\n2.Non recursive\n");
                printf("\nYour choice: ");
                scanf("%d",&choice);

                switch(choice){
                    case 1:
                        R_Postorder(root);
                        break;
                    case 2:
                        NR_Postorder(root);
                        break;
                    default:
                        printf("Invalid Input!!!");
                }
                break;

            case 0:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice!!! please enter again...");
        }
    }while(ch!=0);

    return 0;
}