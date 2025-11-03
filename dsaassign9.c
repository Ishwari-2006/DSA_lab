#include <stdio.h>

void create(int fhash[][3], int fmod)
{
    for(int i=0; i<fmod; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(j==0)
            {
                fhash[i][j]=i;
            }
            else if(j==1)
            {
                fhash[i][j]=0;
            }
            else if(j==2)
            {
                fhash[i][j]=-1;
            }

        }
    }
}

void insert(int fhash[][3],int fmod, int fnum)
{
    int index;
    int newIndex;

    index=fnum%10;

    if(fhash[index][1]==0)
    {
        fhash[index][1]=fnum;
    }
    else
    {
        for(int i=1; i<fmod; i++)
        {
            newIndex=(index+i)%fmod;

            if(fhash[newIndex][1]==0)
            {
                fhash[newIndex][1]=fnum;

                int temp = index;
                if((fhash[index][1] % fmod) == (fnum % fmod))
                {
                    while (fhash[temp][2] != -1)
                    {
                        temp = fhash[temp][2];
                    }
                    fhash[temp][2]=newIndex;
                }
                break;
            }
        }
    }
}

void search(int fhash[][3],int fmod, int fkey)
{
    int key1=fkey%10;
    int success=0;
    int temp=key1;

    if(fhash[key1][1]==fkey)
    {
        printf("%d is found at index %d",fkey,key1);
        success=1;
    }
    else
    {   int temp=key1;
        while(fhash[temp][2]!=-1)
        {
            temp = fhash[temp][2];
        }

        if(fhash[temp][1]==fkey)
        {
            printf("%d is found at index %d",fkey,temp);
            success=1;
        }
    }

    // while(temp!=-1)
    // {
    //     if(fhash[key1][1]==fkey)
    //     {
    //         printf("%d is found ant index %d",fkey,key1);
    //         success=1;
    //         break;
    //     }
    //     temp = fhash[temp][2];

    // }

    if(success==0)
    {
        printf("%d is not present!");
    }

}

void display(int fhash[][3], int mod)
{
    printf("\nindex\tvalue\tchain");
    printf("\n----------------------");

    for(int i=0; i<mod; i++)
    {
        printf("\n");

        printf("  %d\t  %d\t %d",fhash[i][0],fhash[i][1],fhash[i][2]);
    }
}

int main()
{
    int hash[11][3];
    int mod,num,key;
    char ch;
    int count=0;

    printf("\nEnter the mod size: ");
    scanf("%d",&mod);
    printf("\n");

    create(hash,mod);

    do{
        printf("Enter the number: ");
        scanf("%d",&num);

        insert(hash,mod,num);
        count++;

        if(count!=mod)
        {
			printf("Do you want to add more number(y/n)? =>");
			scanf(" %c",&ch);
        }

    }while(ch=='y'&&count!=mod);

    display(hash,mod);

    printf("\nEnter the mod size: ");
    scanf("%d",&key);

    search(hash,mod,key);

    return 0;

}