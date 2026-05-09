/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// comparator for sorting
int compare(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;

    return x->start - y->start;
}

void mergeIntervals(Interval arr[], int n) {

    // sort intervals by start time
    qsort(arr, n, sizeof(Interval), compare);

    Interval result[n];
    int index = 0;

    // first interval
    result[index] = arr[0];

    for(int i = 1; i < n; i++) {

        // overlap condition
        if(arr[i].start <= result[index].end) {

            // merge intervals
            if(arr[i].end > result[index].end) {
                result[index].end = arr[i].end;
            }
        }
        else {
            // no overlap
            index++;
            result[index] = arr[i];
        }
    }

    // print merged intervals
    printf("Merged Intervals:\n");

    for(int i = 0; i <= index; i++) {
        printf("[%d, %d]\n", result[i].start, result[i].end);
    }
}

int main() {

    Interval arr[] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}