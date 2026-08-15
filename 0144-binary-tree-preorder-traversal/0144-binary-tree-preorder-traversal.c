/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preorder(struct TreeNode* root, int* result, int* index) {

    if (root == NULL)
        return;

    // Root
    result[(*index)++] = root->val;

    // Left
    preorder(root->left, result, index);

    // Right
    preorder(root->right, result, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    int* result = (int*)malloc(100 * sizeof(int));

    *returnSize = 0;

    preorder(root, result, returnSize);

    return result;
}