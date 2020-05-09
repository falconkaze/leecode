/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headB || !headA){
        return NULL;
    }
    struct ListNode* currentA = headA;
    struct ListNode* currentB = headB;
    int lengthA = 0;
    int lengthB = 0;
    while(currentA){
        currentA = currentA->next;
        lengthA ++;
    }
    while(currentB){
        currentB = currentB->next;
        lengthB ++;
    }
    int diff = lengthB - lengthA;
    if(diff > 0){
        while(diff){
            headB = headB->next;
            diff--;
        }
    }else{
        while(diff){
            headA = headA->next;
            diff++;
        }
    }
    while(headA && headB){
        if(headA == headB){
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}
