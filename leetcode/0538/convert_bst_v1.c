/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* convertBST(struct TreeNode* root){
    int sum = 0;
    postOrder(root, &sum);
    return root;
}

void postOrder(struct TreeNode* root, int* sum){
    if(root){
        postOrder(root->right, sum);
        *sum += root->val;
        root->val = *sum;
        postOrder(root->left, sum);
    }
}
