int findDuplicate(int* nums, int numsSize){
    int slow = 0;
    int fast = 0;
    int meeting = 0;
    // 快慢指针找相遇点.
    while(true){
        fast = nums[nums[fast]]; 
        slow = nums[slow];
        if(slow == fast){
            meeting = slow;
            break;
        }
    }
    slow = meeting;
    fast = 0;
    // 快慢指针找环的起点.
    while(true){
        if(fast  == slow){
            return slow;
        }
        slow = nums[slow];
        fast = nums[fast];
    }
    return -1;
}
