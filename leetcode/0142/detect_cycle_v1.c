/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(!head){
        return NULL;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    do{
        if(!fast){
            return NULL;
        }
        fast = fast->next;
        if(!fast){
            return NULL;
        }
        fast = fast->next;
        slow = slow->next;
    }while(slow != fast);
    fast = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
