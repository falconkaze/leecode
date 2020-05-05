#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isMirrorTree(struct TreeNode*, struct TreeNode*);

bool isSymmetric(struct TreeNode* root){
    return root == NULL
      || !root->left && !root->right
      || root->left && root->right
      && isMirrorTree(root->left, root->right);
}

bool isMirrorTree(struct TreeNode* p, struct TreeNode* q){
    return (!p && !q)
      || p && q
      && p->val == q->val
      && isMirrorTree(p->left, q->right)
      && isMirrorTree(p->right, q->left);
}
