#include <stdio.h>
#include <stdlib.h> 
# include <conio.h>

// Function prototype
void selectsort(int arr[], int n);

void main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    // Input from user
    printf("Enter the %d integers: \n", n);
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Before sorting
    printf("\nBefore sorting: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    // Calling selection sort
    selectsort(arr, n);

    // After sorting
    printf("\nSorted array in ascending order: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    // Keep terminal open
#ifdef _WIN32
    system("pause"); // Works only on Windows
#else
    printf("\nPress Enter to exit...");
    getchar(); // consume leftover newline
    getchar(); // wait for Enter
#endif

   getch();
}

// Selection sort function
void selectsort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        // Assume the first element is the minimum
        min_idx = i;

        // Find the minimum element in the unsorted part
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
