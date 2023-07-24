// https://leetcode.com/problems/leaf-similar-trees/

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return sequence(root1) == sequence(root2);
    }
    string sequence(TreeNode* root) {
        string seq = "";
        go(root, seq);
        return seq;
    }
    void go(TreeNode* node, string& seq) {
        if(!node->left && !node->right) {
            seq += node->val;
            return;
        }
        if(node->left) {
            go(node->left, seq);
        }
        if(node->right) {
            go(node->right, seq);
        }
    }
};