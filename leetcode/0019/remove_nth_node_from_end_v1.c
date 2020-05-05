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
    struct ListNode* pre = NULL;
    while(after){
        pre = prev;
        prev = prev->next;
        after = after->next;
    }
    if(pre){
        pre->next = prev->next;
        return head;
    }else{
        return prev->next;
    }
}
