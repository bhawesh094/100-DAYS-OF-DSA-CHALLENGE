/*Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.*/

#include <stdio.h>

void countingSort(int arr[], int n) {
    int i, max = arr[0];

    // Step 1: Find max
    for(i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];

    // Step 2: Initialize count array
    for(i = 0; i <= max; i++)
        count[i] = 0;

    // Store frequency
    for(i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 3: Prefix sum
    for(i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int output[n];

    // Step 4: Build output array
    for(i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 5: Copy back
    for(i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}