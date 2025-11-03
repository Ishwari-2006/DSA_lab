#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

struct graph
{
    int numVertex;
    struct node **adjList;
};

struct q {
    int data;
    struct q *next;
};

struct stack
{
    int data;
    struct stack *next;
};

void create(struct graph *g)
{
    int src, dest;
    char ch;
    int count=0;

    printf("Enter number of vertices in graph: ");
    scanf("%d", &g->numVertex);

    g->adjList = (struct node **)calloc(g->numVertex, sizeof(struct node*));

    do
    {
        printf("\nEnter source vertex: ");
        scanf("%d", &src);

        printf("Enter destination vertices of %d (enter -1 to stop): ", src);

        while (1)
        {
            scanf("%d", &dest);
            if (dest == -1)
            {    
                break;
            }

            struct node *newnode = (struct node*)calloc(1, sizeof(struct node));
            newnode->vertex = dest;
            newnode->next = NULL;

            if (g->adjList[src] == NULL)
            {
                g->adjList[src] = newnode;
            }
            else
            {
                struct node *temp = g->adjList[src];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
        }
        count++;

        if(count!=g->numVertex)
        {
            printf("Do you want to enter another source vertex (y/n)? ");
            scanf(" %c", &ch);
        }

    } while (ch == 'y' && count!=g->numVertex);
}

void pushS(struct stack **top, char val) {
    struct stack *newNode = (struct stack*)calloc(1,sizeof(struct stack));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

char popS(struct stack **top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    struct stack *temp = *top;
    char val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

char peekS(struct stack *top) {
    if (top == NULL) 
    {    
        return '\0';
    }
    return top->data;
}

int isEmptyS(struct stack *top) {
    return top == NULL;
}

int IsEmptyQ(struct q *front)
{
    if (front == NULL)
    {
        return 1; // NULL
    }
    return 0; // Non empty
}
void pushQ(struct q **front, struct q **rear, int v) {
    
    struct q *newnode = (struct q *)calloc(1,sizeof(struct q));

    newnode->data = v;
    newnode->next = NULL;

    if (*rear == NULL) 
    {
        *front = *rear = newnode;
    } 
    else 
    {
        (*rear)->next = newnode;
        *rear = newnode;
    }
}
int popQ(struct q **front,struct q **rear)
{
    if (*front == NULL)
    {
        return -1;
    }

    struct q *temp = *front;
    int d = temp->data;

    *front = temp->next;
    
    if (*front == NULL)
    {    
        *rear = NULL;
    }
    free(temp);

    return d;
}

void bfs(struct graph *g, int start)
{
    int *visited=(int*)calloc(g->numVertex,sizeof(int));
    struct q *front=NULL;
    struct q *rear=NULL;

    pushQ(&front,&rear,start);
    visited[start]=1;

    printf("BFS Traversal: ");

    while(!IsEmptyQ(front))
    {
        int v=popQ(&front,&rear);
        printf("%d ",v);

        struct node *temp=g->adjList[v];

        while(temp)
        {
            if(!visited[temp->vertex])
            {
                pushQ(&front,&rear,temp->vertex);
                visited[temp->vertex]=1;
            }
            temp=temp->next;
        }
        printf("\t");

    }

}

void dfs(struct graph *g, int start)
{
    int *visited=(int*)calloc(g->numVertex,sizeof(int));
    struct stack *top=NULL;

    printf("\nDFS Traversal: ");       
    pushS(&top,start);

    while(!isEmptyS(top))
    {
        int v=popS(&top);
        if(!visited[v])
        {
            printf("%d ",v);
            visited[v]=1;
        }
        
        struct node *temp=g->adjList[v];

        while(temp)
        {
            if(!visited[temp->vertex])
            {
                pushS(&top,temp->vertex);
            }
            temp=temp->next;
        }
        printf("\t");
    }    
}

void display(struct graph *g)
{
    printf("\nAdjacency List Representation:\n");
    printf("\nVertex   Adjecent vertices\n");

    for (int i = 0; i < g->numVertex; i++)
    {
        printf(" %d       ", i);
        struct node *temp = g->adjList[i];

        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    struct graph g;
    int start;

    create(&g);
    display(&g);

    printf("\nEnter the start vertex to traverse: ");
    scanf("%d", &start);

    bfs(&g,start);

    dfs(&g, start);

    return 0;
}
