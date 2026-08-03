/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {

    // Both are NULL
    if (p == NULL && q == NULL) {
        return true;
    }

    // One is NULL and other is not
    if (p == NULL || q == NULL) {
        return false;
    }

    // Values are different
    if (p->val != q->val) {
        return false;
    }

    // Check left and right subtrees
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}