int findUnsortedSubarray(int* nums, int numsSize){
    int left = 0;
    int right = numsSize -1;
    while(right > left){
        if(nums[left] <= nums[left + 1]){
            left ++;
        }else {
            break;
        }
    }
    while(right > left){
        if(nums[right] >= nums[right - 1]){
            right --;
        }else {
            break;
        }
    }
    if(left == right){
        return 0;
    }
    int min = nums[left];
    int max = nums[left];
    for(int i = left + 1; i <= right; i ++){
        if(min > nums[i]){
            min = nums[i];
        }
        if(max < nums[i]){
            max = nums[i];
        }
    }
    for(int i = left - 1; i >= 0; i--){
        if(nums[i] <= min){
            continue;
        }
        left = i;
    }
    for(int i = right + 1; i < numsSize; i ++){
        if(nums[i] >= max){
            continue;
        }
        right = i;
    }
    return left == right ? 0 : right - left + 1;
}
