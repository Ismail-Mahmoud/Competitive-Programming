// https://leetcode.com/problems/even-odd-tree/

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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int k = q.size(), pre = 0;
            while(k--) {
                TreeNode* node = q.front();
                q.pop();
                int val = node->val;
                if((level & 1) == (val & 1)) {
                    return false;
                }
                if((level & 1) && pre && (val >= pre)) {
                    return false;
                }
                if(!(level & 1) && pre && (val <= pre)) {
                    return false;
                }
                pre = val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ++level;
        }
        return true;
    }
};