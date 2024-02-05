#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

double test_insertion_sort(int arr[], int n) {
    clock_t start_time, end_time;
    start_time = clock();

    insertion_sort(arr, n);

    end_time = clock();
    return ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    // Test with varying input sizes
    for (int i = 0; i < 5; i++) {
        int size = (i + 1) * 500;
        int* arr = malloc(size * sizeof(int));

        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 1000;
        }

        double execution_time = test_insertion_sort(arr, size);
        printf("Input Size: %d, Execution Time: %f seconds\n", size, execution_time);

        free(arr);
    }

    return 0;
}