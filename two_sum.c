/*
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* n2 solution
int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int *res = NULL;
    if (nums == NULL)
        return NULL;
    if (numsSize == 0 || numsSize == 1)
        return NULL;

    for (i=0; i<numsSize-1; i++){
        for (j=i+1;j<numsSize;j++){
            if (nums[i]+nums[j] == target){
                res = malloc(2*sizeof(int));
                res[0]=i;
                res[1]=j;
                return res;
            }
        }
    }
    return res;
}
*/


/* solution with hashmap
 * insert the number in hashmap, while putting check is complementary (target-num) exists.
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int *res = NULL;
    int max = INT_MIN, min = INT_MAX;
    if (nums == NULL)
        return NULL;
    if (numsSize == 0 || numsSize == 1)
        return NULL;
    if (numsSize == 2){
        if (nums[0]+nums[1] == target){
            res = malloc(2*sizeof(int));
            res[0]=0;
            res[1]=1;
        }
        return res;
    }
    
    for (i=0; i<numsSize; i++){
        if (nums[i] > max) max = nums[i];
        if (nums[i] < min) min = nums[i];
    }
    printf("max:%d, min:%d\n", max, min);    

    int *map = calloc((max-min+1),sizeof(int)); //sets memory to 0
    for(i=0;i<numsSize;i++){
        //insert into map
        map[nums[i]-min] = i+1;
        printf("inserted map[%d] = %d\n", nums[i]-min, i);
    }
    
    for(i=0;i<numsSize;i++){
        int comp = target - nums[i];
        printf("nums:%d, comp:%d\n",nums[i], comp);
        if (comp < min || comp > max) continue;
        if (map[comp-min] && i != (map[comp-min]-1)){ //exists in map
            printf("map[comp-min]=%d\n", map[comp-min]);
            res = malloc(2*sizeof(int));
            res[0]=i;
            res[1]=map[comp-min]-1;
            return res;
        }
    }
    
    return res;
}

int main() {
    int nums[] = {3,2,4};
    int size = sizeof(nums)/sizeof(int);
    int *res;
    res = twoSum(nums, size, 6);
    if (res)
        printf("(%d, %d)\n", res[0], res[1]);
    else
        printf("NULL\n");
    return 0;

}
