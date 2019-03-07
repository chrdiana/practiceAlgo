/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.

Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.

0011122334
0111122334 f=2, c=2
0121122334 f=5, c=3
0123122334 f=7, c=4
0123422334 f=9, c=5
*/


#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int i, first, cur;
    printf("size: %d\n", numsSize);
    if (!nums || numsSize == 0 || numsSize == 1)
        return numsSize;

    first = 0;
    cur = first+1;
    for (i = 1; i<numsSize; i++) {
        if (nums[first] == nums[i]) {
            continue;
        } else {
            nums[cur] = nums[i];
            first = i;
            cur++;
            printf("f: %d, c: %d, i: %d\n", first, cur, i);
        }
    }
    return cur;
}

int main() {
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    //int arr[] = {1};
    int cnt = removeDuplicates(arr, sizeof(arr)/sizeof(int));
    printf("cnt: %d\n", cnt);
    int i;
    for(i = 0; i<cnt; i++){
        printf("%d,", arr[i]);
    }
    printf("\n");
    return 0;
}