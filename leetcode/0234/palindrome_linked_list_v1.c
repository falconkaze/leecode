/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head){
    // 1. 快慢指针找到中点
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast){
        slow = slow->next;
        fast = fast->next;
        if(fast){
            fast = fast->next;
        }
    }
    // 如果链表长度 <= 1, 返回 true.
    if(!slow){
        return true;
    }
    // 2. 后半段链表翻转.
    struct ListNode* latter = slow;
    slow = slow->next;
    latter->next = NULL;
    struct ListNode* tmp;
    while(slow){
        tmp = slow;
        slow = slow->next;
        tmp->next = latter;
        latter = tmp;
    }
    // 3. 比较两段链表是否相等.
    while(latter){
        if(latter->val != head->val){
            return false;
        }
        latter = latter->next;
        head = head->next;
    }
    return true;
}
