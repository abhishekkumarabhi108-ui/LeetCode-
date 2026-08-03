/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode* left, struct TreeNode* right) {

    // Both NULL
    if (left == NULL && right == NULL) {
        return true;
    }

    // Only one is NULL
    if (left == NULL || right == NULL) {
        return false;
    }

    // Values must be same
    if (left->val != right->val) {
        return false;
    }

    // Check mirror positions
    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {

    if (root == NULL) {
        return true;
    }

    return isMirror(root->left, root->right);
}