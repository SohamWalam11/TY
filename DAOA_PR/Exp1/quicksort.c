#include <stdio.h>

// Function prototypes
void quickSort(int arr[], int low, int high);
void swap(int *a, int *b);
int part(int arr[], int low, int high);

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Before sorting
    printf("Before sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }
    printf("\n");

    // After sorting
    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }
    printf("\n");

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int part(int arr[], int low, int high)
{
    int piv = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < piv) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = part(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
