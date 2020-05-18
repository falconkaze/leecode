int maxSubArray(int* nums, int numsSize){
    if(numsSize == 0){
        return 0;
    }
    return maxSubArrayMid(nums, 0, numsSize - 1);
}

int maxSubArrayMid(int* nums, int left, int right){
    if(right == left){
        return nums[left];
    }
    int mid = (left + right) / 2;
    int leftMax = maxSubArrayMid(nums, left, mid);
    int rightMax = maxSubArrayMid(nums, mid + 1, right);
    int midMax = maxSubCrossArray(nums, mid, left, right);
    int result = leftMax > rightMax ? leftMax : rightMax;
    if(midMax > result){
        result = midMax;
    }
    return result;
}

int maxSubCrossArray(int* nums, int mid, int left, int right){
    int leftMax = nums[mid];
    int sum = nums[mid];
    int i = mid;
    while(i){
        sum += nums[--i];
        if(sum > leftMax){
            leftMax = sum;
        }
    }
    int rightMax = nums[mid + 1];
    sum = rightMax;
    i = mid + 1;
    while(i < right){
        sum += nums[++i];
        if(sum > rightMax){
            rightMax = sum;
        }
    }
    return leftMax + rightMax;
}
