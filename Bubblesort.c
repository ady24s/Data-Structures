#include <stdio.h>

void bubblesort(int arr[], int size)
{
    int i;
    int j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        printf("Pass %d: ", i);

        for (int k = 0; k < size; k++) {
            printf("%d ", arr[k]);
        }

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter the number of elements of the array:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n");

    printf("Original array:");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    bubblesort(arr, n);

    printf("Sorted array:");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
