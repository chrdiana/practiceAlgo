#include <stdio.h>
#include <limits.h>

int max_product_3(int arr[], int size) {

    int max[3] = {INT_MIN, INT_MIN, INT_MIN};
    int min[2] = {INT_MAX, INT_MAX};
    int i = 0;

    for(i = 0; i < size; i++) {
        if (arr[i] >= max[2]) {
            max[0] = max[1];
            max[1] = max[2];
            max[2] = arr[i];
        } else if(arr[i] >= max[1]) {
            max[0] = max[1];
            max[1] = arr[i];
        } else if(arr[i] > max[0]) {
            max[0] = arr[i];
        }

        if (arr[i] <= min[0]) {
            min[1] = min[0];
            min[0] = arr[i];
        } else if (arr[i] < min[1]){
            min[1] = arr[i];
        }
    }
    int p1 = max[0] * max[1] * max[2];
    int p2 = min[0] * min [1] * max[2];
    //if (p1 > p2) 
    //    return p1;
    return (p1 > p2)? p1 :  p2;
}

int main () {

    int arr[] = {-9, -12, -3, -8, 2, 6};
    int size = sizeof(arr)/sizeof(arr[0]);

    int max = max_product_3(arr, size);
    printf("Max: %d\n", max);
}
