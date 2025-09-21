#include <stdio.h>
int Union(int farr1[], int farr2[],int farr3[], int fn);
int Intersection(int farr1[], int farr2[],int farr3[], int fn);
void Diffrence(int farr1[], int farr2[],int farr3[], int fn);
void symmDiffrence(int farr1[], int farr2[],int intfarr3[], int fn);


void acceptArray(int farr[], int fn) {
    for(int i = 0; i < fn; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &farr[i]);
    }
}

// Function to display array
void displayArray(int farr[], int fn) {
    printf("Array elements: ");
    for(int i = 0; i < fn; i++) {
        printf("%d ", farr[i]);
    }
    printf("\n");
}

int Union(int farr1[], int farr2[],int farr3[], int fn){
  int i,j,k=0,flag=0;
  //add all elememts of 1st array in result array
  for(i=0;i<fn;i++)
  {
  farr3[k]=farr1[i];
  k++;
  }

  for(i=0;i<fn;i++)
  {
  flag=1;
	  for(j=0;j<fn;j++)
	  {
		  if(farr2[i]==farr1[j])
	       {
			  flag=0;
			  break;
	       }
	  }
	  if(flag==1)
	    {
		    farr3[k]=farr2[i];
		    k++;
	    }
	  }
	  return k;

  }

int Intersection(int farr1[], int farr2[],int farr3[], int fn)
{
	int i,j,k=0;
	for (i = 0; i < fn; i++) {
        for (j = 0; j < fn; j++) {
            if (farr1[i] == farr2[j]) {
                farr3[k++] = farr1[i];
                break;
            }
        }
    }

	return k;
}

void Diffrence(int farr1[], int farr2[],int farr3[], int fn)
{
	//1 3 4 5 6
	//4 5 8 9 6
	int k=0;
	for(int i=0; i<fn; i++)
	{ int flag=0;
		for(int j=0; j<fn; j++)
		{
			if(farr1[i]==farr2[j])
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
		{
		farr3[k]=farr1[i];
		k++;
		}
	}
	

	displayArray(farr3,k);
}

void symmDiffrence(int farr1[], int farr2[],int farr3[], int fn)
{	
	int unionArr[200], interArr[100];

    int unionSize = Union(farr1, farr2, unionArr, fn);
    int interSize = Intersection(farr1, farr2, interArr, fn);

    Diffrence(unionArr, interArr, farr3, unionSize);

}

int main()
{
	 int arr1[100],arr2[100],arr3[100]={0},n,choice=0,ch=0;

	    printf("Enter number of elements sets: ");
	    scanf("%d", &n);


	    acceptArray(arr1, n);
	    displayArray(arr1, n);

	    acceptArray(arr2, n);
	    displayArray(arr2, n);

		do {
        printf("\n------ MENU ------\n");
        printf("1. Union\n");
        printf("2. Intersection\n");
        printf("3. Difference\n");
        printf("4. Symmetric Difference\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        int size;

        switch (choice) {
            case 1:
                printf("Union: ");
                size = Union(arr1, arr2, arr3, n);
                displayArray(arr3, size);
                break;

            case 2:
                printf("Intersection: ");
                size = Intersection(arr1, arr2, arr3, n);
                displayArray(arr3, size);
                break;

            case 3:
				printf("Enter your choice: \n1.arr1-arr2\n2.arr2-arr1\n");
				scanf("%d",&ch);

				if(ch==1){
                printf("Difference (Set1 - Set2): ");
                Diffrence(arr1, arr2, arr3, n);
				}

				else{
					printf("Difference (Set2 - Set1): ");
                	Diffrence(arr2, arr1, arr3, n);
				}
                break;

            case 4:
                printf("Symmetric Difference: ");
                symmDiffrence(arr1, arr2, arr3, n);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0);

	return 0;
}