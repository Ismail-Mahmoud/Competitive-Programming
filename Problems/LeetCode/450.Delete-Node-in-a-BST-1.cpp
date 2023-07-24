// https://leetcode.com/problems/delete-node-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) {
            return nullptr;
        }
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if(key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        // 0 or 1 children
        if(!root->left) {
            return root->right;
        }
        if(!root->right) {
            return root->left;
        }

        // 2 children
        TreeNode* succ = root->left;  // max in left subtree (or min in right subtree)
        while(succ->right) {
            succ = succ->right;
        }
        root->val = succ->val;
        root->left = deleteNode(root->left, succ->val);

        return root;
    }
};