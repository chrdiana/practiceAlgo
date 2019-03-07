#include <stdio.h>

void merge(int *arr, int start, int mid, int end) {

    printf("merge: %d, %d, %d\n", start, mid, end);
    int temp[end-start+1];
    int k = 0;
    int i = start;
    int j = mid+1;
    printf("Temp: ");
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            printf("%d ", temp[k]);
            k++;
            i++;
        } else {
            temp[k] = arr[j];
            printf("%d ", temp[k]);
            k++;
            j++;
        }
    }
    while (i<=mid) {
        temp[k] = arr[i];
        printf("%d ", temp[k]);
        k++;
        i++;
    }
    while (j <= end) {
        temp[k] = arr[j];
        printf("%d ", temp[k]);
        k++;
        j++;
    }
    printf("\n");

    //copy temp to arr start to end
    for (i = start; i<=end; i++) {
        arr[i] = temp[i-start];
    }
    printf("Merge done\n");
}

void swap (int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = arr[i];
}


void mergesort(int *arr, int start, int end) {

    int mid = (start + end)/2;
    
    if (start < end) {
        printf("sort: %d, %d\n", start, mid);
        mergesort(arr, start, mid);
        printf("sort: %d, %d\n", mid+1, end);
        mergesort(arr, mid+1, end);

        merge(arr, start, mid, end);
    }
}

int main () {
    int arr1[] = {8,3,4,6,9,3,5,6};
    int arr2[] = {9,0,2,6,3,7,7};
    int size = (sizeof(arr1)/sizeof(int));
    int i =0;

    printf("arr1: [");
    for (i = 0; i<size; i++) {
        printf("%d,", arr1[i]);
    }
    printf("]\n");

    mergesort(arr1, 0, size-1);

    printf("Sorted arr1: [");
    for (i = 0; i<size; i++) {
        printf("%d,", arr1[i]);
    }
    printf("]\n");
}