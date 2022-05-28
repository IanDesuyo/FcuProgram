#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val == key) {
        if (root->left == NULL) {
            return root->right;
        } else if (root->right == NULL) {
            return root->left;
        } else {
            struct TreeNode* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }

            root->val = temp->val;
            root->right = deleteNode(root->right, root->val);
        }

    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else {
        root->left = deleteNode(root->left, key);
    }

    return root;
}