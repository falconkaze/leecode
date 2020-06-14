#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct StackNode {
    struct TreeNode *val;
    struct StackNode *next;
};

struct Array {
    int* data;
    int size;
    int capacity;
};

struct Array* newArray();

void addItem(struct Array* array, int value);

struct StackNode* push(struct StackNode *stack, struct TreeNode* val);

struct TreeNode* pop(struct StackNode* stack, struct StackNode** newStack);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    struct Array* array = newArray();
    struct TreeNode* node = root;
    struct StackNode* stack = NULL;
    while(node){
        addItem(array, node->val);
        if(node->right){
            stack = push(stack, node->right);
        }
        node = node->left;
    }
    while(node = pop(stack, &stack)){
        while(node){
            addItem(array, node->val);
            if(node->right){
                stack = push(stack, node->right);
            }
            node = node->left;
        }
    }
    int* result = array->data;
    *returnSize = array->size;
    return result;
}

struct StackNode* push(struct StackNode *stack, struct TreeNode* val){
    struct StackNode *newNode = malloc(sizeof(struct StackNode));
    newNode->val = val;
    newNode->next = stack;
    return newNode;
}

struct TreeNode* pop(struct StackNode* stack, struct StackNode** newStack){
    if(!stack){
        return NULL;
    }
    *newStack = stack->next;
    struct TreeNode* result = stack->val;
    free(stack);
    return result;
}

struct Array* newArray(){
    struct Array* array = malloc(sizeof(struct Array));
    array->size = 0;
    array->capacity = 10;
    array->data = malloc(sizeof(int) * 10);
    return array;
}

void addItem(struct Array* array, int value){
    if(array->size >= array->capacity){
        int* oldData = array->data;
        int oldCapacity = array->capacity;
        int newCapacity = oldCapacity * 1.5;
        int* newData = malloc(sizeof(int) * newCapacity);
        for(int i = 0; i < oldCapacity; i++){
            newData[i] = oldData[i];
        }
        free(oldData);
        array->data = newData;
        array->capacity = newCapacity;
    }
    array->data[array->size] = value;
    array->size ++;
}
