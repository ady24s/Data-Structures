#include <stdio.h>

void insertionsort(int arr[], int size)
{
    for ( int i = 0; i < size; i++){
        for (int j = i; j > 0; j--){
            if (arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr [j-1];
                arr [j-1] = temp;
            }
            else{
                break;
            }

        }
        printf("Pass %d: ", i);
        for (int k = 0; k < size; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

}

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int  i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for ( int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionsort(arr, n);

    printf("Sorted array: ");
    for ( int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;

}
