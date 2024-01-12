#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Generate an array of 1000 random numbers
    srand(time(NULL));
    int n = 1000;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Adjust the range as needed
    }

    printf("Original array: ");
    printArray(arr, n);

    // Profiling Start
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    // Profiling End

    printf("Sorted array: ");
    printArray(arr, n);

    // Calculate the time taken for sorting
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort: %f seconds\n", cpu_time_used);

    return 0;
}
