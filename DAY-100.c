/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[]) {
    int n = right - left + 1;
    Pair temp[n];

    int i = left;
    int j = mid + 1;
    int k = 0;

    int rightCount = 0;

    while (i <= mid && j <= right) {

        // Right element is smaller
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            rightCount++;
        }
        else {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSort(Pair arr[], int left, int right, int count[]) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);

    merge(arr, left, mid, right, count);
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    Pair arr[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    printf("Counts of smaller elements on right:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}