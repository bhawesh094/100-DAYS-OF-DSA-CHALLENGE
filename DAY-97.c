/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

/* Compare meetings by start time */
int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;

    return m1->start - m2->start;
}

/* ---------- Min Heap Functions ---------- */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;

    heapifyUp(heap, (*size) - 1);
}

void removeMin(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;

    heapifyDown(heap, *size, 0);
}

/* ---------- Main Logic ---------- */

int minMeetingRooms(Meeting meetings[], int n) {

    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[1000];
    int heapSize = 0;

    /* Add first meeting end time */
    insertHeap(heap, &heapSize, meetings[0].end);

    for (int i = 1; i < n; i++) {

        /* If room becomes free */
        if (meetings[i].start >= heap[0]) {
            removeMin(heap, &heapSize);
        }

        /* Allocate current meeting */
        insertHeap(heap, &heapSize, meetings[i].end);
    }

    return heapSize;
}

int main() {

    Meeting meetings[] = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    int n = sizeof(meetings) / sizeof(meetings[0]);

    int rooms = minMeetingRooms(meetings, n);

    printf("Minimum Meeting Rooms Required = %d\n", rooms);

    return 0;
}