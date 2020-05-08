/*
 * 遍历每个元素，判断是不是满足条件。时间复杂度是 O(n)，空间复杂度是 O(1)。
 */
int findPeakElement(int* nums, int numsSize){
    if(numsSize <= 1){
        return 0;
    }
    for(int i = 0; i < numsSize - 1; i ++){
        if(nums[i] > nums[i+1]){
            return i;
        }
    }
    return numsSize - 1;
}
