// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node* next;
// };


// void accept(struct node **fhead,struct node **flast)
// {   struct node *head=NULL;
//     struct node *last=NULL;
//     struct node *newnode=NULL;
//     char ch;

//     head=*fhead;
//     last=*flast;

//     do{
//         newnode=(struct node*)calloc(1,sizeof(struct node));
//         printf("Enter the data: ");
//         scanf("%d",&newnode->data);

//         if(head==NULL)
//         {
//             head=newnode;
//             last=newnode;
//         }
//         else
//         {
//             last->next=newnode;
//             last=newnode;
//         }
        
//         printf("Do you want to add more elments? ");
//         scanf(" %c",&ch);
//     }while(ch=='y');

//     *fhead=head;
//     *flast=last;
// }

// void traverse(struct node **fhead)
// {  
//     struct node *temp=NULL;
//     temp=*fhead;
    
//     printf("\nLinked list: ");
//     while(temp!=NULL)
//     {
//         printf("%d -> ",temp->data);
//         temp = temp->next;

//     }
//     printf("NULL");
// }

// void addNodef(struct node **fhead)
// {   struct node *newnode=NULL;

//     newnode=(struct node*)calloc(1,sizeof(struct node));

//     printf("\nEnter the data: ");
//     scanf("%d",&newnode->data);

//     newnode->next=*fhead;
//     *fhead=newnode;

// }

// void addNodel(struct node **flast)
// {
//      struct node *newnode=NULL;

//     newnode=(struct node*)calloc(1,sizeof(struct node));

//     printf("\nEnter the data: ");
//     scanf("%d",&newnode->data);

//     (*flast)->next=newnode;
//     newnode->next=NULL;
//     *flast=newnode;
// }

// void addNodev(struct node **fhead)
// {
//     struct node *temp=NULL;
//     struct node *newnode=NULL;
//     int value;
//     temp=*fhead;

//     newnode=(struct node*)calloc(1,sizeof(struct node));

//     printf("\nEnter the value of node after which you want to add node: ");
//     scanf("%d",&value);

//     printf("Enter data: ");
//     scanf("%d",&newnode->data);
//     while(temp->data!=value)
//     {  
//        temp=temp->next; 
//     }

//     newnode->next=temp->next;
//     temp->next=newnode;
    
// }

// void addNodep(struct node **fhead)
// {
//     struct node *temp=NULL;
//     struct node *newnode=NULL;
//     int pos;
//     int count=1;
//     temp=*fhead;

//     newnode=(struct node*)calloc(1,sizeof(struct node));

//     printf("\nEnter the position: ");
//     scanf("%d",&pos);

//     printf("Enter data: ");
//     scanf("%d",&newnode->data);

//     while(temp!=NULL)
//     {
//        count++;
//        if(count==pos)
//        {
//          newnode->next=temp->next;
//          temp->next=newnode;
//          break;
//        }
//        temp=temp->next; 
//     }
// }

// void deleteNodef(struct node **fhead)
// {  struct node *x=*fhead;
    
//    *fhead=x->next;
//    free(x);
// }

// void deleteNodel(struct node **fhead,struct node **flast)
// {   struct node *temp=*fhead;

//     if(*fhead==*flast)
//     {
//         *fhead=NULL;
//         *flast=NULL;
//         free(*fhead);
//         return;
//     }

//     while(temp->next->next!=NULL)
//     {
//         temp=temp->next;
//     }

//     temp->next=NULL;
//     free(temp->next);    
// }

// void deleteNodev(struct node **fhead)
// {
//     struct node *temp=*fhead;
//     struct node *x=NULL;
//     int value;

//     printf("\nEnter the value of node after which you want to delete node: ");
//     scanf("%d",&value);

//      while(temp->data!=value)
//     {  
//        temp=temp->next; 
//     }

//     x=temp->next;
//     temp->next=temp->next->next;
//     free(x);    
// }

// void deleteNodep(struct node **fhead)
// {
//     struct node *temp=*fhead;
//     struct node *x=NULL;
//     int pos;
//     int count=1;

//     printf("\nEnter the position: ");
//     scanf("%d",&pos);

//      while(temp!=NULL)
//     {
//        count++;
//        if(count==pos)
//        {
//          x=temp->next;
//          temp->next=temp->next->next;
//          free(x);

//          break;
//        }
//        temp=temp->next; 
//     }

// }

// void reverse(struct node **fhead,struct node **flast)
// {
//     struct node *prev=NULL;
//     struct node *curr=*fhead;
//     struct node *next1=NULL;
    
// *flast=*fhead;

//     while(curr!=NULL)
//     {
//         next1=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=next1;

//     }
//     *fhead=prev;

// }

// int main()
// {   struct node *head=NULL;
//     struct node *last=NULL;
//     int choice;

//     do{
//         printf("\n-----SLL Menu-----\n\n");
//         printf("1.Accept SLL\n");
//         printf("2.Traverse\n");
//         printf("3.Add node at 1st position\n");
//         printf("4.Add node at last position\n");
//         printf("5.Add node by value\n");
//         printf("6.Add node by position\n");
//         printf("7.Delete node at 1st position\n");
//         printf("8.Delete node at last position\n");
//         printf("9.Delete node by value\n");
//         printf("10.Delete node by position\n");
//         printf("11.Reverse the SSL\n");
//         printf("0.Exit\n");

//         printf("Enter your choice: ");
//         scanf("%d",&choice);

//         switch(choice)
//         {
//             case 1:
//             accept(&head,&last);
//             break;
            
//             case 2:
//             traverse(&head);
//             break;

//             case 3:
//             addNodef(&head);
//             traverse(&head);
//             break;

//             case 4:
//             addNodel(&last);
//             traverse(&head);
//             break;

//             case 5:
//             addNodev(&head);
//             traverse(&head);
//             break;

//             case 6:
//             addNodep(&head);
//             traverse(&head);
//             break;

//             case 7:
//             deleteNodef(&head);
//             traverse(&head);
//             break;

//             case 8:
//             deleteNodel(&head,&last);
//             traverse(&head);
//             break;

//             case 9:
//             deleteNodev(&head);
//             traverse(&head);
//             break;

//             case 10:
//             deleteNodep(&head);
//             traverse(&head);
//             break;

//             case 11:
//             reverse(&head, &last);
//             traverse(&head);
//             break;

//             case 0:
//             printf("Exiting...");
//             break;

//             default:
//             printf("Invalid choice!..please choose again...");
//         }

//     }while(choice!=0);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void accept(struct node **fhead, struct node **flast)
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

    printf("\nLinked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
    free(x);
}

void deleteNodel(struct node **fhead, struct node **flast)
{
    if (*fhead == NULL) {
        printf("\nList is empty.\n");
        return;
    }

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
}

void deleteNodev(struct node **fhead)
{
    if (*fhead == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    int value;
    printf("\nEnter the value of node after which you want to delete node: ");
    scanf("%d", &value);

    struct node *temp = *fhead;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Node with value %d not found or no node to delete after it.\n", value);
        return;
    }

    struct node *x = temp->next;
    temp->next = x->next;
    free(x);
}

void deleteNodep(struct node **fhead)
{
    if (*fhead == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    int pos, count = 1;
    printf("\nEnter the position: ");
    scanf("%d", &pos);

    if (pos <= 1) {
        deleteNodef(fhead);
        return;
    }

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
    free(x);
}

void reverse(struct node **fhead, struct node **flast)
{
    if (*fhead == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct node *prev = NULL;
    struct node *curr = *fhead;
    struct node *next1 = NULL;

    *flast = *fhead;

    while (curr != NULL) {
        next1 = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next1;
    }
    *fhead = prev;
}

int main()
{   
    struct node *head = NULL;
    struct node *last = NULL;
    int choice;

    do {
        printf("\n----- SLL Menu -----\n\n");
        printf("1. Accept SLL\n");
        printf("2. Traverse\n");
        printf("3. Add node at 1st position\n");
        printf("4. Add node at last position\n");
        printf("5. Add node by value\n");
        printf("6. Add node by position\n");
        printf("7. Delete node at 1st position\n");
        printf("8. Delete node at last position\n");
        printf("9. Delete node by value\n");
        printf("10. Delete node by position\n");
        printf("11. Reverse the SLL\n");
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
                addNodef(&head);
                traverse(&head);
                break;

            case 4:
                addNodel(&last);
                traverse(&head);
                break;

            case 5:
                addNodev(&head);
                traverse(&head);
                break;

            case 6:
                addNodep(&head);
                traverse(&head);
                break;

            case 7:
                deleteNodef(&head);
                traverse(&head);
                break;

            case 8:
                deleteNodel(&head, &last);
                traverse(&head);
                break;

            case 9:
                deleteNodev(&head);
                traverse(&head);
                break;

            case 10:
                deleteNodep(&head);
                traverse(&head);
                break;

            case 11:
                reverse(&head, &last);
                traverse(&head);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please choose again...\n");
        }

    } while (choice != 0);

    return 0;
}

