// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0, max_level = 0, sum = 0, max_sum = INT_MIN;
        while(!q.empty()) {
            ++level;
            sum = 0;
            int s = q.size();
            while(s--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            if(sum > max_sum) {
                max_sum = sum;
                max_level = level;
            }
        }
        return max_level;
    }
};