/*Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/

#include <stdio.h>

void insertionSort(float bucket[], int count) {
    int i, j;
    float key;

    for(i = 1; i < count; i++) {
        key = bucket[i];
        j = i - 1;

        while(j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    int i, j;

    // Create buckets
    float bucket[n][n];
    int bucketCount[n];

    // Initialize bucket counts
    for(i = 0; i < n; i++) {
        bucketCount[i] = 0;
    }

    // Put elements into buckets
    for(i = 0; i < n; i++) {
        int index = n * arr[i];
        bucket[index][bucketCount[index]] = arr[i];
        bucketCount[index]++;
    }

    // Sort each bucket
    for(i = 0; i < n; i++) {
        insertionSort(bucket[i], bucketCount[i]);
    }

    // Merge buckets into original array
    int k = 0;

    for(i = 0; i < n; i++) {
        for(j = 0; j < bucketCount[i]; j++) {
            arr[k] = bucket[i][j];
            k++;
        }
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array:\n");

    for(int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}