/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct Array {
    int* data;
    int size;
    int capacity;
};

struct Stack {
    struct TreeNode** data;
    int top;
    int capacity;
};

void inorderTraversalMid(struct TreeNode*, struct Array*);

void addItem(struct Array*, int);

void pushItem(struct Stack* stack, struct TreeNode* node);

struct TreeNode* popItem(struct Stack* stack);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    struct Array* array = malloc(sizeof(struct Array));
    array->data = malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;

    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->data = malloc(sizeof(struct TreeNode*) * 10);
    stack->top = 0;
    stack->capacity = 10;

    inorderTraversalMid(root, array);
    int* resultArray = array->data;
    *returnSize = array->size;

    free(array);
    free(stack->data);
    free(stack);
    return resultArray;
}

void inorderTraversalMid(struct TreeNode* root, struct Array* array){
    if(root){
        inorderTraversalMid(root->left, array);
        addItem(array, root->val);
        inorderTraversalMid(root->right, array);
    }
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

void pushItem(struct Stack* stack, struct TreeNode* node){
    if(stack->pop >= stack->capacity){
        struct TreeNode** oldData = stack->data;
        int oldCapacity = stack->capacity;
        int newCapacity = oldCapacity * 1.5;
        struct TreeNode** newData = malloc(sizeof(struct TreeNode*) * newCapacity);
        for(int i = 0; i < oldCapacity; i++){
            newData[i] = oldData[i];
        }
        free(oldData);
        stack->data = newData;
        stack->capacity = newCapacity;
    }
    stack->data[stack->pop] = node;
    stack->pop ++;
}

struct TreeNode* popItem(struct Stack* stack){
    return stack->data[stack->pop--];
}
