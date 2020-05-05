/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast){
        slow = slow->next;
        fast = fast->next;
        if(!fast){
            return false;
        }
        fast = fast->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}
