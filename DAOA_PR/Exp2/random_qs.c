#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Global counters
long long comparisons;
long long swaps;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

// Partition using random pivot
int partition(int arr[], int low, int high) {
    int randomPivot = low + rand() % (high - low + 1);
    swap(&arr[randomPivot], &arr[high]); // Move pivot to end

    int pivot = arr[high];
    printf("Pivot chosen: %d (at index %d)\n", pivot, randomPivot);

    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Randomized QuickSort function
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Function to analyze complexity
void analyzeComplexity(int n) {
    double best_avg = n * (log(n) / log(2.0)); // O(n log2(n) )
    double worst = (double)n * n;

    if (comparisons <= 2 * best_avg) {
        printf("\nTime Complexity: O(n log n)\n");
    } else if (comparisons >= worst / 2) {
        printf("\nTime Complexity: O(n^2)\n");
    } else {
        printf("\nTime Complexity: Between O(n log n) and O(n^2)\n");
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    int *arr_best = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arr_best[i] = arr[i];

    comparisons = swaps = 0;
    clock_t start = clock();
    randomizedQuickSort(arr_best, 0, n - 1);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nBest Case (Random Input)\n");
    printf("Sorted Array: ");
    printArray(arr_best, n);
    printf("Comparisons: %lld\n", comparisons);
    printf("Swaps: %lld\n", swaps);
    printf("Time taken: %f seconds\n", time_taken);
    analyzeComplexity(n);

    // ✅ Worst Case (Already Sorted Input)
    int *arr_worst = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arr_worst[i] = arr_best[i]; // take sorted array as input again

    comparisons = swaps = 0;
    start = clock();
    randomizedQuickSort(arr_worst, 0, n - 1);
    end = clock();

    double time_taken_worst = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nWorst Case (Sorted Input)\n");
    printf("Sorted Array: ");
    printArray(arr_worst, n);
    printf("Comparisons: %lld\n", comparisons);
    printf("Swaps: %lld\n", swaps);
    printf("Time taken: %f seconds\n", time_taken_worst);
    analyzeComplexity(n);

    free(arr);
    free(arr_best);
    free(arr_worst);
    return 0;
}
