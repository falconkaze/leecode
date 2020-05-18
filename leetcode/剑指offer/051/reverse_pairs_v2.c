int reversePairs(int* nums, int numsSize){
    int sum = 0;
    for(int i = 1; i < numsSize; i ++){
        int value = nums[i];
        int j = i;
        while(j && nums[j - 1] > value){
            nums[j] = nums[j - 1];
            sum ++;
            j --;

        }
        nums[j] = value;
    }
    return sum;
}
