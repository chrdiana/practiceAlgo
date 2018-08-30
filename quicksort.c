#include <stdio.h>

void swap(int arr[], int i, int j) {
    if (i == j)
        return;
    printf("Swapping %d and %d\n", arr[i], arr[j]);
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void print_array(int arr[], int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition_high(int arr[], int low, int high) {

    int pivot = arr[high];
    int i = low - 1;
    int j = 0;

    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, high);
    print_array(arr, high+1);
    return (i+1);
}

int partition_low(int arr[], int low, int high) {

    int pivot = arr[low];
    int i = high + 1;
    int j = 0;

    for (j = high; j >= low + 1; j--) {
        if (arr[j] >= pivot) {
            i--;
            swap(arr, i, j);
        }
    }
    swap(arr, low, i-1);
    print_array(arr, high+1);
    return (i-1);
}

void quicksort(int arr[], int low, int high) {
    int pi;
    if (low < high) {
        //pi = partition_high(arr, low, high);
        pi = partition_low(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


int main() {

    int arr[] = {50,60,90,40,100,20,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Input array: ");
    print_array(arr, size);

    quicksort(arr, 0, size-1);
    
    printf("Sorted array: ");
    print_array(arr, size);
}
