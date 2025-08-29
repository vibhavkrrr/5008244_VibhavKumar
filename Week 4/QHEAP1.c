#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX];
int heap_size = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapify_up(int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] > heap[idx]) {
            swap(&heap[parent], &heap[idx]);
            idx = parent;
        } else break;
    }
}

void heapify_down(int idx) {
    int left, right, smallest;
    while (1) {
        left = 2*idx + 1;
        right = 2*idx + 2;
        smallest = idx;

        if (left < heap_size && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap_size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != idx) {
            swap(&heap[smallest], &heap[idx]);
            idx = smallest;
        } else break;
    }
}

void insert(int x) {
    heap[heap_size] = x;
    heapify_up(heap_size);
    heap_size++;
}

int getMin() {
    return heap[0];
}

void delete_val(int x) {
    // find index of x
    int idx = -1;
    for (int i = 0; i < heap_size; i++) {
        if (heap[i] == x) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return;

    // replace with last element
    heap[idx] = heap[heap_size-1];
    heap_size--;

    // fix heap
    heapify_up(idx);
    heapify_down(idx);
}

int main() {
    int Q, type, x;
    scanf("%d", &Q);

    while (Q--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &x);
            insert(x);
        } else if (type == 2) {
            scanf("%d", &x);
            delete_val(x);
        } else if (type == 3) {
            printf("%d\n", getMin());
        }
    }
    return 0;
}
