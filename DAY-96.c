/*Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j].*/

#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;      
    int j = mid + 1;   
    int k = left;      
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            
            // Remaining elements in left half are inversions
            inv_count += (mid - i + 1);
        }
    }

    // Copy remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        // Left half
        inv_count += mergeSort(arr, temp, left, mid);

        // Right half
        inv_count += mergeSort(arr, temp, mid + 1, right);

        // Merge and count inversions
        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long inversions = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions = %lld\n", inversions);

    return 0;
}