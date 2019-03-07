/*
 * Maximum sub array
 * 1. divide and conquer
 * 2. greedy: kandane's algo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a,b) ((a>b)? a : b)

#define MAX3(a,b,c) MAX(MAX(a,b), c)

#define MIN(a,b) ((a<b)? a : b)

#define MIN3(a,b,c) MIN(MIN(a,b), c)

int merge_cross_arr(int *arr, int start, int mid, int end) {

    int sum = 0;
    int left_max = INT_MIN;
    int i;
    for (i = mid; i >= start; i--) {
        sum = sum + arr[i];
        left_max = MAX(left_max, sum);
    }

    sum = 0;
    int right_max = INT_MIN;
    for (i = mid+1; i<=end; i++) {
        sum = sum + arr[i];
        right_max = MAX(right_max, sum);
    }
    return right_max + left_max;
}

int __msa_dc(int *arr, int start, int end) {
    if (start == end) {
        return arr[start];
    }

    int mid = (start+end)/2;
    return MAX3(__msa_dc(arr, start, mid), __msa_dc(arr, mid+1, end), merge_cross_arr(arr, start, mid, end));
}

int msa_dc(int *arr, int len) {

    return __msa_dc(arr, 0, len-1);
}

int msa_greedy(int *arr, int len) {

    int msa = arr[0];
    int max = arr[0];
    int i;
    for (i = 1; i<len; i++) {
        max = MAX(arr[i], max+arr[i]);
        msa = MAX(msa, max);
    }
    return msa;

}

int mpsa_greedy(int *arr, int len) {

    int msa = INT_MIN;
    int max = 1;
    int min = 1;
    int i;
    for (i = 0; i<len; i++) {
        printf("MAX of %d, %d, %d\n", arr[i], max*arr[i], min*arr[i]);
        int pmax=max*arr[i];
        int pmin=min*arr[i];
        max = MAX3(arr[i], pmax, pmin);
        min = MIN3(arr[i], pmax, pmin);
        printf("max: %d, min: %d\n", max, min);
        msa = MAX(msa, max);
    }
    return msa;
}

int main () {

    int arr[] = {2,3,-2,4}; //{-2,1,-3,4,-1,2,1,-5,4};

    int msa = msa_dc(arr, (sizeof(arr)/sizeof(int)));
    printf("MSA_dc is: %d\n", msa);
    msa = mpsa_greedy(arr, (sizeof(arr)/sizeof(int)));

    printf("MSA_greedy is: %d\n", msa);
    return 0;
}