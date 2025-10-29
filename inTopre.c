#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct oprStack
{
    struct oprStack *prev;
    char data;
    struct oprStack *next;
};

struct opndStack
{
    struct opndStack *prev;
    char data;
    struct opndStack *next;
};

int prioCheck(char ch)
{
    int priority=0;

    if(ch=='+'|| ch=='-')
    {
        priority=1;
    }
    if(ch=='*'|| ch=='/')
    {
        priority=2;
    }
    return priority;
}

void pushopr(struct oprStack **ftop, char ch)
{
    struct oprStack *newnode = (struct oprStack *)calloc(1, sizeof(struct oprStack));

    newnode->data = ch;
    newnode->next = *ftop;
    newnode->prev = NULL;

    if (*ftop == NULL)
    {
        *ftop = newnode;
    }
    else
    {   (*ftop)->prev=newnode;
        *ftop = newnode;
    }
}

void pushopnd(struct opndStack **ftop, char ch)
{
    struct opndStack *newnode = (struct opndStack *)calloc(1, sizeof(struct opndStack));

    newnode->data = ch;
    newnode->next = *ftop;
    newnode->prev = NULL;

    if (*ftop == NULL)
    {
        *ftop = newnode;
    }
    else
    {   
        (*ftop)->prev=newnode;  
    }
}

char popopnd(struct opndStack **ftop)
{
    struct opndStack *top = NULL;
    char val;

    top = *ftop;

    if (top == NULL)
    {
        printf("The stack is empty...");
    }
    else
    {   struct opndStack *temp = top;
        val = temp->data; 
        top = temp->next;
        if(top!=NULL)
        {
            top->prev = NULL;
        }
        free(temp);
    }

    *ftop = top;
    return val;
}

char popopr(struct oprStack **ftop)
{
    struct oprStack *top = NULL;
    char val;

    top = *ftop;

    if (top == NULL)
    {
        printf("The stack is empty...");
    }
    else
    {   struct oprStack *temp = top;
        val = temp->data; 
        top = temp->next;
        if(top!=NULL)
        {
            top->prev = NULL;
        }
        free(temp);
    }

    *ftop = top;
    return val;
}

char peek(struct oprStack *ftop) 
{
    char val = '\0';  

    if (ftop == NULL) {
        val = '\0';  
    } else {
        val = ftop->data;  
    }

    return val;
}


void infixToPrefix(struct oprStack **ftop,struct opndStack **ftop1,char finfix[], char fprefix[])
{
    int i=0;
    char opr[2];
    char opnd[20];

    while(finfix[i]!='\0')
    {
        char symbol=finfix[i];
        
        if((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'))
        {
            pushopnd(ftop1, symbol);
        }
        else if (symbol == '(') {
            pushopr(ftop, symbol);
        }
        else if (symbol == ')') {
            while (*ftop != NULL && peek(*ftop) != '(') {
                 char opnd2=popopnd(*ftop1);
                char opnd1=popopnd(*ftop1);

                opr[0]=popopr(*ftop);

                strcpy(opnd,opr);
                strcat(opnd,opnd1);
                strcat(opnd,opnd2);

                pushopnd(*ftop1,opnd);
                pushopr(*ftop,opr);

            }
            popopr(ftop); // remove '('
        }
        else if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/')
        {
            int inop=prioCheck(symbol);
            int stop=prioCheck(peek(*ftop));

            if(*ftop == NULL || inop>stop)
            {
                pushopr(ftop,symbol);
            }
            else
            {
                char opnd2[20]=popopnd(*ftop1);
                char opnd1[20]=popopnd(*ftop1);

                opr[0]=popopr(*ftop);

                strcpy(opnd,opr);
                strcat(opnd,opnd1);
                strcat(opnd,opnd2);

                pushopnd(*ftop1,opnd);
                pushopr(*ftop,opr);

            }
        }
        
        i++;

    }
    if(opr==NULL)
        {   strcpy(fprefix,opnd);
            return;
        }
}
int main()
{
    char infix[20],prefix[20];
    char i;
    struct oprStack *top=NULL;
    struct opndStack *top1=NULL;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPrefix(&top,&top1,infix,prefix);

    printf("prefix: %s\n",prefix);
    

    return 0;
}
