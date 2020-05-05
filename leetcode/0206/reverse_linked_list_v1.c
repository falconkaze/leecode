/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    if(!head){
        return head;
    }
    struct ListNode* result = head;
    struct ListNode* nextNode = head->next;
    head->next = NULL;
    head = nextNode;
    while(head){
        head = head->next;
        nextNode->next = result;
        result = nextNode;
        nextNode = head;
    }
    return result;
}
