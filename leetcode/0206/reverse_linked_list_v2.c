/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseListMid(struct ListNode*, struct ListNode*);

struct ListNode* reverseList(struct ListNode* head){
    return reverseListMid(NULL, head);
}

struct ListNode* reverseListMid(struct ListNode* result, struct ListNode* list){
    if(list){
        struct ListNode* tmp = list;
        list = list->next;
        tmp->next = result;
        return reverseListMid(tmp, list);
    }
    return result;
}
