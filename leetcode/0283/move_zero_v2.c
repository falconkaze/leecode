void moveZeroes(int* nums, int numsSize){
    int left = 0;
    while(left < numsSize && nums[left]){
        left++;
    }
    if(left == numsSize){
        return;
    }
    int right = left + 1;
    while(right < numsSize){
        if(nums[right] != 0){
            nums[left] = nums[right];
            left ++;
        }
        right++;
    }
    while(left < numsSize){
        nums[left] = 0;
        left++;
    }
}
