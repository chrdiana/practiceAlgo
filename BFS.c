/*
 * [3,9,20,null,null,15,7]
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue {
    int *arr;
    int cur;
    int end;
} Queue;

void enqueue (Queue *q, int v_idx) {
    if (q->cur < 0)
        q->cur++;
    q->end++;
    q->arr[q->end] = v_idx;
    //printf("Enqueued %d at idx: %d\n", v_idx, q->end);
}

int dequeue (Queue *q) {
    int idx = q->arr[q->cur];
    q->cur++;
    if (q->cur > q->end) {
        q->cur = -1;
        q->end = -1;
    }
    //printf("Dequeued %d from idx: %d\n", idx, q->cur-1);
    return idx;
}

int isEmpty (Queue *q) {
    if (q->cur == -1) {
        return 1;
    }
    return 0;
}

void printQ(Queue *q) {
    int i;
    printf("Queue: ");
    for (i = q->cur; i<= q->end; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int sizeQ(Queue *q) {
    int size = q->end - q->cur;
    if (size < 0) {
        return 0;
    }
    return size;
}

void BFS(int *tree, int arrSize) {

    int *visited = calloc (arrSize, sizeof(int));
    
    Queue *q1 = malloc(sizeof(Queue));
    q1->arr = calloc(arrSize, sizeof(int));
    q1->cur = -1;
    q1->end = -1;

    Queue *q2 = malloc(sizeof(Queue));
    q2->arr = calloc(arrSize, sizeof(int));
    q2->cur = -1;
    q2->end = -1;

    Queue *parent = q1;
    Queue *children = q2;

    int startv = tree[0];
    visited[0] = 1;
    //printf ("%d\n", tree[0]);
    enqueue(q1, 0);
    //printQ(q1);
    

    while (!isEmpty(parent)) {
        int idx = dequeue(parent);
        printf ("%d ", tree[idx]);
        //printQ(q);
        
        int left = 2*idx+1;
        if (left < arrSize && tree[left] != INT_MIN && visited[left] != 1 ) {
            visited[left] = 1;
            //printf ("%d ", tree[left]);
            enqueue(children, left);
            //printQ(q);
        }
        int right = 2*idx+2;
        if (right < arrSize && tree[right] != INT_MIN && visited[right] != 1) {
            visited[right] = 1;
            //printf ("%d ", tree[right]);
            enqueue(children, right);
            //printQ(q);
        }
        if (isEmpty(parent)) {
            printf("\n");
            Queue *tmp = parent;
            parent = children;
            children = tmp;
        }
    }
    //printf("\n");
}

int main() {
    //int arr[] = {3,9,20,INT_MIN,INT_MIN,15,7};
    int arr[] = {3,9,20,INT_MIN,INT_MIN,15,7};

    BFS(arr, sizeof(arr)/sizeof(int));
}