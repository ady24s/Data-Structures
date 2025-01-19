#include <stdio.h>

void linearsearch(int arr[], int size, int target)
{
    int index;
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            index = i;
            printf("Element found at %d index\n", index);

        }
    }
}

int main ()
{ linear search
    int n;
    int i;
    printf("Enter number of elements:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf ("Given array:");
     for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    int target;
    printf("Enter the target element:");
    scanf("%d", &target);

    linearsearch(arr, n, target);

}

// Recursive

#include <stdio.h>

int linearSearchRecursive(int arr[], int target, int index, int size) {
    if (index == size) {
        return -1; // Element not found
    }

    if (arr[index] == target) {
        return index; // Element found
    }

    return linearSearchRecursive(arr, target, index + 1, size);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int result = linearSearchRecursive(arr, target, 0, size);

    if (result != -1) {
        printf("Element found at %d index\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}

//Multple occurance

#include <stdio.h>

void linearSearchMultipleOccurrences(int arr[], int size, int target) {
    int i;
    int found = 0; // Flag to check if the element is found at least once

    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found at %d index\n", i);
            found = 1; // Set the flag to true as the element is found
        }
    }

    if (!found) {
        printf("Element not found in the array\n");
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    linearSearchMultipleOccurrences(arr, size, target);

    return 0;
}
