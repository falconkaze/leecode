#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int start = 0;
    while(start < numsSize){
        int tmp;
        int index = start + 1;
        if(nums[index - 1] != index){
            tmp = nums[index - 1];
            nums[index - 1] = -1;
            index = tmp;
            while(nums[index - 1] != index){
                tmp = nums[index - 1];
                nums[index - 1] = index;
                index = tmp;
            }
        }
        start ++;
    }
    int* result = malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for(int i = 0; i < numsSize; i ++){
        if(nums[i] != i + 1){
            result[*returnSize] = i + 1;
            *returnSize++;
        }
    }
    return result;
}

int main(){
  int array[] = {2, 2};
  int* returnSize = 0;
  int* result = findDisappearedNumbers(array, 2, returnSize);
  printf("result: %d.\n", *returnSize);
  return *returnSize;
}
