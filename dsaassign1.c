#include <stdio.h>
void acceptArray(int arr[], int n);
void displayArray(int arr[], int n);
void linearSearch(int arr[], int n, int key);
void bubbleSort(int arr[], int n);
int binarySearch(int farr[], int fn, int fkey);
// Function to accept array
void acceptArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to display array
void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function for linear search
void linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element %d found at position %d (index %d)\n", key, i + 1, i);
            return;
        }
    }
    printf("Element %d not found.\n", key);
}

// Function for bubble sort
void bubbleSort(int arr[], int n) {
    int temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted using Bubble Sort.\n");
}
int binarySearch(int farr[], int fn, int fkey)
{
    int low = 0, high = fn - 1, mid;
    int foundIndex = -1;  // -1 means not found

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (farr[mid] == fkey)
        {
            foundIndex = mid;
            low = high + 1;  
        }
        else if (farr[mid] < fkey)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (foundIndex != -1)
        printf("Element %d is found at position %d (index %d)\n", fkey, foundIndex + 1, foundIndex);
    else
        printf("Element %d not found.\n", fkey);

    return 0; 
}

// Main function with switch case
int main() {
    int arr[100], n, choice, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    acceptArray(arr, n);
    displayArray(arr, n);

    do{
        printf("\n--------Menu-------\n");
        printf("1. Linear Search\n");
        printf("2. Bubble Sort\n");
        printf("3. Display Sorted Array\n");
        printf("4. Binary search\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to search (Linear): ");
                scanf("%d", &key);
                linearSearch(arr, n, key);
                break;

            case 2:
                bubbleSort(arr, n);
                break;

            case 3:
                displayArray(arr, n);
                break;

            case 4:
            	displayArray(arr, n);
                printf("Enter element to search (Binary): ");
                scanf("%d", &key);

                binarySearch(arr, n, key);
                break;

            case 0:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }while(choice!=0);

    return 0;
}