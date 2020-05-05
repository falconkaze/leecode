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

void inorderTraversalMid(struct TreeNode*, struct Array*);

void addItem(struct Array*, int);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    struct Array* array = malloc(sizeof(struct Array));
    array->data = malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;

    inorderTraversalMid(root, array);
    int* resultArray = array->data;
    *returnSize = array->size;
    free(array);
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
