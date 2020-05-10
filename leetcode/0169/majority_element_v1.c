int majorityElement(int* nums, int numsSize){
    int result = 0;
    int half = numsSize / 2;
    for(int i = 0; i < 32; i ++){
        int sum = 0;
        for(int j = 0; j < numsSize; j ++){
            sum += 1 & nums[j] >> i;
        }
        if(sum > half){
            result |= 1L << i;
        }
    }
    return result;
}
