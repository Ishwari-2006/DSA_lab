#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void accept(struct node **fhead,struct node **flast)
{
    struct node *head = *fhead;
    struct node *last = *flast;
    struct node *newnode = NULL;
    char ch;

    do {
        newnode = (struct node*)calloc(1, sizeof(struct node));
        if (!newnode) {
            printf("Memory allocation failed!\n");
            return;
        }
        printf("Enter the data: ");
        scanf("%d", &newnode->data);

        if (head == NULL) {
            head = newnode;
            last = newnode;
        } else {
           
            newnode->prev = last; 
            last->next = newnode; 
            last = newnode;  
        }

        printf("Do you want to add more elements? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y');

    *fhead = head;
    *flast = last;
}

void traverse(struct node **fhead)
{
    struct node *temp = *fhead;

    if (temp == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nDLL : ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printReverse(struct node **fhead,struct node **flast)
{   
    if (*fhead == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct node *temp=*flast;

    printf("DLL: ");

    while (temp != NULL) {
        printf("%d <- ", temp->data);
        temp = temp->prev;
    }

    printf("NULL");
} 

void addNodef(struct node **fhead)
{
    struct node *newnode = (struct node*)calloc(1, sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);

    newnode->next = *fhead;
    newnode->prev = NULL;
    
    if (*fhead != NULL)
    {
        (*fhead)->prev = newnode;   
    }
    *fhead = newnode;

}

void addNodel(struct node **flast)
{
    if (*flast == NULL) {
        printf("\nList is empty. Use option 1 to create list first.\n");
        return;
    }

    struct node *newnode = (struct node*)calloc(1, sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);

    newnode->prev=*flast;
    (*flast)->next = newnode;
    *flast = newnode;
}

void addNodev(struct node **fhead)
{
    if (*fhead == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct node *temp = *fhead;
    struct node *newnode = (struct node*)calloc(1, sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }

    int value;
    printf("\nEnter the value of node after which you want to add node: ");
    scanf("%d", &value);

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in list.\n", value);
        free(newnode);
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    
    temp->next = newnode;
}

void addNodep(struct node **fhead)
{
    if (*fhead == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct node *temp = *fhead;
    struct node *newnode = (struct node*)calloc(1, sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }

    int pos, count = 1;
    printf("\nEnter the position (starting from 1): ");
    scanf("%d", &pos);

    if (pos <= 1) {
        printf("Use option 3 to add at first position.\n");
        free(newnode);
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    while (temp != NULL && count < pos - 1) {
        count++;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
if (temp->next != NULL)
   { 
    temp->next->prev = newnode;
   }
temp->next = newnode;
}

void deleteNodef(struct node **fhead)
{
    if (*fhead == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct node *x = *fhead;
    *fhead = x->next;
    if (*fhead != NULL)
    {
        (*fhead)->prev = NULL;
    }
    free(x);
}

void deleteNodel(struct node **fhead, struct node **flast)
{
    if (*fhead == *flast) {
        free(*fhead);
        *fhead = NULL;
        *flast = NULL;
        return;
    }

    struct node *temp = *fhead;
    while (temp->next != *flast) {
        temp = temp->next;
    }

    free(*flast);
    temp->next = NULL;
    *flast = temp;
    if (*fhead != NULL) 
    {
        (*fhead)->prev = NULL;
    }
}

void deleteNodev(struct node **fhead)
{
    int value;
    printf("\nEnter the value of node after which you want to delete node: ");
    scanf("%d", &value);

    struct node *temp = *fhead;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    struct node *x = temp->next;
    temp->next = x->next;
    if (x->next != NULL)
    {
        x->next->prev = temp;
    }
    free(x);
}

void deleteNodep(struct node **fhead)
{

    int pos, count = 1;
    printf("\nEnter the position: ");
    scanf("%d", &pos);


    struct node *temp = *fhead;
    while (temp != NULL && count < pos - 1) {
        count++;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct node *x = temp->next;
    temp->next = x->next;
    if (x->next != NULL)
    {
        x->next->prev = temp;
    }
    free(x);
}

void reverse(struct node **fhead, struct node **flast)
{
    struct node *temp = *fhead;
    struct node *i=NULL;
    
    while(temp!=NULL)
    {
        i=temp->prev;
        temp->prev=temp->next;
        temp->next=i;
        temp=temp->prev;
    } 

    if (i!= NULL) {
        *flast = *fhead;
        *fhead = i->prev;
    }
}  


int main()
{   
    struct node *head = NULL;
    struct node *last = NULL;
    int choice;

    do {
        printf("\n----- DLL Menu -----\n\n");
        printf("1. Accept SLL\n");
        printf("2. Traverse\n");
        printf("3. print in Reverce manner\n");        
        printf("4. Add node at 1st position\n");
        printf("5. Add node at last position\n");
        printf("6. Add node by value\n");
        printf("7. Add node by position\n");
        printf("8. Delete node at 1st position\n");
        printf("9. Delete node at last position\n");
        printf("10. Delete node by value\n");
        printf("11. Delete node by position\n");
        printf("12. Reverse the DLL\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                accept(&head, &last);
                break;

            case 2:
                traverse(&head);
                break;

            
            case 3:
                printReverse(&head,&last);
                break;
                
            case 4:
                addNodef(&head);
                traverse(&head);
                break;

            case 5:
                addNodel(&last);
                traverse(&head);
                break;

            case 6:
                addNodev(&head);
                traverse(&head);
                break;

            case 7:
                addNodep(&head);
                traverse(&head);
                break;

            case 8:
                deleteNodef(&head);
                traverse(&head);
                break;

            case 9:
                deleteNodel(&head, &last);
                traverse(&head);
                break;

            case 10:
                deleteNodev(&head);
                traverse(&head);
                break;

            case 11:
                deleteNodep(&head);
                traverse(&head);
                break;

            case 12:
                reverse(&head, &last);
                traverse(&head);
                break;
    
            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("\nInvalid choice! Please choose again...\n");
        }

    } while (choice != 0);

    return 0;
}

