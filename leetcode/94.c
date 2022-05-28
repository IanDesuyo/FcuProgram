#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    traverse(root, returnSize, res);

    res = realloc(res, sizeof(int) * (*returnSize));
    return res;
}

void traverse(struct TreeNode* node, int* returnSize, int* res) {
    if (node != NULL) {
        traverse(node->left, returnSize, res);
        res[(*returnSize)++] = node->val;
        traverse(node->right, returnSize, res);
    }
}