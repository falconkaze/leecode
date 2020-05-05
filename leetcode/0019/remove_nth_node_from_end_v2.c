/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* prev = head;
    struct ListNode* after = head;
    for(int i = 0; i < n; i ++){
        after = after->next;
    }
    if(after){
        after = after->next;
        while(after){
            prev = prev->next;
            after = after->next;
        }
        prev->next = prev->next->next;
        return head;
    }else{
        return head->next;
    }
}
