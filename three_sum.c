/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* o(n3) solution, returns dups too 
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i,j,k;
    int **res = NULL;
    *returnSize = 0;
    if (!nums){
        return NULL;
    }
    if (numsSize ==0 || numsSize ==1 || numsSize ==2){
        return NULL;
    }
    if (numsSize == 3){
        if (nums[0]+nums[1]+nums[2] == 0){
            *returnSize = 1;
            res = realloc(res, (*returnSize)*sizeof(int*));
            if (!res){
                *returnSize = 0;
                return NULL;
            }
            res[0] = malloc(3*sizeof(int));
            if (!res[0]){
                *returnSize = 0;
                return NULL;
            }
            res[0][0] = nums[0];
            res[0][1] = nums[1];
            res[0][2] = nums[2];
            return res;
        }
        *returnSize = 0;
        return NULL;
    }
    
    for (i = 0; i<numsSize; i++){
        for (j = i+1; j<numsSize; j++){
            for (k = j+1; k<numsSize; k++){
                if (nums[i]+nums[j]+nums[k] == 0){
                    (*returnSize)++;
                    res = realloc(res, (*returnSize)*sizeof(int*));
                    if (!res){
                        *returnSize = 0;
                        return NULL;
                    }
                    res[(*returnSize)-1] = malloc(3*sizeof(int));
                    if (!res[(*returnSize)-1]){
                        *returnSize = 0;
                        return NULL;
                    }
                    res[(*returnSize)-1][0] = nums[i];
                    res[(*returnSize)-1][1] = nums[j];
                    res[(*returnSize)-1][2] = nums[k];
                }
            }
        }
    }
    return res;
}*/

int cmpInt (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

/* O(n2) solution */
int** threeSum(int* nums, int numsSize, int* returnSize) {

    int i,j,k;
    int **res = NULL;
    *returnSize = 0;
    if (!nums){
        return NULL;
    }
    if (numsSize ==0 || numsSize ==1 || numsSize ==2){
        return NULL;
    }
    if (numsSize == 3){
        if (nums[0]+nums[1]+nums[2] == 0){
            *returnSize = 1;
            res = realloc(res, (*returnSize)*sizeof(int*));
            if (!res){
                *returnSize = 0;
                return NULL;
            }
            res[0] = malloc(3*sizeof(int));
            if (!res[0]){
                *returnSize = 0;
                return NULL;
            }
            res[0][0] = nums[0];
            res[0][1] = nums[1];
            res[0][2] = nums[2];
            return res;
        }
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmpInt);
    int target;
    for (i = 0; i<numsSize-2; i++) {   //-2 coz we are looking for 3 numbers, not required but saves cycles
        if (i>0 && nums[i] == nums[i-1]) //skip
            continue;
        target = -nums[i];
        j = i+1;
        k = numsSize-1;
        while(j<k) {
            if (nums[j]+nums[k] > target)
                k--;
            else if (nums[j]+nums[k] < target)
                j++;
            else {
                //equals target
                (*returnSize)++;
                res = realloc(res, (*returnSize)*sizeof(int*));
                res[(*returnSize)-1] = malloc(3*sizeof(int));
                res[(*returnSize)-1][0] = nums[i];
                res[(*returnSize)-1][1] = nums[j];
                res[(*returnSize)-1][2] = nums[k];
                j++;  //next elems
                k--;
                while (j<k && nums[j] == nums[j-1]) j++;  //skip
                while (j<k && nums[k] == nums[k+1]) k--;  //skip
            }
        }
    }
    return res;
}

/*
[-1, 0, 1, 2, -1, -4] : (1, 0, -1, -2, 1, 4)
[-4, -1, -1, 0, 1, 2] : (4, 1, 1, 0, -1, -2)
01 [-1,0]: -1 (1)  12 [0,1]: 1 (-1)    23 [1,2]: 3 (-3)    34 [2,-1]: 1 (-1)  45 [-1,-4]: -5 (5)
02 [-1,1]: 0 (0)   13 [0,2]: 2 (-2)    24 [1,-1]: 0 (0)    35 [2,-4]: -2 (2)
03 [-1,2]: 1 (-1)   14 [0,-1]: -1 (1)  25 [1,-4]: -3 (3)
04 [-1,-1]: -2 (2)  15 [0,-4]: -4 (4)
05 [-1,-4]: -5 (5)
*/

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int size = sizeof(nums)/sizeof(int);
    int **res;
    int resSize, i;
    res = threeSum(nums, size, &resSize);
    if (res)
        for (i = 0; i<resSize; i++){
            printf("%d: (%d, %d, %d)\n", i+1, res[i][0], res[i][1], res[i][2]);
        }
    else
        printf("NULL\n");
    return 0;

}