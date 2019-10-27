/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry;
    struct ListNode *result = malloc(sizeof(struct ListNode));
    struct ListNode *pos = result;
    
    int sum = l1->val + l2->val;
    pos->val = sum % 10;
    carry = sum / 10;
    
    struct ListNode *l1_pos = l1->next;
    struct ListNode *l2_pos = l2->next;
    while(l1_pos){
        if(l2_pos){
            pos->next = malloc(sizeof(struct ListNode));
            pos = pos->next;
            sum = l1_pos->val + l2_pos->val + carry;
            pos->val = sum % 10;
            carry = sum / 10;
            l1_pos = l1_pos->next;
            l2_pos = l2_pos->next;
        }else{
            do{
                pos->next = malloc(sizeof(struct ListNode));
                pos = pos->next;
                sum = l1_pos->val + carry;
                pos->val = sum % 10;
                carry = sum / 10;
                l1_pos = l1_pos->next;
            }while(l1_pos);
        }
    }
    while(l2_pos){
            pos->next = malloc(sizeof(struct ListNode));
            pos = pos->next;
            sum = l2_pos->val + carry;
            pos->val = sum % 10;
            carry = sum / 10;
            l2_pos = l2_pos->next;
    }
    if(carry){
        pos->next = malloc(sizeof(struct ListNode));
        pos = pos->next;
        pos->val = carry;
    }
    pos->next = NULL;
    return result;
}
