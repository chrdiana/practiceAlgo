/*
 * Longest increasing subsequence in an int array:
 * Recursive solution:
 * LIS(i): length of lis ith index onwards, two conditions:
 * 1. i is taken: LIS(i) = 1 + LIS(i+1)
 * 2. i is not taken: LIS(i) = LIS(i+1)
 * LIS: max of (taken, not taken)
 * 
 * DP solution:
 * dp[i]: max len of subsequence including i
 * dp[i] = MAX(dp[j]) + 1 , for all 0 <= j < i
 * LIS: MAX(dp[i]) , for all 0 <= i < n
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a,b) ((a > b)? a : b)

// recursive:
int __lis_r(int *arr, int len, int prev, int curr) {
    if (curr == len) {
        return 0;
    }

    int taken, not_taken;
    if (arr[curr] > prev) {
        taken = 1 + __lis_r(arr, len, arr[curr], curr+1);
    }
    not_taken = __lis_r(arr, len, prev, curr+1);
    return MAX(taken, not_taken);
}

int lis_r(int *arr, int len) {
    return __lis_r(arr, len, INT_MIN, 0);
}


//DP:
int lis_dp(int *arr, int len) {
    if (len == 0) {
        return 0;
    }
    int *dp = malloc(len*sizeof(int));

    dp[0] = 1;
    int i, j;
    int maxval, maxans;
    maxans = 1;     //dp[0] = 1
    for (i = 0; i<len; i++) {
        maxval = 0;         //finding max of dp for all j < i
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                maxval = MAX(maxval, dp[j]); 
            }
        }
        dp[i] = maxval + 1;
        maxans = MAX(maxans, dp[i]);
    }
    return maxans;
}


int main () {

    int arr[] = {10,9,2,5,3,7,101};

    int lis = lis_r(arr, (sizeof(arr)/sizeof(int)));

    printf("LIS_R: %d\n", lis);

    lis = lis_dp(arr, (sizeof(arr)/sizeof(int)));

    printf("LIS_dp: %d\n", lis);
}