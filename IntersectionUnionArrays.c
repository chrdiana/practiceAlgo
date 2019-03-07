//int 	mergesort (void *base, size_t nmemb, size_t size, int (*compar ) (const void *, const void * ))

#include <stdio.h>
#include <stdlib.h>

int my_compare_int (const void *a, const void *b) {
    int first = *((int *)a);
    int sec = *((int *)b);

    if (first < sec) {
        return -1;
    } else if (first > sec) {
        return 1;
    } else {
        return 0;
    }
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int i = 0, j= 0;
    int arrsize = (nums1Size < nums2Size)? nums1Size : nums2Size;
    int *intersection = calloc(arrsize, sizeof(int));
    int size = 0;

    //sort the arrays
    mergesort(nums1, nums1Size, sizeof(int), my_compare_int);
    mergesort(nums2, nums2Size, sizeof(int), my_compare_int);

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            if (i == 0 || nums1[i] != nums1[i-1]) {
                intersection[size] = nums1[i];
                size++;
            }
            i++;
            j++;
        }
    }
    *returnSize = size;
    return intersection;
}

int* unionArray(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int i = 0, j= 0;
    int arrsize = nums1Size + nums2Size;
    int *unionArr = calloc(arrsize, sizeof(int));
    int size = 0;

    //sort the arrays
    mergesort(nums1, nums1Size, sizeof(int), my_compare_int);
    mergesort(nums2, nums2Size, sizeof(int), my_compare_int);

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            if (i == 0 || nums1[i] != nums1[i-1]) {
                unionArr[size] = nums1[i];
                size++;
            }
            i++;
        } else if (nums1[i] > nums2[j]) {
            if (j == 0 || nums2[j] != nums2[j-1]) {
                unionArr[size] = nums2[j];
                size++;
            }
            j++;
        } else {
            if (i == 0 || nums1[i] != nums1[i-1]) {
                unionArr[size] = nums1[i];
                size++;
            }
            i++;
            j++;
        }
    }
    *returnSize = size;
    return unionArr;
}

int main () {
    //int arr1[] = {8,3,4,6,9,3,5,6};
    //int arr2[] = {9,0,2,6,3,7,7};

    int arr1[] = {61,24,20,58,95,53,17,32,45,85,70,20,83,62,35,89,5,95,12,86,58,77,30,64,46,13,5,92,67,40,20,38,31,18,89,85,7,30,67,34,62,35,47,98,3,41,53,26,66,40,54,44,57,46,70,60,4,63,82,42,65,59,17,98,29,72,1,96,82,66,98,6,92,31,43,81,88,60,10,55,66,82,0,79,11,81};
    int arr2[] = {5,25,4,39,57,49,93,79,7,8,49,89,2,7,73,88,45,15,34,92,84,38,85,34,16,6,99,0,2,36,68,52,73,50,77,44,61,48,5};


    int size;
    int *intersection = intersect(arr1, (sizeof(arr1)/sizeof(int)), arr2, (sizeof(arr2)/sizeof(int)), &size);

    int i =0;
    printf("Intersection: [");
    for (i = 0; i<size; i++) {
        printf("%d,", intersection[i]);
    }
    printf("]\n");

    int arr11[] = {8,3,4,6,9,3,5,6};
    int arr22[] = {9,0,2,6,3,7,7};

    size = 0;
    i =0;
    int *unionArr = unionArray(arr11, (sizeof(arr11)/sizeof(int)), arr22, (sizeof(arr22)/sizeof(int)), &size);
    printf("Union: [");
    for (i = 0; i<size; i++) {
        printf("%d,", unionArr[i]);
    }
    printf("]\n");
}