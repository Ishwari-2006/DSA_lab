#include <stdio.h>
#include <stdlib.h>

void create(int fcost[][100],int fnumVertex)
{
    for(int i=1; i<=fnumVertex; i++)
    {
        for(int j=1; j<=fnumVertex; j++)
        {
            if(i!=j && !fcost[i][j])
            {
                printf("Enter the weight of link %d->%d: ",i,j);
                scanf("%d",&fcost[i][j]);
                fcost[j][i] = fcost[i][j];
            }
            else if(i==j)
            {
                fcost[i][j]=999;
            }
            
        }
    }
}

void display(int fcost[][100],int fnumVertex)
{
    printf("\n");
    for(int i=1; i<=fnumVertex; i++)
    {
        for(int j=1; j<=fnumVertex; j++)
        {
            printf("%d  ",fcost[i][j]);
            
        }
        printf("\n");
    }
}

void prim(int fcost[][100],int fnumVertex)
{
    int *visited=(int*)calloc(fnumVertex,sizeof(int));

    int min=0;
    int i=1,j=1,u=0,v=0;
    int minCost=0;
    int noe=1;
    
    visited[1]=1;

    printf("\nEDGES CONSIDERED FOR MST ARE:\n");

    while(noe<fnumVertex)
    {
        min=999;

        for(i=1; i<=fnumVertex; i++)
        {
            for(j=1; j<=fnumVertex; j++)
            {
                if(fcost[i][j]<min)
                {
                    if(visited[i]==0)
                    {
                        continue;
                    }
                    else
                    {
                        min=fcost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }         
        }

        if(visited[u]==0||visited[v]==0)
        {
            visited[v]=1;
            minCost+=min;
            printf("\n%dth Edge (%d-%d) = %d",noe++,u,v,min);
        }

        fcost[u][v]=fcost[v][u]=999;
    }
    printf("\nMINIMUM COST= %d",minCost);
}



int main()
{
    int cost[100][100];
    int numVertex;

    printf("Enter the total number of vertices: ");
    scanf("%d",&numVertex);

    create(cost,numVertex);
    display(cost,numVertex);

    prim(cost,numVertex);


    return 0;
}

