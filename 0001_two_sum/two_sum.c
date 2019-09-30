
/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 时间复杂度 O(n2).
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int temp;
    for(int i = 0; i < numsSize; i++){
        temp = target - nums[i];
        for(int j = i+1; j < numsSize; j++){
            if(nums[j] == temp){
                int *result = malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
